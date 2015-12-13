
/// @warning Everything here is private. Nothing to see here, move along. (Ugly mish-mosh of shit - attempts to simpliy tool code.)

#ifndef _ObjC__ObjC_Tool_pch
#define _ObjC__ObjC_Tool_pch

#import <Foundation/Foundation.h>

#define TEMPLATE_ALIASES  @"t", @"template", @"header"
#define OUTPUT_ALIASES    @"o", @"output"
#define TESTS_ALIASES     @"x", @"test", @"tests"
#define PLIST_ALIASES     @"d", @"p", @"data", @"model", @"plist"

#define       M(X)        NSMutable##X
#define       $(...)      [NSString stringWithFormat:__VA_ARGS__]
#define      CR(MSTR)     [MSTR appendString:@"\n"]
#define     LOC(S,LOC)    [S rangeOfString:LOC].location
#define    MAIN(...)      int main() { @autoreleasepool {  __VA_ARGS__  } return EXIT_SUCCESS; }
#define  APPEND(X,...)    [X appendFormat:__VA_ARGS__]
#define      FM           NSFileManager.defaultManager
#define    ARGS           NSProcessInfo.processInfo.arguments
#define     ENV           NSProcessInfo.processInfo.environment
#define MEDDATE           NSDateFormatterMediumStyle
#define RGX               NSRegularExpression
#define THEDATE           [NSDateFormatter localizedStringFromDate:NSDate.date dateStyle:MEDDATE timeStyle:MEDDATE]
#define _TEMPLATE          @"\n/*!\t\t@note\tThis file is AUTO_GENERATED! Changes will NOT persist!\n" \
                          "\t\t\t\t\t\tAUTO_GENERATED on %@ from template:%@ with data from:%@\n%@"

/// @abstract The data we are deling with is broadly defined as either #define's or _Type typedefs.

typedef NS_OPTIONS(int, _Emit) { e_DEFS      = 0x00000000,            // All #define's are 0.
                                 e_TYPE      = 0x00000001,            // All typedefs will include the <<1 bit
                                 e_TYPE_BLKS = 0x00000010 | e_TYPE,   // aka 0x00000011
                                 e_TYPE_PMAP = 0x00000100 | e_TYPE,   // aka 0x00000101
                                 e_TYPE_MAC  = 0x10000000,
                                 e_TYPE_IOS  = 0x01000000};

typedef NS_ENUM(BOOL, SentinelLocation) { ENDING = NO, BEGINNING = YES };

#pragma mark - Declarations

OBJC_EXPORT NSString     * RefactorFile (id);  // UNIMPLEMENTED
OBJC_EXPORT NSString     * HeaderTemplate ();
OBJC_EXPORT NSDictionary * PlistDataModel ();

static NSString     * CompiledHeader ();
       void               WriteTests ();

static NSString *failure, *refactoree;
static id output, generated;

// Parses CLI to dictionary.  Generic, chic, and unrelated to task at hand.

NS_INLINE NSDictionary * ParseArgs() {

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

NS_INLINE id ObjectForAnyKeyPassingTest(NSDictionary * values, NSArray * okKeys, BOOL(*test)(id)) {

  for (id key in okKeys) { id found = values[key]; if (found && (!test || test(found))) return found; } return failure = [okKeys.lastObject copy], nil;
}

NS_INLINE BOOL IsFileAndExists(id p) { BOOL d = NO; return [FM fileExistsAtPath:[p stringByStandardizingPath] isDirectory:&d] && !d; }


#define USAGE_PARAMS @" \n\
  -r	--refactor  Source file to refactor (outputs to stdout)   \n\
OR                                                              \n\
  -p  --plist     Plist to parse                                \n\
  -t  --template  Header template!.                             \n\
  -0  --output    Path (or paths) to write compiled header to.  \n\
OR                                                              \n\
  -l  --list      SHow parsed options."

NS_INLINE NSString *    PlistPath () { return ObjectForAnyKeyPassingTest(ParseArgs(), @[PLIST_ALIASES],   IsFileAndExists); }
NS_INLINE NSString * TemplatePath () { return ObjectForAnyKeyPassingTest(ParseArgs(), @[TEMPLATE_ALIASES],IsFileAndExists); }
NS_INLINE NSString * TestFilePath () { return ObjectForAnyKeyPassingTest(ParseArgs(), @[TESTS_ALIASES], IsFileAndExists); }

NS_INLINE void Usage(NSUInteger codeOrNotFound) {

  _Emit _env = LOC(ENV[@"BUILT_PRODUCTS_DIR"],@"iphone") != NSNotFound ? e_TYPE_IOS : e_TYPE_MAC; // was `static _Emit BuildingFor ();`

  printf("PROBLEM:%s\n%s%s\ngot %s\nmodel:%s\ntemplate:%s\nplatform:%x\nrefactor:%s",

      failure.UTF8String, [ARGS[0] UTF8String], USAGE_PARAMS.UTF8String,
      ParseArgs().description.UTF8String,
      PlistPath().UTF8String,
      TemplatePath().UTF8String, _env,
      refactoree.UTF8String);

  codeOrNotFound == NSNotFound ?: exit(codeOrNotFound);
}



@interface                  RxMatch : NSObject
- initWithTextCheckingResult:(NSTextCheckingResult*)tx forString:(NSString*)s;
@property             NSRange   range;    // The range of the original string that was matched.
@property             NSArray * groups;   // Group ONLY. Each object is an RxMatchGroup.
@property (copy)     NSString * value,    // The substring that matched the expression.
                              * original; // Group ONLY. The full original string that was matched against.
@end

@interface                 NSString   (SubstringToOrFrom)
- objectAtIndexedSubscript:(NSInteger)i;
#ifndef MAC_OS_X_VERSION_10_10
- (BOOL) containsString:(NSString*)x;
#endif
@end

#endif
