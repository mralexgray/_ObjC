
#define TEMPLATE  @""\
"/*!   @abstract _ObjC is concise dialect of ObjC that is terse and compatible - without needless tricks."\


NSString * thisFile (){ return [NSString stringWithUTF8String:__FILE__]; }
NSString *  srcroot (){ return thisFile().stringByDeletingLastPathComponent; }
NSString *  projNme (){ return srcroot().lastPathComponent; }
 NSArray * outPaths (){ id defs = [UDEFS stringForKey:@"o"];

  return defs ? [defs componentsSeparatedByString:@":"] :
                @[ $(@"%s/%@.h", BUILT_PRODUCTS_DIR, projNme()),
                   $(@"%@/%@.h", srcroot(),            projNme())];
}

static M(Dictionary)* primitives, *pointers,  *classShortcuts, *parenthized, *qualifiers;

@implementation M(String) (Plist2Header)

- (void) _if:key do:(void (^)())stuff {

    NSString* exclusive = LOC(key,@"_") == NSNotFound ? nil : key[ - (LOC(key,@"_") + 1) ];

    exclusive ? $APPEND(self, @"\n#if %@ // $@\n\n", exclusive) : CR(self); stuff();
    exclusive ? $APPEND(self, @"\n#endif // %@\n",   exclusive) : CR(self);
}

- (void) _appendMap:dict { M(String)* methArgs, *dereferenceable;

    methArgs = @"\n/// Good to make \"shortcuts\" for ALL `_ObjC` types as \"method arguments\"\n"
                "/// with a leading Underscore to use ase parenthesis-free method parameterts!\n".mutableCopy;

    dereferenceable = @"/// For ObjC classes, let's define a preprocessor Macro to call the direct Classes, without the _.\n".mutableCopy;

    [dict enumerateKeysAndObjectsUsingBlock:^(id mapping, id map, BOOL* stop) {

      [self _if:mapping do:^{

        $APPEND(self,@"#pragma mark - %@ \n\n", mapping);

        [self appendString:CUTE_HEADER(@"VAGEEN")];
        
        for (NSString * standard in [map keysSortedByValueUsingSelector:@selector(compare:)]) {

          NSString *newType = map[standard];
          BOOL    isPointer = LOC(standard,@"*") != NSNotFound;

          $APPEND(self,@"_Type %30s  %@ _\n", standard.UTF8String, newType);

          if (isPointer && [@[@"CA", @"NS", @"AV"] containsObject:[standard substringToIndex:2]]) { // dereferenceable

            NSString *prefix = [newType substringToIndex:1],
                  * originalClassName = standard[standard.length -2],
                  * shortcut = [newType[-1] stringByAppendingString: ![prefix isEqualToString:@"_"]
                                                                     ? prefix.uppercaseString : @""];

            $APPEND(dereferenceable, @"\n#define %30s  %@", shortcut.UTF8String, originalClassName);
            (classShortcuts = classShortcuts ?:@{}.mutableCopy)[originalClassName] = shortcut;
          }

          // Add parenthised to dict for regex.
          (parenthized = parenthized ?: @{}.mutableCopy)[$(@"(%@)", newType)] = $(@"%@_", newType);

          $APPEND(methArgs,@"\n#define %15s_  (%@)", newType.UTF8String, newType); // add panethised to header in methargs block
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

      [kind    hasPrefix:@"define"] ? [head _if:kind do:^{

        for (id k in [defs keysSortedByValueUsingSelector:@selector(compare:)]) {
          [head appendFormat:@"#define %30s %@\n", [k UTF8String], defs[k]];

        }
      }] :
//      for (id def in defs) [head _addDefine:def]; }]:

      [kind isEqualToString:@"map"] ? [head _appendMap:defs] : nil;
    }];
  }
  return head;
}

int main() { @autoreleasepool {

  id plist = args.count > 1 ? args[1] : $(@"%@/%@.plist", srcroot(), projNme());

  id genHeader = _hMake(plist); NSError *e = nil;

  for (id x in outPaths())

    [genHeader writeToFile:x atomically:YES encoding:NSUTF8StringEncoding error:&e]; !e ?: NSLog(@"error:%@",e);

//  _preProc();

} return EXIT_SUCCESS; }


@implementation NSString (Subscript)

- objectAtIndexedSubscript:(NSInteger)i { return i < 0 ? [self substringFromIndex:ABS(i)] : [self substringToIndex:i]; }

@end


/*
  for(id x in @[ $(@"%s/%@.h", BUILT_PRODUCTS_DIR, projNme),
                 $(@"%@/%@.h", srcroot,            projNme)])

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

- (void) _addDefines:pair { // dstr = [dstr hasPrefix:@" "] ? dstr[-1] : dstr;

    NSUInteger space = LOC(dstr,@" "); // defines are split at first "space".

    [self appendFormat:@"#define %30s %@\n", [pair[0] UTF8String], pair[1]];
}

void _preProc() {

  NSLog(@"pointers: %@, primitives: %@, classshortcuts: %@, paranthized: %@", pointers, primitives, classShortcuts, parenthized);

//  static Rx *shortcuts = nil;
//  shortcuts = shortcuts ?: RX([classShortcuts.allKeys componentsJoinedByString:@"|"]);

  for (id arg in args) ![arg isMatch:RX(@".*\\.(m|h)$")] ?: ({  NSLog(@"Need to preprocess %@", arg);

    __unused M(String) *work = [M(String) stringWithContentsOfFile:arg encoding:NSUTF8StringEncoding error:nil];

  });

}

*/
