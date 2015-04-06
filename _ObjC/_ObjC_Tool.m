
NSString * _genTokens (NSDictionary *_plistData, NSString* _section) {

  id        backing = [_plistData valueForKeyPath:_section],
           keyParts = [_section componentsSeparatedByString:@"."];

  BOOL   emitsTypes = [keyParts[0] isEqualToString:@"TYPES"],
           sortName = ([_plistData[ @"SORT_ALPHA"]containsObject:_section] || emitsTypes) &&
                      ![_plistData[@"SORT_LENGTH"]containsObject:_section];

  id       sortedKs = [[backing allKeys] sortedArrayUsingComparator:^NSComparisonResult(NSString*x1, NSString*x2) {
    return sortName ? [x1           compare:x2 options:NSCaseInsensitiveSearch]
                    : [@(x1.length) compare:@(x2.length)];
  }];

  M(String) *snippet = $(@"#pragma mark - %@\n\n", _section.pathExtension).mutableCopy,
         *pointerMap = [keyParts[1] containsString:@"POINT"] ? @"".mutableCopy : nil,
           *methArgs = emitsTypes                            ? @"".mutableCopy : nil;

  for (NSString *k in sortedKs) {

    [snippet appendFormat:@"%@ %30s %@%@ %@\n", emitsTypes ? @"_Type" : @"#define",
                                  k.UTF8String, pointerMap ? @""      : @" ", backing[k],
                                                emitsTypes ? @"___"   : @""];

      if (pointerMap) {
        NSString *prefix =  backing[k][  1],
     * originalClassName =  k[k.length - 2],
              * shortcut =  $(@"%@%@", backing[k][-1], ![prefix isEqualToString:@"_"] ? prefix.uppercaseString : @"");

        $APPEND(pointerMap,@"\n#define  %26s  %@", shortcut.UTF8String, originalClassName);
      }

      !emitsTypes ?: [methArgs appendFormat:@"#define %26s_  (%@)\n", [backing[k] UTF8String], backing[k]];

    }

    [snippet appendFormat:@"%@%@%@", pointerMap ?: @"", methArgs ? @"\n\n" : @"", methArgs ?: @""];

  return snippet.copy;
}

NSString* header (NSString *plist, NSString *template) { NSDictionary *_data; id _template;

  NSCAssert(( _template = [NSString stringWithContentsOfFile:template encoding:NSUTF8StringEncoding error:nil]) &&
            (     _data = [NSDictionary dictionaryWithContentsOfFile:plist]), @"Need data + template, mami");

    NSString *head = [NSString stringWithFormat:@"\n"

    "/*!       @note This file is AUTO_GENERATED! Changes will NOT persist!\n"
    "                Built on %@ from template:%@ with data from:%@ */\n%@", THEDATE,
                                                              plist.lastPathComponent,
                                                           template.lastPathComponent, _template];

  return [head replace:RX(@"%% (.*) %%") withDetailsBlock:^NSString *(RxMatch *match) {
  
        return _genTokens(_data,[match.groups.lastObject value]);
  }];
}

id ObjectForAnyKeyPassingTest (NSDictionary *values, NSArray*okKeys, BOOL(^test)(id)) {

  __block id found = nil;
  [okKeys enumerateObjectsUsingBlock:^(id obj, NSUInteger idx, BOOL *stop) {

      if ((found = [values objectForKey:obj])) { *stop = (test == NULL) || test(found); }
  }];
  return found;
}

BOOL( ^IsFileAndExists )(id) = ^BOOL(id p){ BOOL dir = NO, exists =[FM fileExistsAtPath:p isDirectory:&dir];

  return exists && !dir ?: NSLog(@"%@ %s exist. %s a directory.",p, exists ? "DOES" : "does NOT",
                                                       dir ? "It is, but CANNOT be" : "Thankully, it's not"), NO;
};

int main() { @autoreleasepool {

  NSDictionary *opts = ParseArgs();

  NSString *model = ObjectForAnyKeyPassingTest(opts,@[@"d",@"data",@"model",@"plist"], IsFileAndExists),
           *templ = ObjectForAnyKeyPassingTest(opts,@[@"t",@"template",@"header"], IsFileAndExists);
        id output = ObjectForAnyKeyPassingTest(opts,@[@"o",@"output"], NULL);

  if (!model || !templ) return EXIT_FAILURE;

  id x = header(model, templ);

  if (!output) fprintf(stdout, "%s", [x UTF8String]);
  else for (id place in [output isKindOfClass:NSString.class] ? @[output] : output)
      [x writeToFile:place atomically:YES encoding:NSUTF8StringEncoding error:nil];

} return EXIT_SUCCESS; }

@implementation NSString (Subscript)

- objectAtIndexedSubscript:(NSInteger)i { return i < 0 ? [self substringFromIndex:ABS(i)] : [self substringToIndex:i]; }

@end
