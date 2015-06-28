
/*!   @abstract _ObjC is a concise, readable dialect of ObjC that is 100% compatible - without needless tricks.

    @discussion It strives to minimize excessive *'s, {}'s, and ()'s, and so on, and so forth.
                Class pointers and types are typedef'd to aliases, with no pointer,
                formatted like _Four lettes, starting with an underscore, capitalized. */

#pragma once

//#import <TargetConditionals.h>

#ifdef __OBJC__                     // Let's stick to what we know.
#if    __STDC_VERSION__ >= 201112L  // We only speak c11 here.

/*! Our raison d'étre is to make things more readable.. With these simple additions we go from

  - (id) initWithFrame:(NSRect)f;
to 
  _ID initWithFrame __Rect_ r ___

*/

#define IOS_ONLY TARGET_OS_IPHONE
#define MAC_ONLY !IOS_ONLY

#define      💩 ?:
#define        _ :
#define       __ ,
#define      ___ ;

#define    _Type typedef

//#define     Kind interface
#define       🅺 @Kind
#define  🅚(K,...) 🅺 K : __VA_ARGS__
#define       🆇 @Xtra
#define  🅧(...) @Xtra(__VA_ARGS__)
#define       🅿︎ @Plan // 🅟
#define       🆅 @Vows // 🅥
#define       🅲 @concrete
#define  🅒(...) @concreteprotocol(__VA_ARGS__)

#define     Incl import
#define     Optn optional
#define     Reqd required
#define     Stop end
#define        ￭ @Stop
#define       ＿ Plan
#define ｜(...) ___
#define ￤(...)

#define IFNIL(VAR,...) (VAR = VAR ?: __VA_ARGS__)

#define     $(...)    (_Text_ [Text stringWithFormat:__VA_ARGS__,nil])
#define     $PICT(...)    (_Pict_ [Pict imageNamed:__VA_ARGS__])


#define DECLARECONFORMANCE(_CLASS_,_PROTOCOL_) @interface _CLASS_ (_PROTOCOL_) <_PROTOCOL_> @end
#define CONFORM(_CLASS_,_PROTOCOL_) @Plan _CLASS_ (_PROTOCOL_) @end

#define    Ｐ(...) id<__VA_ARGS__>
#define   _Ｐ(...) (id<__VA_ARGS__>)
 #define __Ｐ(...) : (id<__VA_ARGS__>)

#define Code NSCoding
#define Copy NSCopying
#define Fast NSFastEnumeration

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

/// Let's standarize the preprocessor names too!

//@import ObjectiveC
#import <objc/runtime.h>
    ___
 @class AVAudioPlayer
     __ WebView
     __ XCTestCase
    ___

#    if MAC_ONLY
#import <AppKit/AppKit.h>
#  elif IOS_ONLY
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

/*! Kind - Interface (Prototypes, Public, Name, etc)
    Vows - Protocol  (Promises, etc)
    Plan - Implemenation
    Xtra - Categories                                      */

%% DEFINES.ABBREVIATIONS %%

%% DEFINES.MISC %%

%% DEFINES.STRINGS %%
//%% DEFINES.NS %%

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

#define _EnumKind(ENUM_TYPENAME, ENUM_CONSTANTS...)                                    \
                                                                                       \
    _Type enum { ENUM_CONSTANTS } ENUM_TYPENAME ___                                    \
    extern _Dict ENUM_TYPENAME##xHex  ()                                          ___  \
    extern _Dict ENUM_TYPENAME##xVal  ()                                          ___  \
    extern _Dict ENUM_TYPENAME##xLbl  ()                                          ___  \
    extern _List ENUM_TYPENAME##All   ()                                          ___  \
    extern _Text ENUM_TYPENAME##2Text (int enumKind)                              ___  \
    extern _IsIt ENUM_TYPENAME##4Text(_Text enumLabel, ENUM_TYPENAME *enumValue)  ___  \
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
  _Dict ENUM_TYPENAME##xVal() {	_List constants = _EnumParse##ENUM_TYPENAME##ConstantsString();	NEW(NSMutableDictionary,result) \
    for (_UInt i = 0; i < constants.count; i += 2) result[constants[i+1]] = constants[i];	return result; \
  }	\
  _Dict ENUM_TYPENAME##xLbl() {	_List constants = _EnumParse##ENUM_TYPENAME##ConstantsString();	\
    NEW(NSMutableDictionary,result) \
    for (_UInt i = 0; i < constants.count; i += 2) result[constants[i]] = constants[i+1]; return result;	\
  }	\
  _Dict ENUM_TYPENAME##xHex() {	_List constants = _EnumParse##ENUM_TYPENAME##ConstantsString();	NEW(NSMutableDictionary,result) \
    for (_UInt i = 0; i < constants.count; i += 2) result[constants[i]] = constants[i+1];	return result;	\
  } \
  _Text ENUM_TYPENAME##2Text(int enumValue) {	\
    return ENUM_TYPENAME##xVal()[[NSNumber numberWithInt:enumValue]] ?: $(@"<unknown "#ENUM_TYPENAME": %d>", enumValue);	\
  }	\
  _IsIt ENUM_TYPENAME##4Text(_Text enumLabel, ENUM_TYPENAME *enumValue) {	\
    _Numb value = ENUM_TYPENAME##xLbl()[enumLabel];	\
    return value ? ({ *enumValue = (ENUM_TYPENAME)[value intValue];	YES; }) : NO; \
  } \
  _List ENUM_TYPENAME##All() { return ENUM_TYPENAME##xVal().allKeys; } CLANG_POP

#endif // __STDC_VERSION__ >= 201112L
#endif // __ObjC__


