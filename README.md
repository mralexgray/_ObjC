<span style="float:right;">
<img src="https://rawgit.com/mralexgray/_ObjC/master/_ObjC/_ObjC.svg" width="50"/>
</span> 
#`_ObjC` ![NOTSwift]  [![][BStatusImage]][BStatusLink] ![Issues] ![Platforms]

## `A terse, 1:1 dialect of ObjC for Mac + iOS fat targets.`

| Left-Aligned  | Center Aligned  | Right Aligned |
| :------------ |:---------------:| -----:|
| col 3 is      | some wordy text | $1600 |
| col 2 is      | centered        |   $12 |
| zebra stripes | are neat        |    $1 |


- [ ] a bigger project
  - [ ] first subtask #1234
  - [ ] follow up subtask #4321
  - [ ] final subtask cc @mention
- [ ] a separate task


Old tool script target

script
```
#"${CODESIGNING_FOLDER_PATH}"            \
#    -plist  "${SCRIPT_INPUT_FILE_0}"    \
#    -header "${SCRIPT_INPUT_FILE_1}"    \
#    -output "${SCRIPT_OUTPUT_FILE_0}"
#    -tests  "${SCRIPT_OUTPUT_FILE_1}"
```

inputs:
```
\"$(SRCROOT)/$(PROJECT_NAME)/$(PROJECT_NAME).plist\"
\"$(SRCROOT)/$(PROJECT_NAME)/$(PROJECT_NAME)_Template.h\"
```

outputs:
```
\"$(BUILT_PRODUCTS_DIR)/$(PROJECT_NAME).h\"
\"$(DERIVED_FILE_DIR)/myfile\"
```

<table cellpadding="0" cellspacing="3">
      <tbody><tr>
	<td>
	  <a href="/blog/archive/2010/8/16/TargetConditionalsh.html"><img src="/link.gif" width="14" height="16" border="0" alt="(link)"></a>
	</td>
	<td>
	  <b><font size="+1">TargetConditionals.h</font></b> &nbsp; 
	  <font size="-1">(<a href="/blog/archive/2010/8/16/TargetConditionalsh.html">2010-8-16 2:30 PM</a>)</font>
	</td>
      </tr>
      <tr>
	<td>
	  &nbsp;
	</td>
	<td>
      <br>
    <table border="1" cellspacing="0" cellpadding="4">
      <tbody><tr><th></th><td align="center">Mac OS X</td><td align="center">iOS device</td><td align="center">iOS simulator</td>
      </tr><tr><td>TARGET_OS_MAC</td><td bgcolor="#eeffee">1</td><td bgcolor="#eeffee">1</td><td bgcolor="#eeffee">1</td></tr>
      <tr><td>TARGET_OS_IPHONE</td><td>0</td><td bgcolor="#eeffee">1</td><td bgcolor="#eeffee">1</td></tr>
      <tr><td>TARGET_OS_EMBEDDED</td><td>0</td><td bgcolor="#eeffee">1</td><td>0</td></tr>
      <tr><td>TARGET_IPHONE_SIMULATOR</td><td>0</td><td>0</td><td bgcolor="#eeffee">1</td></tr>
    </tbody></table>
    <br>

	</td>
      </tr>
  </tbody></table>
  
``` ruby
require 'redcarpet'
markdown = Redcarpet.new("Hello World!")
puts markdown.to_html
```

``` objective-c
if ([self isKindOfClass:[NSColor class]]) { [self set]; }
```
to  
``` objective-c
!ISA(self,Colr) 💩 [self set] ___
```
 
 
"Full Width" digits...
    
    ０１２３４５６７８９

"Full Width" lowercase letters
    
    ａｂｃｄｅｆｇｈｉｊｋｌｍｎｏｐｑｒｓｔｕｖｗｘｙｚ

"Full Width" uppercase letters
    
    ＡＢＣＤＥＦＧＨＩＪＫＬＭＮＯＰＱＲＳＴＵＶＷＸＹＺ

"Full Width" punctuatuion, etc.
    
    ！＂＃＄％＆＇（）＊＋，－．／：；＜＝＞？＠［＼］＾＿｀｛｜｝～｟｠￠￡￢￣￤￥￦

"Full Width" other symbols...

     ｡｢｣･ￜ￨￩￪￫￬￭￮
#define MATH_SANS 𝗔𝗕𝗖𝗗𝗘𝗙𝗚𝗛𝗜𝗝𝗞𝗟𝗠𝗡𝗢𝗣𝗤𝗥𝗦𝗧𝗨𝗩𝗪𝗫𝗬𝗭
#define MATH_sans 𝗮𝗯𝗰𝗱𝗲𝗳𝗴𝗵𝗶𝗷𝗸𝗹𝗺𝗻𝗼𝗽𝗾𝗿𝘀𝘁𝘂𝘃𝘄𝘅𝘆𝘇


 
 ?  _Text_ [Colr fromTTY:(_Numb_ self).iV] 
 

go from 

/*  NSNib+XMLBase64.h  *  AtoZCodeFactory */

#if TARGET_OS_IPHONE
#import <UIKit/UIKit.h>
#else
#import <AppKit/AppKit.h>
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

Below is the header as was last compiled..

%%CURRENT_VERSION_OF_HEADER_GOES_HERE%%


/// Also in AutoBox (redundancy needs fix)


  // CLANG_IGNORE(-Wuninitialized);

#define     ____ <
#define    _____ >

[Platforms]:    https://img.shields.io/badge/platforms-mac%2Bios%2Bsimulator-lightgrey.svg
[Issues]:       https://img.shields.io/github/issues/mralexgray/_ObjC.svg
[BStatusLink]:  https://travis-ci.org/mralexgray/_ObjC
[BStatusImage]: https://travis-ci.org/mralexgray/_ObjC.svg?branch=master (Travis Build Status)
[NOTSwift]:        https://img.shields.io/badge/NOT%20Swift-YES-blue.svg (NOT swift, lol)


BUGS:
Build fails with Hard drives containing parenthesiseses.
