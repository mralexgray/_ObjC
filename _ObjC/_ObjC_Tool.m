
#import "_ObjC_Tool.h"

MAIN(


  // Dirty, dirty arg parsing.  Supports long or short opts.

  // Bail on help
  !ParseArgs()[@"help"] && !ParseArgs()[@"h"] ?: Usage(@(EXIT_SUCCESS));

  // Require existant Plist path
  (plistPath = ObjectForAnyKeyPassingTest(ParseArgs(), @[@"d", @"p", @"data", @"model", @"plist"], IsFileAndExists))
    ? ({ generated = @{}.mutableCopy; generatedPath = [plistPath.stringByDeletingPathExtension stringByAppendingString:@".generated.plist"]; })
    : ({ failure = @"Plist PATH failurs";  Usage(@(EXIT_FAILURE)); });
  // Make sure we can create model from that plist
  PlistDataModel() ?: ({ failure = @"Plist model failurs";  Usage(@(EXIT_FAILURE)); });

  if (ParseArgs()[@"r"] || ParseArgs()[@"refactor"]) refactoree = ObjectForAnyKeyPassingTest(ParseArgs(), @[@"r", @"refactor"],IsFileAndExists);

  refactoree || (
  (templatePath = ObjectForAnyKeyPassingTest(ParseArgs(), @[@"t", @"template", @"header"],IsFileAndExists))
                && HeaderTemplate()
                && CompiledHeader()) ?: ({ failure = @"Header issue"; Usage(@(EXIT_FAILURE)); });

        output = ObjectForAnyKeyPassingTest(ParseArgs(), @[@"o", @"output"], NULL);
  testFilePath = ObjectForAnyKeyPassingTest(ParseArgs(), @[@"x", @"test", @"tests"], IsFileAndExists);

  !refactoree ?: ({ return RefactorFile(refactoree), 0; }); // printf("%s", .UTF8String); });

  // no output? no worries - just print to stdout

  Usage(@(NSNotFound));
  NSLog(@"outputs:%lu",[output count]);

  output ?: ({ return printf("%s", CompiledHeader().UTF8String), EXIT_SUCCESS; });

  for (id place in [output isKindOfClass:NSString.class] ? @[output] : output) {  // handle multiple output locations

    printf("Outputting header to destination:%s\n", [place UTF8String]);

    [CompiledHeader() writeToFile:place atomically:YES encoding:NSUTF8StringEncoding error:nil]
      ?: ({ failure = @"Cannot write header!"; Usage(@(EXIT_FAILURE)); });
  }

  !testFilePath ?: WriteTests();
)

