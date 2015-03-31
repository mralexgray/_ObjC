
# _ObjC ![Joke](https://img.shields.io/badge/sexy-definitely-blue.svg) [![Build Status](https://travis-ci.org/mralexgray/_ObjC.svg?branch=master)](https://travis-ci.org/mralexgray/_ObjC) ![Issues](https://img.shields.io/github/issues/mralexgray/_ObjC.svg) ![Platforms](https://img.shields.io/badge/platform-mac%2Bios%2Bsimulator-lightgrey.svg)

![Platform](https://img.shields.io/cocoapods/p/_ObjC.svg)

A terse, 1:1 dialect of ObjC for Mac + iOS fat targets.




go from 

/*  NSNib+XMLBase64.h  *  AtoZCodeFactory */

#if TARGET_OS_IPHONE
@import UIKit;
#else
@import AppKit;
#endif

@interface			             NSNib (XMLBase64)
+      (NSData*)   dataFromXMLPath:(NSString*)p;
+    (NSString*) base64FromXMLPath:(NSString*)p;
+    (NSString*)     xmlFromBase64:(NSString*)p;
+ (instancetype)    nibFromXMLPath:(NSString*)s
														 owner:(id)owner
												topObjects:(NSArray**)objs;
@end

@interface                  NSData (Base64)
+   (NSData*)      dataFromInfoKey:(NSString*)k;
+   (NSData*) dataFromBase64String:(NSString*)s;
- (NSString*)  base64EncodedString;
- (NSString*) base64EncodedStringWithSeparateLines:(BOOL)separateLines; // added by Hiroshi Hashiguchi
@end
