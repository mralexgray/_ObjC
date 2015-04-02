
#define      args NSProcessInfo.processInfo.arguments
#define XcodePath _system(@"printf \"${$(xcode-select -p)%.app/*}.app\"")
#define      M(X) NSMutable##X
#define LOC(S,LOC) [S rangeOfString:LOC].location
#define $(...) [NSString stringWithFormat:__VA_ARGS__]
#define $APPEND(X,...) [X appendFormat:__VA_ARGS__]
#define CR(MSTR) [MSTR appendString:@"\n"]

#import "RegExCategories.h"

id _uSort(id); id _sTask(id); static M(Dictionary)* primitives, *pointers, *parenthized, *qualifiers;

@implementation NSString  (Subscript) - objectAtIndexedSubscript:(NSInteger)i { return i < 0 ? [self substringFromIndex:ABS(i)] : [self substringToIndex:i]; } @end

@implementation M(String) (Plist2Header)

- (void) _if:key do:(void (^)())stuff {

    NSString* exclusive = LOC(key,@"_") == NSNotFound ? nil : key[ - (LOC(key,@"_") + 1) ];

    exclusive ? $APPEND(self, @"\n#if %@ // $@\n\n", exclusive) : CR(self); stuff();
    exclusive ? $APPEND(self, @"\n#endif // %@\n",   exclusive) : CR(self);
}

- (void) _addDefine:dstr {

    NSUInteger space = LOC(dstr,@" "); // defines are split at first "space".

    $APPEND(self,@"#define %30s %@\n", [dstr[space] UTF8String], dstr[-space]);
}

- (void) _appendMap:defs { M(String)* methArgs, *dereferenceable;

    methArgs = @"\n/// Good to make \"shortcuts\" for ALL `_ObjC` types as \"method arguments\"\n"
                "/// with a leading Underscore to use ase parenthesis-free method parameterts!\n".mutableCopy;

    dereferenceable = @"/// For ObjC classes, let's define a preprocessor Macro to call the direct Classes, without the _.\n".mutableCopy;

    [defs enumerateKeysAndObjectsUsingBlock:^(id mapping, id map, BOOL* stop) {

      [self _if:mapping do:^{

        $APPEND(self,@"#pragma mark - %@ \n\n", mapping);

        for (NSString * def in map) {

          NSRange     range = [def rangeOfString:@" " options:NSBackwardsSearch];
          NSString *newType = def[ - (range.location + 1) ],
                 * standard = def[    range.location      ];
          BOOL    isPointer = LOC(standard,@"*") != NSNotFound;

          (isPointer ? (pointers   = pointers   ?: @{}.mutableCopy) :
                       (primitives = primitives ?: @{}.mutableCopy))

          [isPointer ? standard[standard.length -2] : standard] = newType;

          $APPEND(self,@"_Type %30s  %@ _\n", standard.UTF8String, newType);

          if ([@[@"CA", @"NS", @"AV"] containsObject:[standard substringToIndex:2]] && isPointer) { // dereferenceable

            NSString *prefix = [newType substringToIndex:1];

            $APPEND(dereferenceable, @"\n#define %30s%@  %@", [newType[-1] UTF8String],

            [prefix isEqualToString:@"_"] ? @"" : prefix.uppercaseString, standard[standard.length -2]);
          }

          $APPEND(methArgs,@"\n#define %15s_  (%@)", newType.UTF8String, newType);
        }
      }];

    }];

    $APPEND(self,@"%@\n\n%@", _uSort(methArgs),_uSort(dereferenceable));
}

@end

#pragma mark - UTILS

id _hMake(id path) {

  NSCAssert([NSFileManager.defaultManager fileExistsAtPath:path isDirectory:NULL], @"need plist");

  M(String) *head = [M(String) stringWithFormat:@"\n"

    "/*! @note This is an AUTOMATICALLY generated file!\n"
    "    Built on %@ from %@ */\n", [NSDateFormatter localizedStringFromDate:NSDate.date
                                                                   dateStyle:NSDateFormatterMediumStyle
                                                                   timeStyle:NSDateFormatterMediumStyle], path];

  for (id entry in [NSArray arrayWithContentsOfFile:path]) { [head appendString:@"\n"];

    [entry isKindOfClass:NSString.class] ||
    [entry  isKindOfClass:NSArray.class] ? [head appendString:
    [entry isKindOfClass:NSString.class] ? entry : [entry componentsJoinedByString:@"\n"]] :

    [entry enumerateKeysAndObjectsUsingBlock:^(NSString* kind, id defs, BOOL* s) {

      [kind    hasPrefix:@"define"] ? [head _if:kind do:^{ for (id def in defs) [head _addDefine:def]; }]:

      [kind isEqualToString:@"map"] ? [head _appendMap:defs] : nil;
    }];
  }
  return head;
}

