
  @abstract _ObjC is a sensible dialect of ObjC that doesn't suck.
     @brief Uncluttered, easy to remember, and obvious to any neophyte.
            Purge needless punctuation, especially *'s, {}'s, and ()'s, and so on, and so forth.
            Class pointers and types are typedef'd to aliases, with no pointer,
            formatted like _Four lettes, starting with an underscore, capitalized.
*/

#pragma once                              // Lord, please!

#ifdef __OBJC__                           // Let's stick to what we know. (We know ObjC)
#if    __STDC_VERSION__ >= 201112L        // std=c11 is REQUIED, honey... catch it.

#define IOS_ONLY  TARGET_OS_IPHONE        // Why not make this easy on us, Apple?
#define MAC_ONLY  !IOS_ONLY               // Simple #if MAC_ONLY or #if IOS_ONLY.  duh.

#define        _  :                       // Semicolon -> underscore x 1
#define       __  ,                       //     Comma -> underscore x 2
#define      ___  ;                       //     Colon -> underscore x 3

#pragma mark - Comment helpers

/*!
	single ➜ <#type#> <#declaration#> ｜('<#oneline-comment#>')

	multi  ➜ <#type#> <#declaration#> ￤('<#one#>') ___
          	<#type#> <#declaration#> ｜('<#two#>')
*/

#define ｜(...) ___
#define ￤(...)

/*! Our raison d'étre is to make things more readable.. With these simple additions we go from

    - (id) initWithFrame:(NSRect)f;

  to something more like...

    - initWithFrame __Rect_ r ___

  Kind - Interface Declaration (Prototypes, Public, Name, etc)
  Vows - Protocol  (Promises, etc)
  Plan - Implemenation
  Xtra - Categories                                      */

#define        💩  ?:                   	// Some of you are going... to.. hate.. this.
#define      _Type  typedef              	// Since we're gonna typedef virtually everything, lets retype typedef, lol.

#pragma mark - Objective C Keywords

#define       Incl  import
#define       Optn  optional
#define       Reqd  required
#define       Stop  end
#define          ￭  @Stop

#define       Kind  interface            	// Let's call a horse, a horse.
#define       Plan 	implementation				// Arent we cute?

#define         🅺  @Kind                	// @Kind <#ClassName#> or 🅺<#ClassName#>
#define         🆇  @Xtra
#define         🅿︎ 	@Plan
#define       	🆅 	@Vows
#define      		🅲 	@concrete             // 🅥 🅟

#define  🅚(K,...)  @KIND(K,__VA_ARGS__)
#define    🅧(...)  @Xtra(__VA_ARGS__)
#define 	 🅒(...) 	@concreteprotocol(__VA_ARGS__)
#define    🅥(...)  <__VA_ARGS__>

#define    Ｐ(...) 	id<__VA_ARGS__>
#define   _Ｐ(...)	(id<__VA_ARGS__>)
#define  __Ｐ(...):	(id<__VA_ARGS__>)


%% DEFINES.MISC %%


#define Code NSCoding
#define Copy NSCopying
#define Fast NSFastEnumeration


#define StringFromBOOL(b) (b?@"YES":@"NO")
#define $B(b) StringFromBOOL(b)
#define CharFromBOOL(b) (b?"YES":"NO")
#define $$B(b) CharFromBOOL(b)

//#define       ＿ Plan

#define IFNIL(VAR,...) (VAR = VAR ?: __VA_ARGS__)

#define     $(...)    (_Text_ [Text stringWithFormat:__VA_ARGS__,nil])
#define     $PICT(...)    (_Pict_ [Pict imageNamed:__VA_ARGS__])


#define DECLARECONFORMANCE(_CLASS_,_PROTOCOL_) @interface _CLASS_ (_PROTOCOL_) <_PROTOCOL_> @end
#define CONFORM(_CLASS_,_PROTOCOL_) @Plan _CLASS_ (_PROTOCOL_) @end


#define _ID - _ObjC_ 
#define Kind_Plan(CLASS,SUPER,...) Kind_ (CLASS,SUPER) ￭ @Plan CLASS

