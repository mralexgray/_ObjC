
#define       M(X)       NSMutable##X
#define       $(...)     [NSString stringWithFormat:__VA_ARGS__]
#define      CR(MSTR)    [MSTR appendString:@"\n"]
#define     LOC(S,LOC)   [S rangeOfString:LOC].location
#define  APPEND(X,...)   [X appendFormat:__VA_ARGS__]
#define      FM        NSFileManager.defaultManager
#define    ARGS        NSProcessInfo.processInfo.arguments
#define THEDATE        [NSDateFormatter localizedStringFromDate:NSDate.date \
                                                       dateStyle:NSDateFormatterMediumStyle \
                                                       timeStyle:NSDateFormatterMediumStyle]
@import Foundation;

@implementation  NSString (SubstringToOrFrom)

- objectAtIndexedSubscript : (NSInteger)i { return i < 0 ? [self substringFromIndex:ABS(i)]
                                                         : [self substringToIndex:i]; }
@end

@interface RxMatch : NSObject

@property (nonatomic)       NSRange   range;    // The range of the original string that was matched.
@property (nonatomic,copy)  NSArray * groups;   // Group ONLY. Each object is an RxMatchGroup.
@property (nonatomic,copy) NSString * value,    // The substring that matched the expression.
                                    * original; // Group ONLY. The full original string that was matched against.
@end


NSDictionary * ParseArgs();

NSString * _genTokens (NSDictionary *_plistData, NSString* _section) {

#define SORT(X) [[_plistData valueForKeyPath: @"SORT_EXCEPTIONS." #X ]containsObject:_section]

  id        backing = [_plistData       valueForKeyPath:_section],
           keyParts = [_section componentsSeparatedByString:@"."];
  BOOL   emitsTypes = [keyParts[0]      isEqualToString:@"TYPES"];

  id(^processDictionary)(id) = ^NSString*(NSDictionary*defs) {

    id       sortedKs = [defs.allKeys sortedArrayUsingComparator:^NSComparisonResult(NSString*x1, NSString*x2) {

      return (SORT(ALPHA) || emitsTypes) && !SORT(LENGTH) ? [x1 compare:x2 options:NSCaseInsensitiveSearch]
                                                          : [@(x1.length) compare:@(x2.length)];
    }];

    M(String)

        * snippet = $(@"#pragma mark - %@\n\n", _section.pathExtension).mutableCopy,
     * pointerMap = [keyParts[1] rangeOfString:@"POINT"].location != NSNotFound
                  ? @"".mutableCopy : nil,
       * methArgs =  emitsTypes ? @"".mutableCopy : nil;

    void(^writeTypeOrDef)(id) = ^(NSString*k){

      APPEND(snippet, @"%@ %30s %@%@ %@\n", emitsTypes ? @"_Type" : @"#define",
                              k.UTF8String, pointerMap ? @""      : @" ", defs[k],
                                            emitsTypes ? @"___"   : @"");
        if (pointerMap) {
          NSString *prefix = defs[k][  1],
       * originalClassName = k[k.length - 2],
                * shortcut = $(@"%@%@", defs[k][-1], ![prefix isEqualToString:@"_"] ? prefix.uppercaseString : @"");

          APPEND(pointerMap,@"\n#define  %26s  %@", shortcut.UTF8String, originalClassName);
        }

        !emitsTypes ?: APPEND(methArgs,@"#define %26s_  (%@)\n"
                                        "#define %21s%@_ : %@_\n", [defs[k] UTF8String], defs[k],
                                                               "_", defs[k],          defs[k]);
      };

    for (NSString *k in sortedKs) writeTypeOrDef(k);

    APPEND(snippet,@"%@%@%@", pointerMap ?: @"", methArgs ? @"\n\n" : @"", methArgs ?: @"");

    return snippet.copy;
  };

  return [backing isKindOfClass:NSDictionary.class] ? processDictionary(backing) : ({

    M(String) * concat = @"".mutableCopy; for (NSDictionary *d in backing) APPEND(concat,@"\n%@", processDictionary(d));

    concat.copy;
  });
}

RxMatch* resultToMatch(NSTextCheckingResult* result, NSString* original) {

    RxMatch* match  = RxMatch.new;
    match.original  = original;
    match.range     = result.range;
    match.value     = result.range.length ? [original substringWithRange:result.range] : nil;

    NSMutableArray* groups = @[].mutableCopy;
    for(int i=0; i<result.numberOfRanges; i++){
        RxMatch* group = RxMatch.new;
        group.range         = [result rangeAtIndex:i];
        group.value         = group.range.length ? [original substringWithRange:group.range] : nil;
        [groups addObject:group];
    }
    match.groups = groups;
    return match;
}

