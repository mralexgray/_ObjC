//
//  _ObjC_Migrator.m
//  _ObjC
//
//  Created by Alex Gray on 7/24/15.
//
//

#import "_ObjC_Tool.h"
#import <ClangKit/ClangKit.h>


#pragma mark - UNIMPLEMENTED


NSDictionary * Migratables () {

  static NSDictionary *d = nil; return d = d ?: ({
    id x = @{}.mutableCopy;
    for (id s in @[@"TYPES.STRUCTS",@"TYPES.POINTERS",@"TYPES.POINTERS_MAC", @"TYPES.PRIMITIVES"]) {

      [x setValuesForKeysWithDictionary:[PlistDataModel() valueForKeyPath:s]];
    }
    [x copy];
  });
}
NSArray * FilterInterestingTokens(id array) {

  return [array filteredArrayUsingPredicate:[NSPredicate predicateWithBlock:^BOOL(CKToken* token, NSDictionary *bindings) {
    return token.kind != CKTokenKindComment && !token.cursor.isInvalid;
  }]];
}

static NSDate *timer;

NSString * RefactorFile (id path) {


  return NSLog(@"%@", Migratables()), @"";

  M(String) *file = [NSMutableString stringWithContentsOfFile:path encoding:NSUTF8StringEncoding error:nil];
        /* First create a translation unit for Objective-C, using a string */
//  timer = NSDate.date;

//  id components = [file componentsSeparatedByString:@"\n\n"];

//  for (NSUInteger t = 0; t < MIN([components count],20); t++) {


      CKTranslationUnit *  tu = [ CKTranslationUnit    translationUnitWithText:file language:CKLanguageObjC];

  [FilterInterestingTokens(tu.tokens) enumerateObjectsUsingBlock:^(id token, NSUInteger idx, BOOL *stop) {

    id possibles = @[].mutableCopy;
    [Migratables() enumerateKeysAndObjectsUsingBlock:^(id key, id obj, BOOL *stop) {

      if ([obj containsString:[token spelling]]) [possibles addObject:key];
    }];
    printf("matched %s with %s",[[token spelling] UTF8String], [possibles description].UTF8String);

//        [PlistDataModel().allKeys[[PlistDataModel().allValues indexOfObject:obj]] UTF8String]);
//    }
  }];

//      if (!goodTokens.count) continue;

  //    NSLog(@"ime:%f",[NSDate.date timeIntervalSinceDate:timer]);
  //  sleep(2);

      // args:@[@"-Weverything" ]
//      printf("%s\n\n", [components[t] UTF8String]);
//
//
//      for (NSUInteger x = 0; x < MIN(goodTokens.count,20); x++) {
//
//        id obj = goodTokens[x];
//
//        fprintf(stderr,"%s\n%s\n", [obj description].UTF8String, [obj cursor].description.UTF8String);
//
//      }
//  }
//  for (id keypath in @[@"TYPES.STRUCTS",@"TYPES.POINTERS",@"TYPES.POINTERS_MAC"]) {

//    [PlistDataModel()[keypath] enumerateKeysAndObjectsUsingBlock:^(id key, id obj, BOOL *stop) {

//  }];

  return file;

}

