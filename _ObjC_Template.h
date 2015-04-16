
/*!   @abstract _ObjC is concise dialect of ObjC that is terse and compatible - without needless tricks.
    @discussion It strives to minimize excessive *'s, {}'s, and ()'s, and so on, and so forth.
                Class pointers and types are typedef'd to aliases, with no pointer,
                formatted like _Four lettes, starting with an underscore, capitalized. */

#ifdef   __OBJC__
#ifndef   _ObjC__
#define   _ObjC__

#define        _ :
#define       __ ,
#define      ___ ;
#define     ____ <
#define    _____ >

#define        💩 ?:

#define BLOCKTYPE(NAME,...) _Type void(^NAME)(__VA_ARGS__)

#define   P(...) id<__VA_ARGS__>
#define  _P(...) (id<__VA_ARGS__>)
 #ifdef __P
 #undef __P
 #endif
#define __P(...) : (id<__VA_ARGS__>)

#define _ID - _ObjC_ 
#define Kind_Plan(CLASS,SUPER,...) Kind_ (CLASS,SUPER) ￭ @Plan CLASS

#define ___DSRC_HELPER(X) X##DataSource
#define ___DLGT_HELPER(X) X##Delegate
#define DSRC(X) ___DSRC_HELPER(X)
#define DLGT(X) ___DLGT_HELPER(X)


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

#if MAC_ONLY

%% TYPES.POINTERS_MAC %%

#endif // MAC_ONLY

%% TYPES.POINTERS %%

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

#endif //  _ObjC__
#endif // __ObjC__