NSString * GenerateSection(NSString * head) {

  //  if ( (LOC(head,@"MAC") != NSNotFound && BuildingFor() == e_TYPE_IOS)) return @""; // || (LOC(head,@"IOS") != NSNotFound && BuildingFor() == e_TYPE_MAC)) return @"";

  id backing = [PlistDataModel() valueForKeyPath:head], // Get dictionary section, i.e. "TYPES.POINTERS"
    keyParts = [head componentsSeparatedByString:@"."]; // Plist is unmodeled, so we have to manually figure out what we're doing.

  _Emit emit = [keyParts[0] isEqualToString:@"TYPES"] ? e_TYPE : e_DEFS; // Are we #define'ing, or typedef'ing?

  if      ([keyParts[1] containsString:@"POINT"]) emit |= e_TYPE_PMAP;   // Specifically, are we emitting pointers?
  else if ([keyParts[1] containsString:@"BLOCK"]) emit |= e_TYPE_BLKS;   // OR Get specific.

  id(^__processDictionary)(id) = ^NSString*(NSDictionary*defs) {         // This is where the work happens!

    // This is total vanity, uses some crazy sort exception list and length to do some kind of crazy sorting!

    id sortedKs = [defs.allKeys sortedArrayUsingComparator:^NSComparisonResult(NSString*x1, NSString*x2) {

      #define SORT(X) [[PlistDataModel() valueForKeyPath: @"SORT_EXCEPTIONS." #X ] containsObject:head]

      return (SORT(ALPHA) || emit&e_TYPE) && !SORT(LENGTH) ? [x1 compare:x2 options:NSCaseInsensitiveSearch]
                                                           : [@(x1.length) compare:@(x2.length)];
    }];

    /// We build our string from here (with an opening #pragma mark).

    M(String) * snippet = $(@"#pragma mark - %@\n\n", head).mutableCopy,
             * methArgs = emit  & e_TYPE      ? @"".mutableCopy : nil, /// "- (id)" -> "_ID" (if it's a typedef)
           * pointerMap = emit == e_TYPE_PMAP ? @"".mutableCopy : nil;

    #define SENTINEL(CTX) CTX == BEGINNING ? emit & e_TYPE ? "_Type" : "#define" : emit & e_TYPE ? " ___" : ""

    void(^writeTypeOrDef)(id) = ^(NSString*k){  // Write it out, girl.

      //   if ( emit & e_TYPE && [defs[k] length] != 5) // and the definition is NOT 6 letters return APPEND(problems, @" %@ (type+not5) ", k);

      SentinelLocation commentsGo = BEGINNING;  // This is just NO, or YES, not sure what I was doing.

      id theDef = defs[k], comment = nil;

      // it might be a block type, so replace its occurance of ^ with one with a space and then the def.
      NSString * theKey = [k stringByReplacingOccurrencesOfString:@"^"
                                                       withString:$(@"^ %@", defs[k])],

      // Entries that aren't strings have comments.  We need to check them and then split them, if so.
             * declared = [theDef isKindOfClass:NSString.class] ? theDef
                                                                : ({ comment = theDef[0]; theDef[1]; });

      APPEND(snippet,                                     // All appendages go onto same massive string.
             @"%@%s %*s%@   %@ %s%@\n",                   // MAIN format string
             commentsGo == ENDING || !comment             // Accomdate comments, Defaults to nothing.
             ? @"" : $(@"    ///%35s%@\n", "", comment),  // Insert at start, if set to BEGINNING and comment exists.
             SENTINEL(BEGINNING),                         // define or typedef?
             31 - (int)theKey.length, "",                 // Padding length, and the pad
             theKey,                                      // the "declaration"
             emit == e_TYPE_BLKS ? @"" : declared,        // Blocks are weird, accomodate them
             SENTINEL(ENDING),                            // defs -> no semicolon BUT typedefs -> semicolon
             commentsGo == BEGINNING || !comment          // Freaky comment handling, again.
             ? @"" : $(@" /// %@", comment));

      if (pointerMap) { NSString *prefix = defs[k][1]; BOOL lead_ = [prefix isEqualToString:@"_"];

        APPEND( pointerMap,                                     // super string.
                @"\n#define %*s%@%@   %@",                      // format string
                lead_ ? 23  : 22,                               // vain nitpicky padding
                " ",                                            // pad char
                declared[-1],                                   // letter at index -1?
                lead_ ? @"" : prefix.uppercaseString,           // shortcut
                k[k.length - 2]);                               // original class name
      }

      #define AS_ARG_SHORTCUTS(X)                            /* God, does this look insane!  */\
        BOOL isBlock = [X containsString:@"＾"];             /* Special cases for block defs */\
        APPEND( methArgs, @"#define %21s%s%@%s   ( %@ )\n"   /* In parenthsis                */\
                           "#define %21s%@_   : ( %@ )\n",   /* Includes leading ':'         */\
                           " ", \
                           isBlock ? "_" : "", \
                           X,  \
                           isBlock ? "" : "_", \
                           X,                                     \
                           isBlock ? ""  : "_",X, X)

      #define METHOD_RETURN_SHORTCUT(X)                       /* - _Text_ -> _TT             */\
        APPEND( methArgs,                                     /* superstring                 */\
                @"#define %21s%@%@      - %@_\n",             /* format string               */\
                " ",                                          /* padding char                */\
                X[2],                                         /* superstring                 */\
                [X[-([X length]-1)] uppercaseString],         /* capitalized last LETTER     */\
                X)                                            /* superstring                 */

//      #define METHOD_RETURN_SHORTCUT(X)                       /* - _Text_ -> _TT             */\
//        APPEND( methArgs,                                     /* superstring                 */\
//                @"#define %21s%@%@      - %@_\n",             /* format string               */\
//                " ",                                          /* padding char                */\
//                X[2],                                         /* superstring                 */\
//                [X[-([X length]-1)] uppercaseString],         /* capitalized last LETTER     */\
//                X)                                            /* superstring                 */


      !emit & e_TYPE ?: ({ AS_ARG_SHORTCUTS(declared); }); // if NOT a type, generate method argument variations

      ![PlistDataModel()[@"ALIAS_INSTANCE_RETURN"] containsObject:declared] ?: METHOD_RETURN_SHORTCUT(declared);
    };

    for (NSString *k in sortedKs) writeTypeOrDef(k);

    APPEND(snippet,@"%@%@%@\n\n#pragma mark - END %@", pointerMap ?: @"",
                                                         methArgs ?  @"\n\n"
                                                                   : @"",
                                                         methArgs ?: @"", head);

    return snippet.copy;
  };

  return [backing isKindOfClass:NSDictionary.class] ? __processDictionary(backing) :

  [({ M(Array) *parts; for (id d in backing) [parts addObject:__processDictionary(d)]; parts; }) componentsJoinedByString:@"\n"];

} // Meat + Potatoes

