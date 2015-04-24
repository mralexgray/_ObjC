
MAIN(

     plistPath = ObjectForAnyKeyPassingTest(ParseArgs(), @[@"d",@"p",@"data",@"model",@"plist"], IsFileAndExists);
  templatePath = ObjectForAnyKeyPassingTest(ParseArgs(), @[@"t",@"template",@"header"],          IsFileAndExists);
        output = ObjectForAnyKeyPassingTest(ParseArgs(), @[@"o",@"output"],                      NULL);
  testFilePath = ObjectForAnyKeyPassingTest(ParseArgs(), @[@"tests",@"test",@"x"],               IsFileAndExists);

  if (ParseArgs()[@"help"] || !plistPath || !templatePath || !PlistDataModel() || !HeaderTemplate() || !CompiledHeader())

    return fprintf(stdout, "%s\n --plist, -p\tplist to parse\n --template, -t\theader template!.\n--output, -o \tpath or paths to write compiled header to.\ngot %s\nmodel:%s\ntemplate:%s\nplatform:%x", [ARGS[0] UTF8String], [ParseArgs() description].UTF8String, [plistPath UTF8String], [templatePath UTF8String], BuildingFor()), EXIT_FAILURE;
     
  if (!output) return fprintf(stdout, "%s", [CompiledHeader() UTF8String]); // no output, no worries, print to stdout!

  for (id place in [output isKindOfClass:NSString.class] ? @[output] : output) {

    fprintf(stdout, "Outputting header to destination:%s\n", [place UTF8String]);

    if (![CompiledHeader() writeToFile:place atomically:YES encoding:NSUTF8StringEncoding error:nil]) return EXIT_FAILURE;
  }
  if (testFilePath) WriteTests();
)
static _Emit             BuildingFor () { static _Emit _env; return _env = _env ?:

  LOC(ENV[@"BUILT_PRODUCTS_DIR"],@"iphone") != NSNotFound ? e_TYPE_IOS : e_TYPE_MAC;
}

static NSDictionary * PlistDataModel () { return plist    = plist    ?: [NSDictionary dictionaryWithContentsOfFile:plistPath]; }
static     NSString * HeaderTemplate () { return template = template ?: [NSString stringWithContentsOfFile:templatePath encoding:NSUTF8StringEncoding error:nil]; }

