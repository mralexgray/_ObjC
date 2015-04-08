
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

#define IOS_ONLY TARGET_OS_IPHONE
#define MAC_ONLY !IOS_ONLY

#define  NSLog(...)  (void)printf("%s %s\n",__PRETTY_FUNCTION__,$(__VA_ARGS__).UTF8String)

#define    _Type typedef

#define     Incl import
#define     Optn optional
#define     Reqd required
#define     Stop end
#define        ￭ @Stop
#define       ＿ Plan

/// Let's standarize the preprocessor names too!

@import ObjectiveC ___
 @class AVAudioPlayer,
        WebView ___
#    if MAC_ONLY
@import Cocoa ___
#  elif IOS_ONLY
@import UIKit ___

// Standarize names 1:1 between platforms. (DEFINES.STANDARD_NAMES)

%% DEFINES.STANDARD_NAMES %%

#endif // Per-Platform Imports (DEFINES.STANDARD_NAMES)

%% TYPES.PRIMITIVES %%

%% TYPES.STRUCTS %%

#if MAC_ONLY

%% TYPES.POINTERS_MAC %%

#endif // MAC_ONLY

%% TYPES.POINTERS %%

/*! Good to make shortcuts for ALL  types as method arguments,
    with a leading Underscore to use ase parenthesis-free method parameterts! */

/// For ObjC classes, let's define a preprocessor Macro to call the direct Classes, without the _.


/*! Kind - Interface (Prototypes, Public, Name, etc)
    Vows - Protocol  (Promises, etc)
    Plan - Implemenation
    Xtra - Categories                                      */

%% DEFINES.MISC %%

%% DEFINES.ABBREVIATIONS %%

#if IOS_ONLY //

%% DEFINES.GEOMETRY_TRANSLATIONS %%

#endif // IOS_ONLY/GEOMETRY

@Kind(_ObjC_Load) ￭

#endif //  _ObjC__
#endif // __ObjC__