static NSString * CompiledHeader () {

  return compiled = compiled ?: ({

    // Search for our placeholders, ormatted like %% DEFINES.STANDARD_NAMES %%
    RGX *regex = [RGX.alloc initWithPattern:@"%% (.*) %%" options:0 error:nil];

    NSString* string = //copy the string so we can replace subsections

    $(_TEMPLATE, THEDATE, plistPath.lastPathComponent,
                          templatePath.lastPathComponent, HeaderTemplate());

    M(String) *replaced = string.mutableCopy;

    id matches = [regex matchesInString:string options:0 range:NSMakeRange(0, string.length)];

    NSLog(@"found %lu matches", [matches count]);

    [matches enumerateObjectsWithOptions:NSEnumerationReverse
                              usingBlock:^(NSTextCheckingResult* result, NSUInteger idx, BOOL *s) {

      NSLog(@"replacing %@", [string substringWithRange:result.range]);

      id section = GenerateSection( [[RxMatch.alloc initWithTextCheckingResult:result forString:string].groups.lastObject value]);

      [replaced replaceCharactersInRange:result.range withString:section]; ///* replacement */ replacer(/*RxMatch* match */];

    }];

    replaced.copy;
  });
}

void WriteTests () {

  #define delimeter @"// AUTOGENERATED TEST PLACEHOLDER"

  id contents = [NSString stringWithContentsOfFile:testFilePath encoding:NSUTF8StringEncoding error:nil];

  M(String) *tests = [contents substringToIndex:[contents rangeOfString:delimeter].location + delimeter.length].mutableCopy;

  APPEND(tests,@" (Generated at %@)\n\n_XCTCase(DefinesTestCase)\n_XCTest(TheyWorked,\n", THEDATE);

  for (id keypath in @[@"TYPES.STRUCTS",@"TYPES.POINTERS",@"TYPES.POINTERS_MAC"]) {

    APPEND(tests,@"\n");

    [[PlistDataModel() valueForKeyPath:keypath] enumerateKeysAndObjectsUsingBlock:^(id key, id obj, BOOL *stop) {

      APPEND(tests,@"\tXCTAssert(@encode(%@) == @encode(%@), @\"%%s should equal %%s!\",@encode(%@),@encode(%@));\n", key, obj, key, obj);

    }];
    APPEND(tests,@"\n");
  }

  APPEND(tests,@"\n)\n@end\n");  // Finish Tests

  [FM removeItemAtPath:testFilePath error:nil];
  [tests writeToFile:testFilePath atomically:YES encoding:NSUTF8StringEncoding error:nil];
}

// Parses CLI to dictionary.  Generic, chic, and unrelated to task at hand.

NSDictionary * ParseArgs() {

  static id opts; static dispatch_once_t onceToken; dispatch_once(&onceToken, ^{

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
}

