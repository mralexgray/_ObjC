
/// @warning Everything here is private. Nothing to see here, move along. (Ugly mish-mosh of shit - attempts to simpliy tool code.)

#ifndef _ObjC__ObjC_Tool_pch
#define _ObjC__ObjC_Tool_pch

#import <Foundation/Foundation.h>

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
#define THEDATE           [NSDateFormatter localizedStringFromDate:NSDate.date dateStyle:MEDDATE timeStyle:MEDDATE]
#define _TEMPLATE          @"\n/*!\n\t@note This file is AUTO_GENERATED! Changes will NOT persist!\n" \
                          "AUTO_GENERATED on %@ from template:%@ with data from:%@ */\n%@"

/// @abstract The data we are deling with is broadly defined as either #define's or _Type typedefs.

typedef NS_OPTIONS(int, _Emit) { e_DEFS      = 0x00000000,            // All #define's are 0.
                                 e_TYPE      = 0x00000001,            // All typedefs will include the <<1 bit
                                 e_TYPE_BLKS = 0x00000010 | e_TYPE,   // aka 0x00000011
                                 e_TYPE_PMAP = 0x00000100 | e_TYPE,   // aka 0x00000101
                                 e_TYPE_MAC  = 0x10000000,
                                 e_TYPE_IOS  = 0x01000000};

typedef NS_ENUM(BOOL, SentinelLocation) { ENDING = NO, BEGINNING = YES };

#pragma mark - Declarations

static NSString     * RefactorFile (id);  // UNIMPLEMENTED
static NSString     * CompiledHeader ();
static NSDictionary * PlistDataModel ();
       NSDictionary *      ParseArgs ();
       void               WriteTests ();

       
static NSString * template, * templatePath, * plistPath, * testFilePath, * refactoree;
static id plist, output, compiled;

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

NS_INLINE id ObjectForAnyKeyPassingTest(NSDictionary * values, NSArray * okKeys, BOOL(*test)(id)) {

  for (id key in okKeys) { id found = values[key]; if (found && (!test || test(found))) return found; } return nil;
}

NS_INLINE BOOL IsFileAndExists(id p) { BOOL dir = NO; return [FM fileExistsAtPath:p isDirectory:&dir] && !dir; }

NS_INLINE NSString * HeaderTemplate() {

  static NSString * t; return t = t ?: [NSString stringWithContentsOfFile:templatePath encoding:NSUTF8StringEncoding error:nil];
}

#define USAGE_PARAMS @" \
  -r	--refactor  Source file to refactor (outputs to stdout)   \
OR                                                              \
  -p  --plist     Plist to parse                                \
  -t  --template  Header template!.                             \
  -0  --output    Path (or paths) to write compiled header to.  \
OR                                                              \
  -l  --list      SHow parsed options."

NS_INLINE void Usage() {

  _Emit _env = LOC(ENV[@"BUILT_PRODUCTS_DIR"],@"iphone") != NSNotFound ? e_TYPE_IOS : e_TYPE_MAC; // was `static _Emit BuildingFor ();`

    fprintf(stdout, "%s%s\ngot %s\nmodel:%s\ntemplate:%s\nplatform:%x",

      [ARGS[0] UTF8String], USAGE_PARAMS.UTF8String, ParseArgs().description.UTF8String, plistPath.UTF8String, templatePath.UTF8String, _env);
}

#endif