id _uSort(id str) { return _sTask($(@"echo \"%@\"|sort|uniq", str)); }

id _sTask(id cmd) { return !cmd ? nil : ({ NSPipe* pipe; NSTask * task;

  [task = NSTask.new setValuesForKeysWithDictionary: @{  @"launchPath" : @"/bin/zsh",
                                                          @"arguments" : @[@"-c", cmd],
                                                     @"standardOutput" : pipe = NSPipe.pipe}]; [task launch];
  [NSString.alloc initWithData: pipe.fileHandleForReading.readDataToEndOfFile encoding:NSUTF8StringEncoding]; });
}

int main() { @autoreleasepool {

  NSString* thisFile = [NSString stringWithUTF8String:__FILE__],
           * srcroot = thisFile.stringByDeletingLastPathComponent,
           * projNme = srcroot.lastPathComponent,
             * plist = args.count > 1 ? args[1] : $(@"%@/%@.plist", srcroot, projNme);

  id genHeader = _hMake(plist); NSError *e = nil;

  NSLog(@"genheader %@", genHeader);
  
  for(id x in @[ $(@"%s/%@.h", BUILT_PRODUCTS_DIR, projNme),
                 $(@"%@/%@.h", srcroot,            projNme)])

    [genHeader writeToFile:x atomically:YES encoding:NSUTF8StringEncoding error:&e]; !e ?: NSLog(@"error:%@",e);

  for (id arg in args) ![arg isMatch:RX(@".*\\.(m|h)$")] ?: NSLog(@"Need to preprocess %@", arg);

  NSLog(@"pointers: %@, primitives: %@", pointers, primitives);

} return EXIT_SUCCESS; }

/*
int _longest(id strings);


int _longest(id strings) {
    return (int)

        [[[strings sortedArrayUsingDescriptors:
                       @[ [NSSortDescriptor.alloc initWithKey:@"length" ascending:YES selector:@selector(localizedStandardCompare:)] ]] firstObject] length];
}


@interface      HeaderWriter : NSObject @end
@implementation HeaderWriter { NSMutableString* _outString; id _plist; }

- initWithPlist:path { return self = super.init &&

  [NSFileManager.defaultManager fileExistsAtPath:_plist = list isDirectory:NULL] ? self : nil;
}
- (NSMutableString*) outString { return _outString = _outString ?: [NSMutableString plist2Header:_plist]; }
@end

//// The NSRegularExpression class is currently only available in the Foundation framework of iOS 4
//NSError *error = NULL;
//NSRegularExpression *regex = [NSRegularExpression regularExpressionWithPattern:@"@property\\s*?\\(nonatomic\\,\\s*?readonly\\)\\s*" options:NSRegularExpressionAnchorsMatchLines error:&error];
//NSString *result = [regex stringByReplacingMatchesInString:searchText options:0 range:NSMakeRange(0, [searchText length]) withTemplate:@"_RO "];

//        __block NSString *newType = nil;
//
//            [def enumerateSubstringsInRange:NSMakeRange(0, def.length)
//                                    options:NSStringEnumerationByWords|NSStringEnumerationReverse
//                                 usingBlock:^(NSString*subs, NSRange sbr, NSRange enclR, BOOL *s) {
//                newType = subs; *stop = YES;
//            }];

//          NSUInteger space = [def rangeOfString:@" "].location;
//          NSString *newType = [def substringFromIndex:space],
            // stringByReplacingOccurrencesOfString:newType withString:@""];
           // substringToIndex:[def rangeOfString:newType].location];


@interface      Replacement : NSObject  @property NSMutableArray *matches; @end

@implementation Replacement

- initWithString:(NSString*)d { if (!(self = super.init)) return nil;

//    [entry enumerateKeysAndObjectsUsingBlock:^(NSString* kind, id definitions, BOOL *s) {
//
//        [kind hasPrefix:@"define"] ?
//
//        [header if:kind do:^{ for (id def in definitions) [header addDefine:def]; }] :
//
//        [kind isEqualToString:@"map"]    ? [header appendMap:definitions] : nil;
//    }];
//
//  entries = e; type = t;  platform = p;
  return self;
}
- (NSMutableString*) generated { NSMutableString *outString = @"\n".mutableCopy;

 return outString;
//  Validity == Universal ?
//  if (type)
}
@end
*/

