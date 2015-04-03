
/*!   @abstract _ObjC is concise dialect of ObjC that is terse and compatible - without needless tricks.
    @discussion It strives to minimize excessive *'s, {}'s, and ()'s, and so on, and so forth.
                Class pointers and types are typedef'd to aliases, with no pointer,
                formatted like _Four lettes, starting with an underscore, capitalized. */

#ifdef   __OBJC__
#ifndef   _ObjC__
#define   _ObjC__

#define        _ ;

#define IOS_ONLY TARGET_OS_IPHONE
#define MAC_ONLY !IOS_ONLY

#define    _Type typedef
#define     Incl import
#define     Optn optional
#define     Reqd required
#define     Stop end
#define        ￭ @Stop
#define ＿ Plan


/// Let's standarize the preprocessor names too!

@import ObjectiveC _
 @class AVAudioPlayer,
        WebView _
#    if MAC_ONLY
@import Cocoa _
#  elif IOS_ONLY
@import UIKit _

// Standarize names 1:1 between platforms.

%% DEFINES.STANDARD_NAMES %%

#endif // Per-Platform Imports


#pragma mark - primitives 

%% TYPES.PRIMITIVES %%

#pragma mark - structs 

%% TYPES.STRUCTS %%

#pragma mark - pointers (MAC_ONLY)

#if MAC_ONLY

%% TYPES.POINTERS_MAC %%

#endif // MAC_ONLY

#pragma mark - pointers 

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

// GEOMETRY TRANSLATIONS

#if IOS_ONLY // $@

%% DEFINES.GEOMETRY_TRANSLATIONS %%

#endif // IOS_ONLY

#endif // _ObjC__
#endif // __ObjC__

