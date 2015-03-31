@import AppKit;

@interface      Replacement : NSObject  @property NSMutableArray *matches; @end

@implementation Replacement

- initWithString:(NSString*)d { if (!(self = super.init)) return nil;

    [entry enumerateKeysAndObjectsUsingBlock:^(NSString* kind, id definitions, BOOL *s) {

        [kind hasPrefix:@"define"] ?

        [header if:kind do:^{ for (id def in definitions) [header addDefine:def]; }] :

        [kind isEqualToString:@"map"]    ? [header appendMap:definitions] : nil;
    }];

  entries = e; type = t;  platform = p; return self;
}
- (NSMutableString*) generated { NSMutableString *outString = @"\n".mutableCopy;

  Validity == Universal ?
  if (type)
}
@end



@implementation  NSMutableString (Plist2Header)

- (void) if:(NSString*)key do:(void(^)())stuff {

  NSUInteger platform = [key rangeOfString: @"_"].location; // look for underscore.
  NSString *exclusive = platform != NSNotFound ? [key substringFromIndex:platform + 1] : nil;

  exclusive ? [self appendFormat:@"\n#if %@\n", exclusive]       : [self appendString:@"\n"];   stuff();
  exclusive ? [self appendFormat:@"\n#endif // %@\n", exclusive] : [self appendString:@"\n"];
}

- (void) addDefine:(NSString*)def {  // definitiions is array of #defines. split at first "space".

  NSUInteger space = [def rangeOfString:@" "].location;

  [self appendFormat:@"#define %20s %@\n", [[def   substringToIndex:space] UTF8String],
                                           [def substringFromIndex:space]];
}

- (void) appendMap:(NSDictionary*)definitions {

  NSMutableString *methArgs, * dereferenceable;

    methArgs =  @"\n/// Good to make \"shortcuts\" for ALL `_ObjC` types as \"method arguments\"\n"
       "/// with a leading Underscore to use ase parenthesis-free method parameterts!\n".mutableCopy;

    dereferenceable = @"/// For ObjC classes, let's define a preprocessor Macro to call the direct Classes, without the _.\n".mutableCopy;

    [definitions enumerateKeysAndObjectsUsingBlock:^(id mapping, id map, BOOL *stop) {

      [self if:mapping do:^{

        [self appendFormat:@"#pragma mark - %@ \n\n", mapping];

        for (NSString * def in map) {

//        __block NSString *newType = nil;
//
//            [def enumerateSubstringsInRange:NSMakeRange(0, def.length)
//                                    options:NSStringEnumerationByWords|NSStringEnumerationReverse
//                                 usingBlock:^(NSString*subs, NSRange sbr, NSRange enclR, BOOL *s) {
//                newType = subs; *stop = YES;
//            }];

        NSRange range = [def rangeOfString:@" " options:NSBackwardsSearch];
        NSString *newType = [def substringFromIndex:range.location+1];

//          NSUInteger space = [def rangeOfString:@" "].location;
//          NSString *newType = [def substringFromIndex:space],
           NSString * standard = [def substringToIndex:range.location];

            // stringByReplacingOccurrencesOfString:newType withString:@""];
           // substringToIndex:[def rangeOfString:newType].location];

          [self appendFormat:@"_Type %30s  %@ _\n", standard.UTF8String, newType];

          if ([@[@"CA", @"NS", @"AV"] containsObject:[standard substringToIndex:2]]) {

            NSString *prefix = [newType substringToIndex:1];
            [dereferenceable appendFormat:@"\n#define %30s%@  %@", [[newType substringFromIndex:1] UTF8String],
                  [prefix isEqualToString:@"_"] ? @"" : [prefix uppercaseString],
                                              [standard substringToIndex:standard.length -2]];
//            break;
          }

          [methArgs appendFormat:@"\n#define %15s_  (%@)", [newType UTF8String], newType];
        }
    }];

  }];

  [self appendFormat:@"%@\n\n%@", methArgs, dereferenceable];
}

+ plist2Header:(NSString*)p {

  NSMutableString *header = [self stringWithFormat:@"\n"

    "/*! @note This is an AUTOMATICALLY generated file!\n"
    "    Built on %@ from %@ */\n", [NSDateFormatter localizedStringFromDate:NSDate.date
                                                                     dateStyle:NSDateFormatterMediumStyle
                                                                    timeStyle:NSDateFormatterMediumStyle], p];

  for (id entry in [NSArray arrayWithContentsOfFile:p]) {

    [header appendString:@"\n"];

    [entry isKindOfClass:NSString.class] ? [header appendString:entry] :

    [entry enumerateKeysAndObjectsUsingBlock:^(NSString* kind, id definitions, BOOL *s) {

        [kind hasPrefix:@"define"] ?

        [header if:kind do:^{ for (id def in definitions) [header addDefine:def]; }] :

        [kind isEqualToString:@"map"]    ? [header appendMap:definitions] : nil;
    }];
  }

  return header;
}

@end

int main(int argc, char*argv[], char**argp) { @autoreleasepool {


  NSString * plist,
           * thisFile  = [NSString stringWithUTF8String:__FILE__],
           * srcroot   = thisFile.stringByDeletingLastPathComponent,
           * projName  = srcroot.lastPathComponent,
           * inputfile = argc > 1 && [NSFileManager.defaultManager fileExistsAtPath:
                 plist = [NSString stringWithUTF8String:argv[1]] isDirectory:NULL] ? plist
                       : [NSString stringWithFormat:@"%@/%@.plist", srcroot, projName];

  NSMutableArray *outfiles = @[[NSString stringWithFormat:@"%s/%@.h",BUILT_PRODUCTS_DIR,projName],
                               [NSString stringWithFormat:@"%@/%@.h",srcroot, projName]].mutableCopy;

  if (argc > 2) { int argcc = 2;

    while (argcc < argc) { [outfiles addObject:[NSString stringWithUTF8String:argv[argcc]]]; argcc++; }
  }

  id x = [NSMutableString plist2Header:inputfile];

  for (id outPath in outfiles) {
    NSError *e = nil;
    [x writeToFile:outPath atomically:YES encoding:NSUTF8StringEncoding error:&e];
    !e ?: NSLog(@"error:%@", e);
  }

}	return EXIT_SUCCESS; }

//// The NSRegularExpression class is currently only available in the Foundation framework of iOS 4
//NSError *error = NULL;
//NSRegularExpression *regex = [NSRegularExpression regularExpressionWithPattern:@"@property\\s*?\\(nonatomic\\,\\s*?readonly\\)\\s*" options:NSRegularExpressionAnchorsMatchLines error:&error];
//NSString *result = [regex stringByReplacingMatchesInString:searchText options:0 range:NSMakeRange(0, [searchText length]) withTemplate:@"_RO "];
