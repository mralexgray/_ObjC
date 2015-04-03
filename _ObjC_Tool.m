

NSString * thisFile (){ return [NSString stringWithUTF8String:__FILE__]; }

NSString *  srcroot (){ return thisFile().stringByDeletingLastPathComponent; }

NSString *  projNme (){ return srcroot().lastPathComponent; }

static  id outPaths (){

  return [[UDEFS stringForKey:@"o"] componentsSeparatedByString:@":"]
      ?: @[ $(@"%s/%@.h", BUILT_PRODUCTS_DIR, projNme()), $(@"%@/%@.h", srcroot(),projNme())];
}
static  id listPath () { return  args.count > 1 ? args[1] : $(@"%@/%@.plist", srcroot(), projNme()); }
static  id plistRef () { return [NSDictionary dictionaryWithContentsOfFile:listPath()];
}
static  id template () { return @"/Volumes/2T/ServiceData/AtoZ.framework/AtoZUniversal/_ObjC/_ObjC_Template.h"; }


NSString * _genTokens (id parse) { id _backing = [plistRef() valueForKeyPath:parse];

  NSLog(@"gettting KP:%@", parse);

  id key = [parse componentsSeparatedByString:@"."];
  BOOL _emitsTypes = [key[0] isEqualToString:@"TYPES"],
         _sortName = ( [_backing[ @"SORT_ALPHA"]containsObject:parse] || _emitsTypes) &&
                      ![_backing[@"SORT_LENGTH"]containsObject:parse];

  id sortedKs = [[_backing allKeys] sortedArrayUsingComparator:^NSComparisonResult(id obj1, id obj2) {
    return _sortName ? [obj1 compare:obj2 options:NSCaseInsensitiveSearch]
                     : [@([obj1 length]) compare:@([obj2 length])];
  }];

  M(String) *snippet = @"".mutableCopy, *pointerMap = [key[1] containsString:@"POINT"] ? @"".mutableCopy : nil,
                                        *methArgs = _emitsTypes ? @"".mutableCopy : nil;

  for (id k in sortedKs) {

    [snippet appendFormat:@"%@ %30s %@ %@\n", _emitsTypes ? @"_Type": @"#define", [k UTF8String], _backing[k],
                                              _emitsTypes ? @"_": @""];

      if (pointerMap) {

              NSString *prefix = [_backing[k] substringToIndex:1],
                  * originalClassName = k[[k length] -2],
                  * shortcut = [_backing[k][-1] stringByAppendingString: ![prefix isEqualToString:@"_"]
                                                                     ? prefix.uppercaseString : @""];

            [pointerMap appendFormat:@"\n#define %26s  %@", shortcut.UTF8String, originalClassName];
      }
      if (_emitsTypes) {

        [methArgs appendFormat:@"#define %22s_ (%@)\n", [_backing[k] UTF8String], _backing[k]];

      }

    }

    [snippet appendFormat:@"%@\n%@\n", pointerMap ?: @"", methArgs ?: @""];


  return snippet.copy;
}

id _hMake() {

  for (id x in @[template(), listPath()])
    NSCAssert([NSFileManager.defaultManager fileExistsAtPath:x isDirectory:NULL], @"need %@", x);

  id defs = plistRef();
    NSCAssert(defs, @"need definigions");

  NSString *head = [NSString stringWithFormat:@"\n"

    "/*! @note This is an AUTOMATICALLY generated file!\n"
    "    Built on %@ from %@ */\n%@",

      [NSDateFormatter localizedStringFromDate:NSDate.date dateStyle:NSDateFormatterMediumStyle
                                                           timeStyle:NSDateFormatterMediumStyle],
                                                           listPath(),
      [NSString stringWithContentsOfFile:template() encoding:NSUTF8StringEncoding error:nil]];

  return [head replace:RX(@"%% (.*) %%") withDetailsBlock:^NSString *(RxMatch *match) {
  
    return _genTokens([match.groups.lastObject value]);
  }];

}

int main() { @autoreleasepool {

  id genHeader = _hMake(); NSError *e = nil;

  for (id x in outPaths())

    [genHeader writeToFile:x atomically:YES encoding:NSUTF8StringEncoding error:&e]; !e ?: NSLog(@"error:%@",e);

  _sTask(@" terminal-notifier -title 'poop' -message 'vageen'");

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


@implementation M(String) (Plist2Header)

- (void) _if:key do:(void (^)())stuff {

    NSString* exclusive = LOC(key,@"_") == NSNotFound ? nil : key[ - (LOC(key,@"_") + 1) ];

    exclusive ? $APPEND(self, @"\n#if %@ // $@\n\n", exclusive) : CR(self); stuff();
    exclusive ? $APPEND(self, @"\n#endif // %@\n",   exclusive) : CR(self);
}

- (void) _appendMap:dict { M(String)* methArgs, *dereferenceable;

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
typedef NS_ENUM(int,Emits) { EmitsDefines, EmitsTypes  };
typedef NS_ENUM(int,SortBy){ SortByLength, SortByAlpha };

@end
*/

