
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

#import <Foundation/Foundation.h>

NSString* AZEnumToBinary(int num) {  char str[9] = {0};

  return $(@"%s", ({ int i; for(i=7;i>=0;i--){ str[i] = (num&1)?'1':'0'; num >>= 1; } str; }));
}

@interface RxMatch : NSObject

@property (nonatomic)       NSRange   range;    // The range of the original string that was matched.
@property (nonatomic,copy)  NSArray * groups;   // Group ONLY. Each object is an RxMatchGroup.
@property (nonatomic,copy) NSString * value,    // The substring that matched the expression.
                                    * original; // Group ONLY. The full original string that was matched against.
@end
@implementation  NSString (SubstringToOrFrom)

- (NSString*) refactor { NSDictionary *rules = @{}; return @""; }

- objectAtIndexedSubscript:(NSInteger)i { return i < 0 ? [self substringFromIndex:ABS(i)] : [self substringToIndex:i]; }

@end

NSString * Header(); NSDictionary * Plist(); NSString * Template (); static id templatePath, plistPath; NSDictionary * ParseArgs (); id replace(NSRegularExpression*,NSString*,NSString*(^)(RxMatch*)); id ObjectForAnyKeyPassingTest(NSDictionary*,NSArray*,BOOL(^)(id)); id _genTokens (id,id);

int main() { @autoreleasepool {

  BOOL(^ IsFileAndExists)(id) = ^BOOL(id p){ BOOL dir = NO;  return [FM fileExistsAtPath:p isDirectory:&dir] && !dir; };

  id      opts = ParseArgs();
     plistPath = ObjectForAnyKeyPassingTest(opts, @[@"d",@"p",@"data",@"model",@"plist"], IsFileAndExists);
  templatePath = ObjectForAnyKeyPassingTest(opts, @[@"t",@"template",@"header"],     IsFileAndExists);
  id    output = ObjectForAnyKeyPassingTest(opts, @[@"o",@"output"],                 NULL);

  if (!plistPath || !templatePath || !Plist() || !Template() || !Header())

    return fprintf(stdout, "%s\n ERROR. Need valid input for both plist data and header template!, got %s\nmodel:%s\ntemplate:%s", [ARGS[0] UTF8String], [opts description].UTF8String, [plistPath UTF8String], [templatePath UTF8String]), EXIT_FAILURE;

  if (!output) return fprintf(stdout, "%s", [Header() UTF8String]);

  for (id place in [output isKindOfClass:NSString.class] ? @[output] : output)

    if (![Header() writeToFile:place atomically:YES encoding:NSUTF8StringEncoding error:nil]) return EXIT_FAILURE;

} return EXIT_SUCCESS; }

NSDictionary * Plist    () { static id data;  return data  = data ?:  [NSDictionary dictionaryWithContentsOfFile:plistPath]; }
    NSString * Template () { static id templ; return templ = templ ?: [NSString stringWithContentsOfFile:templatePath encoding:NSUTF8StringEncoding error:nil]; }

typedef NS_OPTIONS(int, _Emit) { e_DEFS, e_TYPE      = 0x00000001,
                                         e_TYPE_BLKS = 0x00000010 | e_TYPE,
                                         e_TYPE_PMAP = 0x00000100 | e_TYPE};