#define ___DSRC_HELPER(X) X##DataSource
#define ___DLGT_HELPER(X) X##Delegate
#define DSRC(X) ___DSRC_HELPER(X)
#define DLGT(X) ___DLGT_HELPER(X)


#define _XCTCase(_name_)  @Kind_(_name_,XCTestCase) ￭ @Plan _name_
#define _XCTest(X,...)    - (void)  test##X { ({ __VA_ARGS__; }); }
#define _XCTDown(...)     - (void) tearDown { ({ __VA_ARGS__; }); [super tearDown]; }
#define _XCTUp(...)       - (void)    setUp { [super setUp]; ({ __VA_ARGS__; }); }


#define  NSLog(...)  (void)fprintf(stderr,"%s\n",$(__VA_ARGS__).UTF8String)

//#define  NSLog(...)  (void)printf("%s %s\n",__PRETTY_FUNCTION__,$(__VA_ARGS__).UTF8String)

#define BLOCKTYPE(NAME,...) _Type void(^NAME)(__VA_ARGS__)

_Type  void(^＾)()___   // Defines a generic block as ＾

#define ALLOWED @"ϟ ツ ⌘ ☁ ½"


//#define ∧ @"carrot"

/// Let's standarize the preprocessor names too!

//@import ObjectiveC

#import <objc/runtime.h>

 @class WebView
     __ XCTestCase
     __ ORSSerialPort
     __ AVAudioPlayer
    ___

#if MAC_ONLY
#import <AppKit/AppKit.h>

%% DEFINES.STANDARD_NAMES_MAC %%

#elif IOS_ONLY
#import <UIKit/UIKit.h>

// Standarize names 1:1 between platforms. (DEFINES.STANDARD_NAMES)

%% DEFINES.STANDARD_NAMES %%

%% DEFINES.GEOMETRY_TRANSLATIONS %%

#endif // Per-Platform Imports (DEFINES.STANDARD_NAMES)

%% TYPES.PRIMITIVES %%

%% TYPES.STRUCTS %%


//typdeffing.  for example, I will show mapping of const char *, as ironically, it cannot be achieved like the others

#define _CChr const char *
#define _CChr_ (_CChr)
#define __CChr_ : _CChr_

%% TYPES.POINTERS %%

#if MAC_ONLY

%% TYPES.POINTERS_MAC %%

#endif // MAC_ONLY

%% TYPES.BLOCKS_VOIDS %%

%% TYPES.BLOCKS %%

/*! Good to make shortcuts for ALL  types as method arguments,
    with a leading Underscore to use ase parenthesis-free method parameterts! */

/// For ObjC classes, let's define a preprocessor Macro to call the direct Classes, without the _.

%% DEFINES.PROPERTIES %%

%% DEFINES.ABBREVIATIONS %%

%% DEFINES.STRINGS %%

%% DEFINES.NS %%

@KIND(_ObjC_Load) ￭


NS_INLINE id concatDescriptions(id uno, ...) { id result = @"".mutableCopy; va_list args; va_start(args, uno);

  for (id arg = uno; arg != nil; arg = va_arg(args, id)) [result appendString:[arg description]]; va_end(args); return result;
}

#define $$$(FIRST,...) concatDescriptions(FIRST,__VA_ARGS__,nil)

#define FULLW_DIGIT ０１２３４５６７８９
#define FULLW_alpha ａｂｃｄｅｆｇｈｉｊｋｌｍｎｏｐｑｒｓｔｕｖｗｘｙｚ
#define FULLW_ALPHA ＡＢＣＤＥＦＧＨＩＪＫＬＭＮＯＰＱＲＳＴＵＶＷＸＹＺ
#define FULLW_OTHER ！＂＃＄％＆＇（）＊＋，－．／：；＜＝＞？＠［＼］＾＿｀｛｜｝～｟｠￠￡￢￣￤￥￦
#define HALFW_OTHER ｡｢｣･ￜ￨￩￪￫￬￭￮
#define MATH_SANS 𝗔𝗕𝗖𝗗𝗘𝗙𝗚𝗛𝗜𝗝𝗞𝗟𝗠𝗡𝗢𝗣𝗤𝗥𝗦𝗧𝗨𝗩𝗪𝗫𝗬𝗭
#define MATH_sans 𝗮𝗯𝗰𝗱𝗲𝗳𝗴𝗵𝗶𝗷𝗸𝗹𝗺𝗻𝗼𝗽𝗾𝗿𝘀𝘁𝘂𝘃𝘄𝘅𝘆𝘇