NSString* replace(NSRegularExpression*self, NSString *string, NSString*(^replacer)(RxMatch*)) {

    if (!replacer) return string; //no replacer? just return
    NSMutableString* replaced = string.mutableCopy; //copy the string so we can replace subsections
    NSArray* matches = [self matchesInString:string options:0 range:NSMakeRange(0, string.length)]; //get matches
    for (int i=(int)matches.count-1; i>=0; i--) { //replace each match (right to left so indexing doesn't get messed up)
        NSTextCheckingResult* result = matches[i];
        RxMatch* match = resultToMatch(result,string);
        NSString* replacement = replacer(match);
        [replaced replaceCharactersInRange:result.range withString:replacement];
    }
    return replaced;
}

id ObjectForAnyKeyPassingTest (NSDictionary *values, NSArray*okKeys, BOOL(^test)(id)) {

  __block id found = nil;
  [okKeys enumerateObjectsUsingBlock:^(id obj, NSUInteger idx, BOOL *stop) {

      if ((found = [values objectForKey:obj]))  *stop = !test || test(found); 
  }];
  return found;
}

NSString* header (NSString *plist, NSString *template) { NSDictionary *_data; id _template;

  NSCAssert( (_template = [NSString stringWithContentsOfFile:template encoding:NSUTF8StringEncoding error:nil])
              && (_data = [NSDictionary dictionaryWithContentsOfFile:plist]), @"Need data + template, mami");

  return replace([NSRegularExpression.alloc initWithPattern:@"%% (.*) %%" options:0 error:nil],

$(@"\n/*!       @note This file is AUTO_GENERATED! Changes will NOT persist!\n"
     "                Built on %@ from template:%@ with data from:%@ */\n%@",

        THEDATE, plist.lastPathComponent, template.lastPathComponent, _template),

        ^NSString *(RxMatch *match) { return _genTokens(_data,[match.groups.lastObject value]); });
}

int main() { @autoreleasepool {

  NSDictionary *opts = ParseArgs();

  BOOL(^ IsFileAndExists)(id) = ^BOOL(id p){ BOOL dir = NO, exists =[FM fileExistsAtPath:p isDirectory:&dir];

    return exists && !dir; //  ?: (BOOL)(fprintf(stderr, "%s %s exist. %s a directory.", [p UTF8String], exists ? "DOES" : "does NOT", dir ? "It is, but CANNOT be" : "Thankully, it's not"), NO);
  };

  NSString *model = ObjectForAnyKeyPassingTest(opts,@[@"d",@"data",@"model",@"plist"], IsFileAndExists),
           *templ = ObjectForAnyKeyPassingTest(opts,@[@"t",@"template",@"header"], IsFileAndExists);
        id output = ObjectForAnyKeyPassingTest(opts,@[@"o",@"output"], NULL);

  if (!model || !templ)
    return fprintf(stdout, "%s\n ERROR. Need valid input for both plist data and header template!, got %s\nmodel:%s\ntemplate:%s", [ARGS[0] UTF8String], opts.description.UTF8String, model.UTF8String, templ.UTF8String), EXIT_FAILURE;

  id x = header(model, templ);

  if (!output) return fprintf(stdout, "%s", [x UTF8String]);

  for (id place in [output isKindOfClass:NSString.class] ? @[output] : output)
    if (![x writeToFile:place atomically:YES encoding:NSUTF8StringEncoding error:nil]) return EXIT_FAILURE;

} return EXIT_SUCCESS; }



NSDictionary * ParseArgs() { id opts = @{}.mutableCopy, flag = nil;

  for (NSString *argv in [ARGS subarrayWithRange:(NSRange){1,ARGS.count-1}]) { BOOL isFlag = [argv hasPrefix:@"-"];

    id arg = !isFlag ? argv : ({ id newFlag = argv.copy; while ([newFlag hasPrefix:@"-"])
                                    newFlag = [newFlag substringFromIndex:1]; newFlag; });

    flag ? ({ isFlag && ![opts objectForKey:flag = arg] ? ({ opts[flag] = NSNull.null; }) : ({

        id existing = opts[flag]; // doesn't have - prefix ... adding or creating a value.

        opts[flag] = !existing || [existing isKindOfClass: NSNull.class] ? arg :
                                  [existing isKindOfClass:NSArray.class] ?
                                  [existing     arrayByAddingObject:arg] : @[existing, arg]; });

    }) : ({ isFlag && !opts[flag = arg] ? ({ opts[flag] = NSNull.null; })

       : ({ opts[@"?"] = [opts[@"?"] ?: @[] arrayByAddingObject:arg]; flag = nil; }); // No '-', add to unnamed array.
    });

  }  return [opts copy];
} // Parses CLI to dictionary.  Generic, chic, and unrelated to task at hand.

@implementation RxMatch @end
