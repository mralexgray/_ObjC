
@import Darwin.getopt;

NSString * _genTokens (NSDictionary *plistData, id section) {

  id      _backing = [plistData valueForKeyPath:section],
               key = [section componentsSeparatedByString:@"."];

  BOOL _emitsTypes = [key[0] isEqualToString:@"TYPES"],
         _sortName = ([plistData[ @"SORT_ALPHA"]containsObject:section] || _emitsTypes) &&
                     ![plistData[@"SORT_LENGTH"]containsObject:section];

  id      sortedKs = [[_backing allKeys] sortedArrayUsingComparator:^NSComparisonResult(id obj1, id obj2) {
    return _sortName ? [obj1 compare:obj2 options:NSCaseInsensitiveSearch]
                     : [@([obj1 length]) compare:@([obj2 length])];
  }];

  M(String) *snippet = $(@"#pragma mark - %@\n\n", [section pathExtension]).mutableCopy,
         *pointerMap = [key[1] containsString:@"POINT"] ? @"".mutableCopy : nil,
           *methArgs = _emitsTypes                      ? @"".mutableCopy : nil;

  for (id k in sortedKs) {

    [snippet appendFormat:@"%@ %30s %@%@ %@\n", _emitsTypes ? @"_Type": @"#define",
                                     [k UTF8String], pointerMap ? @"" : @" ", _backing[k],
                                              _emitsTypes ? @"___": @""];

      if (pointerMap) {
        NSString *prefix =  _backing[k][ 1],
     * originalClassName = k[[k length] -2],
              * shortcut = [_backing[k][-1] stringByAppendingString:
                          ![prefix isEqualToString:@"_"] ? prefix.uppercaseString : @""];

        $APPEND(pointerMap,@"\n#define  %26s  %@", shortcut.UTF8String, originalClassName);
      }

      !_emitsTypes ?: [methArgs appendFormat:@"#define %26s_  (%@)\n", [_backing[k] UTF8String], _backing[k]];

    }

    [snippet appendFormat:@"%@\n\n%@", pointerMap ?: @"", methArgs ?: @""];

  return snippet.copy;
}

NSString* header (NSString *_plistPath, NSString *_templatePath) { NSDictionary *plistData;

    NSCAssert((plistData = [NSDictionary dictionaryWithContentsOfFile:_plistPath]), @"NEEd data, mami");

    NSString *head = [NSString stringWithFormat:@"\n"

    "/*!       @note This file is AUTO_GENERATED! Changes will NOT persist!\n"
    "                Built on %@ from template:%@ with data from:%@ */\n%@",

      [NSDateFormatter localizedStringFromDate:NSDate.date dateStyle:NSDateFormatterMediumStyle
                                                           timeStyle:NSDateFormatterMediumStyle],
                                                           _plistPath.lastPathComponent,
                                                           _templatePath.lastPathComponent,
      [NSString stringWithContentsOfFile:_templatePath encoding:NSUTF8StringEncoding error:nil]];

  return [head replace:RX(@"%% (.*) %%") withDetailsBlock:^NSString *(RxMatch *match) {
  
        return _genTokens(plistData,[match.groups.lastObject value]);
  }];
}

NSString * srcroot (){

  return [NSString stringWithUTF8String:__FILE__].stringByDeletingLastPathComponent;
}

      id  listPath (){

  return  args.count > 1 ? args[1] : $(@"%@/%@.plist", srcroot(), srcroot().lastPathComponent);
}

      id template (){ return $(@"%@/%@_Template.h", srcroot(), srcroot().lastPathComponent); }

NSString *error, *dataPath, *templatePath; __unused NSArray *outPaths;

void print_usage(id error) {

  fprintf(stderr,"\nUsage: %s -t <templatefile> -d <dataPlistFile> <outputPath> [otherOutputPaths]\n\n"
    " -t, --template      <file>  POOPIE the protoype template file's path\n"
    " -d, --definisitions <file>  the plist data file's path\n\n"
    "What we have:\n"
    "  Template: %s\n      Data: %s\n  Outfiles: %lu%s%s\n",
    NSProcessInfo.processInfo.processName.UTF8String,
    templatePath.UTF8String, dataPath.UTF8String, outPaths.count,
    error ? "\n\nError: " : "", error ? [error UTF8String] : "");
}

NSString* _validatePath(const char *p) { id path = nil;

    return [NSFileManager.defaultManager fileExistsAtPath:path = [NSString stringWithUTF8String:p]
                                              isDirectory:NULL] ? path : nil;
}

struct io_opts { /* name of long option */
	const char *name;
	/* one of no_argument, required_argument, and optional_argument: whether option takes an argument */
	int has_arg;
	/* if not NULL, set *flag to val when option found */
	int *flag;
	/* if flag not NULL, value to set *flag to; else return value */
	int val;
};


int main(int argc, char *argv[]) { @autoreleasepool { int ch;

  static struct option longopts[] = { { "template",    required_argument, NULL, 't' },
                                      { "definitions", required_argument, NULL, 'd' }, {NULL, 0, NULL, 0 }};

  while ((ch = getopt_long(argc, argv, "t:d:", longopts, NULL)) != -1)

    error = ch == 't' ? (templatePath = _validatePath(optarg)) ? nil : @"need a valid template file"  :
            ch == 'd' ? (    dataPath = _validatePath(optarg)) ? nil : @"ned a valid plist path"
                      : @"something went wrong";

  argc -= optind;
  argv += optind;

  /* Print any remaining command line arguments (not options). */
  if (optind < argc) while (optind < argc) {

      const char *extra = argv[optind++];
      NSString *outF = [FM stringWithFileSystemRepresentation:extra length:strlen(extra)];
      if (outF) outPaths = [outPaths?:@[] arrayByAddingObject:outF];
    }

  if (error || argc < 2) print_usage(error), exit(EXIT_SUCCESS);

} return EXIT_SUCCESS; }


@implementation NSString (Subscript)

- objectAtIndexedSubscript:(NSInteger)i { return i < 0 ? [self substringFromIndex:ABS(i)] : [self substringToIndex:i]; }

@end