#define NSSTRINGIFY_HELPER_NO_EXPAND(x) @#x
#define NSSTRINGIFY_HELPER(x) NSSTRINGIFY_HELPER_NO_EXPAND(x)
#define NSSTRINGIFY(z) NSSTRINGIFY_HELPER(z)

#define PRAGMA(X) _Pragma(#X)

#define CLANG_IGNORE_HELPER0(x) #x
#define CLANG_IGNORE_HELPER1(x) CLANG_IGNORE_HELPER0(clang diagnostic ignored x)
#define CLANG_IGNORE_HELPER2(y) CLANG_IGNORE_HELPER1(#y)

#define CLANG_POP               PRAGMA(clang diagnostic pop)
#define CLANG_IGNORE(x)         PRAGMA(clang diagnostic push); _Pragma(CLANG_IGNORE_HELPER2(x))

#define CLANG_IGNORE_DEPRECATED CLANG_IGNORE(-Wdeprecated-declarations)
#define CLANG_IGNORE_PROTOCOL   CLANG_IGNORE(-Wprotocol)
#define CLANG_IGNORE_NO_ATTR    CLANG_IGNORE(-Wobjc-property-no-attribute)

CLANG_IGNORE_NO_ATTR


#define _Enum(ENUM_TYPENAME, ENUM_CONSTANTS...)                                                           \
                _Type enum { ENUM_CONSTANTS } ENUM_TYPENAME ___                                           \
                              static _Text _##ENUM_TYPENAME##_constants_string = @"" #ENUM_CONSTANTS ___  \
                                    _EnumPlan(ENUM_TYPENAME)
#define Ⅲ _EnumKind

#define _EnumKind(ENUM_TYPENAME, ENUM_CONSTANTS...)                                    \
                                                                                       \
    _Type enum { ENUM_CONSTANTS } ENUM_TYPENAME ___                                    \
    extern _Dict ENUM_TYPENAME##xHex  ()                                          ___  \
    extern _Dict ENUM_TYPENAME##xVal  ()                                          ___  \
    extern _Dict ENUM_TYPENAME##xLbl  ()                                          ___  \
    extern _List ENUM_TYPENAME##All   ()                                          ___  \
    extern _Dict ENUM_TYPENAME##Info  ()                                          ___  \
    extern _Text ENUM_TYPENAME##2Text (int enumKind)                              ___  \
    extern _IsIt ENUM_TYPENAME##4Text(_Text enumLabel, ENUM_TYPENAME *enumValue)  ___  \
    extern _Void ENUM_TYPENAME##Test(int enumKind)  ___  \
    CLANG_IGNORE(-Wunused-variable)                                                    \
    static _Text _##ENUM_TYPENAME##_constants_string = @"" #ENUM_CONSTANTS        ___  \
    CLANG_POP

