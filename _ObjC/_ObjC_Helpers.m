
#import "_ObjC_Tool.h"

NSString * HeaderTemplate() {

  return template = template ?: [NSString stringWithContentsOfFile:templatePath encoding:NSUTF8StringEncoding error:nil];
}

NSDictionary * PlistDataModel() { NSCAssert(plistPath, @"plist path is null!");

  return plist = plist ?: [NSDictionary dictionaryWithContentsOfFile:plistPath];
}


@implementation  NSString (SubstringToOrFrom)

- objectAtIndexedSubscript:(NSInteger)i { return i < 0 ? [self substringFromIndex:ABS(i)] : [self substringToIndex:i]; }

#ifndef MAC_OS_X_VERSION_10_10
- (BOOL) containsString:(NSString*)x    { return [self rangeOfString:x].location != NSNotFound; }
#endif
@end

@implementation RxMatch

- initWithTextCheckingResult:(NSTextCheckingResult*)result forString:(NSString*)original {

  self       = super.init;
  _original  = original;
  _range     = result.range;
  _value     = result.range.length ? [original substringWithRange:result.range] : nil;

  NSMutableArray* groups = @[].mutableCopy;

  for(int i = 0; i < result.numberOfRanges; i++) {

    RxMatch * group = RxMatch.new;
    group.range     = [result rangeAtIndex:i];
    group.value     = group.range.length ? [original substringWithRange:group.range] : nil;

    [groups addObject:group];
  }
  _groups = [groups copy];
  return self;
}

@end
