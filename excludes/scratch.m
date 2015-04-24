//#define _ObjC_Please(CLASS) [NSUD
//#define     ✳️  - (instancetype)
//#define     ❇️  + (instancetype)


//id replace(NSRegularExpression*self, NSString *string, NSString*(^replacer)(RxMatch*)) {
//
//  if (!replacer) return string;                   // no replacer? just return
//
//  NSMutableString* replaced = string.mutableCopy; //copy the string so we can replace subsections
//  NSArray* matches = [self matchesInString:string options:0 range:NSMakeRange(0, string.length)]; //get matches
//  for (int i=(int)matches.count-1; i>=0; i--) { //replace each match (right to left so indexing doesn't get messed up)
//
//    NSTextCheckingResult* result = matches[i];
//
//    [replaced replaceCharactersInRange:result.range
//                            withString:
//    /* replacement */ replacer(/*RxMatch* match */result2Match(result,string))];
//  }
//  return replaced;
//}
//  replace([NSRegularExpression.alloc initWithPattern:@"%% (.*) %%" options:0 error:nil],
//
//    $(@"\n/*!       @note This file is AUTO_GENERATED! Changes will NOT persist!\n"
//       "                Built on %@ from template:%@ with data from:%@ */\n%@",
//     THEDATE, [plistPath lastPathComponent], [templatePath lastPathComponent],HeaderTemplate()),
//
//  );

id replace(NSRegularExpression*,NSString*,NSString*(^)(RxMatch*));