NSString * _genTokens(NSDictionary *plistData, NSString*head) {

#define SORT(X) [[plistData valueForKeyPath: @"SORT_EXCEPTIONS." #X ]containsObject:head]

  id backing = [plistData        valueForKeyPath:head],
    keyParts = [head componentsSeparatedByString:@"."];
  _Emit emit = [keyParts[0]  isEqualToString:@"TYPES"] ? e_TYPE : 0;
        emit = [keyParts[1]   containsString:@"POINT"] ? emit | e_TYPE_PMAP
             : [keyParts[1]   containsString:@"BLOCK"] ? emit | e_TYPE_BLKS : emit;

  id(^__processDictionary)(id) = ^NSString*(NSDictionary*defs) {

    id       sortedKs = [defs.allKeys sortedArrayUsingComparator:^NSComparisonResult(NSString*x1, NSString*x2) {

      return (SORT(ALPHA) || emit&e_TYPE) && !SORT(LENGTH) ? [x1 compare:x2 options:NSCaseInsensitiveSearch]
                                                           : [@(x1.length) compare:@(x2.length)];
    }];

    M(String) * snippet = $(@"#pragma mark - %@\n\n", head.pathExtension).mutableCopy,
             * methArgs = emit  & e_TYPE      ? @"".mutableCopy : nil,
           * pointerMap = emit == e_TYPE_PMAP ? @"".mutableCopy : nil,
             * problems = @"".mutableCopy;

#define SENTINEL(BEGIN,e_emitter) BEGIN && e_emitter & e_TYPE ? "_Type" : BEGIN ? "#define" :  e_emitter & e_TYPE ? " ___" : ""

    void(^writeTypeOrDef)(id) = ^(NSString*k){  // Write it out, girl.

//      if (      emit & e_TYPE && [defs[k] length] != 5) // and the definition is NOT 6 letters
//        return APPEND(problems, @" %@ (type+not5) ", k);

      // it might be a block type, so replace its occurance of ^ with one with a space and then the def.
      NSString * theKey = [k stringByReplacingOccurrencesOfString:@"^"  withString:$(@"^ %@", defs[k])];

      APPEND(snippet, @"%s %*s%@   %@ %s\n", SENTINEL(YES,emit),
                                    31 - (int)theKey.length, "", theKey,
                        emit == e_TYPE_BLKS ? @"" : defs[k],
                                         SENTINEL(NO,emit));

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
      
      ![Plist()[@"ALIAS_INSTANCE_RETURN"] containsObject:defs[k]] ?: METHOD_RETURN_SHORTCUT(defs[k]);
    };

    for (NSString *k in sortedKs) writeTypeOrDef(k);

    APPEND(snippet,@"%@%@%@\n\n#pragma mark - END %@ PROBLEMS: %@", pointerMap ?: @"", methArgs ? @"\n\n" : @"", methArgs ?: @"", head, problems);

    return snippet.copy;
  };

  return [backing isKindOfClass:NSDictionary.class] ? __processDictionary(backing) : ({

    M(String) * concat = @"".mutableCopy;

    for (id d in backing) APPEND(concat,@"\n%@", __processDictionary(d)); concat.copy; });
}

RxMatch * result2Match(NSTextCheckingResult* result, NSString* original) {

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

id replace(NSRegularExpression*self, NSString *string, NSString*(^replacer)(RxMatch*)) {

  if (!replacer) return string;                   // no replacer? just return

  NSMutableString* replaced = string.mutableCopy; //copy the string so we can replace subsections
  NSArray* matches = [self matchesInString:string options:0 range:NSMakeRange(0, string.length)]; //get matches
  for (int i=(int)matches.count-1; i>=0; i--) { //replace each match (right to left so indexing doesn't get messed up)

    NSTextCheckingResult* result = matches[i];

    [replaced replaceCharactersInRange:result.range
                            withString:
    /* replacement */ replacer(/*RxMatch* match */result2Match(result,string))];
  }
  return replaced;
}

id ObjectForAnyKeyPassingTest(NSDictionary *values, NSArray*okKeys, BOOL(^test)(id)) {

  __block id found = nil;
  [okKeys enumerateObjectsUsingBlock:^(id obj, NSUInteger idx, BOOL *stop) {

    if ((found = [values objectForKey:obj]))  *stop = !test || test(found);
  }];
  return found;
}


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


NSString * Header() { static id h; return h = h ?:

  replace([NSRegularExpression.alloc initWithPattern:@"%% (.*) %%" options:0 error:nil],

   $(@"\n/*!       @note This file is AUTO_GENERATED! Changes will NOT persist!\n"
     "                Built on %@ from template:%@ with data from:%@ */\n%@",

     THEDATE, [plistPath lastPathComponent], [templatePath lastPathComponent],Template()),

      ^NSString *(RxMatch *match) {

          return _genTokens(Plist(),[match.groups.lastObject value]); });
}