NSString * GenerateSection(NSString * head)     {

//  if ( (LOC(head,@"MAC") != NSNotFound && BuildingFor() == e_TYPE_IOS)) return @""; // ||
//       (LOC(head,@"IOS") != NSNotFound && BuildingFor() == e_TYPE_MAC)) return @"";

  id backing = [PlistDataModel() valueForKeyPath:head],
    keyParts = [head componentsSeparatedByString:@"."];

  _Emit emit = [keyParts[0] isEqualToString:@"TYPES"] ? e_TYPE : e_DEFS;

  if      ([keyParts[1] containsString:@"POINT"]) emit |= e_TYPE_PMAP;
  else if ([keyParts[1] containsString:@"BLOCK"]) emit |= e_TYPE_BLKS;

  id(^__processDictionary)(id) = ^NSString*(NSDictionary*defs) {

    id sortedKs = [defs.allKeys sortedArrayUsingComparator:^NSComparisonResult(NSString*x1, NSString*x2) {

      #define SORT(X) [[PlistDataModel() valueForKeyPath: @"SORT_EXCEPTIONS." #X ]containsObject:head]

      return (SORT(ALPHA) || emit&e_TYPE) && !SORT(LENGTH) ? [x1 compare:x2 options:NSCaseInsensitiveSearch]
                                                           : [@(x1.length) compare:@(x2.length)];
    }];

    M(String) * snippet = $(@"#pragma mark - %@\n\n", head.pathExtension).mutableCopy,
             * methArgs = emit  & e_TYPE      ? @"".mutableCopy : nil,
           * pointerMap = emit == e_TYPE_PMAP ? @"".mutableCopy : nil,
             * problems = @"".mutableCopy;

      #define SENTINEL(Context) Context == NSFormattingContextBeginningOfSentence ? \
                                        emit & e_TYPE ? "_Type"   : "#define"  :    \
                                        emit & e_TYPE ? " ___"    : ""

    void(^writeTypeOrDef)(id) = ^(NSString*k){  // Write it out, girl.

      //   if (      emit & e_TYPE && [defs[k] length] != 5) // and the definition is NOT 6 letters return APPEND(problems, @" %@ (type+not5) ", k);

      // it might be a block type, so replace its occurance of ^ with one with a space and then the def.
      NSString * theKey = [k stringByReplacingOccurrencesOfString:@"^"  withString:$(@"^ %@", defs[k])];

      APPEND(snippet, @"%s %*s%@   %@ %s\n", SENTINEL(NSFormattingContextBeginningOfSentence),
                                             31 - (int)theKey.length,
                                             "",
                                             theKey,
                                             emit == e_TYPE_BLKS ? @"" : defs[k],
                                             SENTINEL(0));

      if (pointerMap) { NSString *prefix = defs[k][1]; BOOL lead_ = [prefix isEqualToString:@"_"];

        APPEND(pointerMap,@"\n#define %*s%@%@   %@", lead_ ? 23  : 22, " ", defs[k][-1],
                                                     lead_ ? @"" : prefix.uppercaseString, // shortcut
                                                     k[k.length - 2]);  // original class name
      }

      #define AS_ARG_SHORTCUTS(X) ({ \
        BOOL isBlock = [X containsString:@"＾"];          /* Special cases for block defs */ \
        APPEND( methArgs, @"#define %21s%s%@%s   ( %@ )\n"   /* In parenthsis                */ \
                           "#define %21s%@_   : ( %@ )\n", /* Includes leading ':'         */ \
                " ", isBlock ? "_" : "", X, isBlock ? "" : "_", X,                                                                   \
                isBlock ? "" : "_",X, X); })

      #define METHOD_RETURN_SHORTCUT(X) APPEND(methArgs, @"#define %21s%@%@      - %@_\n",\
                                              " ",X[2],[X[-([X length]-1)] uppercaseString],    X)

      !emit & e_TYPE ?: AS_ARG_SHORTCUTS(defs[k]); // if NOT a type, generate method argument variations
      
      ![PlistDataModel()[@"ALIAS_INSTANCE_RETURN"] containsObject:defs[k]] ?: METHOD_RETURN_SHORTCUT(defs[k]);
    };

    for (NSString *k in sortedKs) writeTypeOrDef(k);

    APPEND(snippet,@"%@%@%@\n\n#pragma mark - END %@ PROBLEMS: %@", pointerMap ?: @"", methArgs ? @"\n\n" : @"", methArgs ?: @"", head, problems);

    return snippet.copy;
  };

  return [backing isKindOfClass:NSDictionary.class] ? __processDictionary(backing) :

  [({ M(Array) *parts; for (id d in backing) [parts addObject:__processDictionary(d)]; parts; }) componentsJoinedByString:@"\n"];

//    M(String) * concat = @"".mutableCopy;
//    for (id d in backing) APPEND(concat,@"\n%@", __processDictionary(d)); concat.copy; });
}


id ObjectForAnyKeyPassingTest(  NSDictionary * values,     NSArray * okKeys, BOOL(*test)(id)) {

  __block id found = nil;

  [okKeys enumerateObjectsUsingBlock:^(id obj, NSUInteger idx, BOOL *stop) {

    if ((found = [values objectForKey:obj]))  *stop = !test || test(found);
  }];
  return found;
}

static NSString * CompiledHeader() { return compiled = compiled ?: ({

    NSRegularExpression *regex = [NSRegularExpression.alloc initWithPattern:@"%% (.*) %%" options:0 error:nil];

    NSString* string = //copy the string so we can replace subsections

      $(@"\n/*!       @note This file is AUTO_GENERATED! Changes will NOT persist!\n"
         "                Built on %@ from template:%@ with data from:%@ */\n%@",
       THEDATE, [plistPath lastPathComponent], [templatePath lastPathComponent],HeaderTemplate());

    NSMutableString *replaced = string.mutableCopy;

    id matches = [regex matchesInString:string options:0 range:NSMakeRange(0, string.length)];

    NSLog(@"found %@ matches", @([matches count]));

    [matches enumerateObjectsWithOptions:NSEnumerationReverse
                       usingBlock:^(NSTextCheckingResult* result, NSUInteger idx, BOOL *stop) {

      NSLog(@"replacing %@", [string substringWithRange:result.range]);
      [replaced replaceCharactersInRange:result.range
                withString: GenerateSection(
          [[[[RxMatch.alloc initWithTextCheckingResult:result forString:string] groups] lastObject] value])];

              ///* replacement */ replacer(/*RxMatch* match */];
    }];
    [replaced copy];
  });
}

