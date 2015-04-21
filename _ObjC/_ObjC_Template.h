
/*!   @abstract _ObjC is a concise, readable dialect of ObjC that is 100% compatible - without needless tricks.

    @discussion It strives to minimize excessive *'s, {}'s, and ()'s, and so on, and so forth.
                Class pointers and types are typedef'd to aliases, with no pointer,
                formatted like _Four lettes, starting with an underscore, capitalized. */

#pragma once

/*! Our raison d'étre is to make things more readable.. With these simple additions we go from

  - (id) initWithFrame:(NSRect)f;
to 
  _ID initWithFrame __Rect_ r ___

*/


#define        _ :
#define       __ ,
#define      ___ ;



#ifdef __OBJC__                     // Let's stick to what we know.
#if    __STDC_VERSION__ >= 201112L  // We only speak c11 here.

#define DECLARECONFORMANCE(_CLASS_,_PROTOCOL_) @interface _CLASS_ (_PROTOCOL_) <_PROTOCOL_> @end
#define CONFORM(_CLASS_,_PROTOCOL_) @Plan _CLASS_ (_PROTOCOL_) @end

#define NSSTRINGIFY_HELPER_NO_EXPAND(x) @#x
#define NSSTRINGIFY_HELPER(x) NSSTRINGIFY_HELPER_NO_EXPAND(x)
#define NSSTRINGIFY(z) NSSTRINGIFY_HELPER(z)


#define      💩 ?:

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


#define IOS_ONLY TARGET_OS_IPHONE
#define MAC_ONLY !IOS_ONLY

#define  NSLog(...)  (void)fprintf(stderr,"%s\n",$(__VA_ARGS__).UTF8String)
//#define  NSLog(...)  (void)printf("%s %s\n",__PRETTY_FUNCTION__,$(__VA_ARGS__).UTF8String)

#define    _Type typedef

#define     Incl import
#define     Optn optional
#define     Reqd required
#define     Stop end
#define        ￭ @Stop
#define       ＿ Plan
#define ｜(...) ___
#define ￤(...)

#define BLOCKTYPE(NAME,...) _Type void(^NAME)(__VA_ARGS__)

_Type  void(^＾)()___   // Defines a generic block as ＾

/// Let's standarize the preprocessor names too!

//@import ObjectiveC ___
 @class AVAudioPlayer,
        WebView ___
#    if MAC_ONLY
#import <AppKit/AppKit.h>
#  elif IOS_ONLY
@import UIKit ___

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

@Kind(_ObjC_Load) ￭


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

#endif // __STDC_VERSION__ >= 201112L
#endif // __ObjC__