#define _EnumPlan(ENUM_TYPENAME) \
\
  CLANG_IGNORE(-Wmissing-prototypes) \
  _List _EnumParse##ENUM_TYPENAME##ConstantsString() {	\
    _Text constantsString = [[_##ENUM_TYPENAME##_constants_string componentsSeparatedByCharactersInSet:NSCharacterSet.whitespaceAndNewlineCharacterSet] componentsJoinedByString:@""]; \
    constantsString = ![constantsString hasSuffix:@","] ? constantsString : [constantsString substringToIndex:constantsString.length-1]; \
    NEW(NSMutableArray,labelsAndValues) \
    VAR(int,nextDefaultValue,0)	\
    for (_Text stringPair in [constantsString componentsSeparatedByString:@","]) {	\
      _List labelAndValueString = [stringPair componentsSeparatedByString:@"="];	\
      _Text label               = labelAndValueString[0];	\
      _Text valueString         = labelAndValueString.count > 1 ? labelAndValueString[1] : nil;	\
        int value; \
      if (valueString) { \
        _Rnge shiftTokenRange = [valueString rangeOfString:@"<<"]; \
        if (shiftTokenRange.location != NSNotFound) { \
          valueString = [valueString substringFromIndex:shiftTokenRange.location + 2]; \
          value = 1 << valueString.intValue; \
        } else if ([valueString hasPrefix:@"0x"]) { \
          [[NSScanner scannerWithString:valueString] scanHexInt:(unsigned int*)&value]; \
        } else value = valueString.intValue; \
      } else value = nextDefaultValue; \
      nextDefaultValue = value + 1;	\
      [labelsAndValues addObject:label];	\
      [labelsAndValues addObject:[NSNumber numberWithInt:value]];	\
    }	\
    return labelsAndValues;	\
  } \
  _Dict ENUM_TYPENAME##xVal() {	_List constants = _EnumParse##ENUM_TYPENAME##ConstantsString();	NEW(DictM,result) \
    for (_UInt i = 0; i < constants.count; i += 2) result[constants[i+1]] = constants[i];	return result.copy; \
  }	\
  _Dict ENUM_TYPENAME##xLbl() {	_List constants = _EnumParse##ENUM_TYPENAME##ConstantsString();	NEW(DictM,result) \
    for (_UInt i = 0; i < constants.count; i += 2) result[constants[i]] = constants[i+1]; return result.copy;	\
  }	\
  _Dict ENUM_TYPENAME##xHex() {	_List constants = _EnumParse##ENUM_TYPENAME##ConstantsString();	NEW(DictM,result) \
    for (_UInt i = 0; i < constants.count; i += 2) result[constants[i]] = @(i).hexString;	return result.copy;	\
  } \
  _Dict ENUM_TYPENAME##Info() {	_List constants = _EnumParse##ENUM_TYPENAME##ConstantsString();	NEW(DictM,result) \
    for (_UInt i = 0; i < constants.count; i += 2) result[constants[i]] = @{ @"hex" : @(i).hexString, @"value" : constants[i+1] };	return result.copy;	\
  } \
  _Text ENUM_TYPENAME##2Text(int enumValue) {	\
    return ENUM_TYPENAME##xVal()[[Numb numberWithInt:enumValue]] ?: $(@"<unknown "#ENUM_TYPENAME": %d>", enumValue);	\
  }	\
  _IsIt ENUM_TYPENAME##4Text(_Text enumLabel, ENUM_TYPENAME *enumValue) {	\
    _Numb value = ENUM_TYPENAME##xLbl()[enumLabel];	\
    return value ? ({ *enumValue = (ENUM_TYPENAME)[value intValue];	YES; }) : NO; \
  } \
  _Void ENUM_TYPENAME##Test(int enumKind){ \
    printf("%s: %d (%s)\n", [ENUM_TYPENAME##2Text(enumKind) UTF8String], enumKind, @(enumKind).hexString.UTF8String); \
    [ENUM_TYPENAME##Info() enumerateKeysAndObjectsUsingBlock:^(_Text k, _Dict v, BOOL *s){ \
      int comp = [v[@"value"] intValue]; \
      printf("\t%s (%s)\n\t\t& %s\t\t| %s\t\t^ %s\n\n", k.UTF8String, [v[@"hex"]UTF8String], $$B(enumKind&comp), $$B(enumKind|comp),$$B(enumKind*comp));\
    }]; \
  } \
  _List ENUM_TYPENAME##All() { return ENUM_TYPENAME##xVal().allKeys; } CLANG_POP

#endif // __STDC_VERSION__ >= 201112L
#endif // __ObjC__