void WriteTests () {

  id delimiter = @"/// AUTO-GENERATED TESTS BELOW",
      contents = [NSString stringWithContentsOfFile:testFilePath encoding:NSUTF8StringEncoding error:nil];

  M(String) *tests = [contents substringToIndex:[contents rangeOfString:delimiter].location + [delimiter length]].mutableCopy;

  APPEND(tests,@"(Generated at %@)\n\n_XCTCase(DefinesTestCase)\n_XCTest(TheyWorked,\n", THEDATE);

  for (id keypath in @[@"TYPES.STRUCTS",@"TYPES.POINTERS",@"TYPES.POINTERS_MAC"]) {
    APPEND(tests,@"\n");
    [[PlistDataModel() valueForKeyPath:keypath] enumerateKeysAndObjectsUsingBlock:^(id key, id obj, BOOL *stop) {
      APPEND(tests,@"\tXCTAssert(@encode(%@) == @encode(%@), @\"%%s should equal %%s!\",@encode(%@),@encode(%@));\n", key, obj, key, obj);
    }];
    APPEND(tests,@"\n");
  }
  APPEND(tests,@"\n)\n@end\n");
  [FM removeItemAtPath:testFilePath error:nil];
  [tests writeToFile:testFilePath atomically:YES encoding:NSUTF8StringEncoding error:nil];
}

@implementation  NSString (SubstringToOrFrom)

- (NSString*) refactor { NSDictionary *rules = @{}; return @""; }

- objectAtIndexedSubscript:(NSInteger)i { return i < 0 ? [self substringFromIndex:ABS(i)] : [self substringToIndex:i]; }
#ifndef MAC_OS_X_VERSION_10_10
- (BOOL) containsString:(NSString*)x { return [self rangeOfString:x].location != NSNotFound; }
#endif

@end

@implementation RxMatch
- initWithTextCheckingResult:(NSTextCheckingResult*)result forString:(NSString*)original {

  self = super.init;
  _original  = original;
  _range     = result.range;
  _value     = result.range.length ? [original substringWithRange:result.range] : nil;

  NSMutableArray* groups = @[].mutableCopy;
  for(int i=0; i<result.numberOfRanges; i++){
    RxMatch* group = RxMatch.new;
    group.range         = [result rangeAtIndex:i];
    group.value         = group.range.length ? [original substringWithRange:group.range] : nil;
    [groups addObject:group];
  }
  _groups = [groups copy];
  return self;
}
@end

static NSDictionary * ParseArgs() { static id opts; static dispatch_once_t onceToken; dispatch_once(&onceToken, ^{

   id _opts = @{}.mutableCopy, flag = nil;

    for (NSString *argv in [ARGS subarrayWithRange:(NSRange){1,ARGS.count-1}]) { BOOL isFlag = [argv hasPrefix:@"-"];

      id arg = !isFlag ? argv : ({ id newFlag = argv.copy; while ([newFlag hasPrefix:@"-"])
        newFlag = [newFlag substringFromIndex:1]; newFlag; });

      flag ? ({ isFlag && ![_opts objectForKey:flag = arg] ? ({ _opts[flag] = NSNull.null; }) : ({

        id existing = _opts[flag]; // doesn't have - prefix ... adding or creating a value.

        _opts[flag] = !existing || [existing isKindOfClass: NSNull.class] ? arg :
        [existing isKindOfClass:NSArray.class] ?
        [existing     arrayByAddingObject:arg] : @[existing, arg]; });

      }) : ({ isFlag && !_opts[flag = arg] ? ({ _opts[flag] = NSNull.null; })

        : ({ _opts[@"?"] = [_opts[@"?"] ?: @[] arrayByAddingObject:arg]; flag = nil; }); // No '-', add to unnamed array.
      });

    }  opts = [_opts copy];
  });

  return opts;

} // Parses CLI to dictionary.  Generic, chic, and unrelated to task at hand.

