
/*!       @note This file is AUTO_GENERATED! Changes will NOT persist!
                Built on Apr 16, 2015, 12:21:16 PM from template:_ObjC.plist with data from:_ObjC_Template.h */

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
//#define     ✳️  - (instancetype)
//#define     ❇️  + (instancetype)


#define BLOCKTYPE(NAME,...) _Type void(^NAME)(__VA_ARGS__)
//#define _ObjC_Please(CLASS) [NSUD

#define P(...) id<__VA_ARGS__>
#define _P(...) (id<__VA_ARGS__>)
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

#pragma mark - STANDARD_NAMES

#define                           NSApp   UIApp 
#define                           NSNib   UINib 
#define                          NSRect   CGRect 
#define                          NSFont   UIFont 
#define                          NSSize   CGSize 
#define                          NSView   UIView 
#define                         NSPoint   CGPoint 
#define                         NSImage   UIImage 
#define                         NSEvent   UIEvent 
#define                         NSColor   UIColor 
#define                        NSScreen   UIScreen 
#define                        NSWindow   UIWindow 
#define                      NSZeroRect   CGRectZero 
#define                      NSZeroSize   CGSizeZero 
#define                     NSZeroPoint   CGPointZero 
#define                     NSTableView   UITableView 
#define                    NSBezierPath   UIBezierPath 
#define                   NSApplication   UIApplication 
#define              NSUserNotification   UILocalNotification 


#pragma mark - END DEFINES.STANDARD_NAMES PROBLEMS: 

#pragma mark - GEOMETRY_TRANSLATIONS

#define                       rectValue   CGRectValue 
#define                      NSMakeRect   CGRectMake 
#define                      NSMakeSize   CGSizeMake 
#define                      pointValue   CGPointValue 
#define                     NSMakePoint   CGPointMake 
#define                    NSEqualRects   CGRectEqualToRect 
#define                    NSEqualSizes   CGSizeEqualToSize 
#define                   NSEqualPoints   CGPointEqualToPoint 
#define              NSPointInRect(P,R)   CGRectContainsPoint(R,P) 


#pragma mark - END DEFINES.GEOMETRY_TRANSLATIONS PROBLEMS: 

#endif // Per-Platform Imports (DEFINES.STANDARD_NAMES)

#pragma mark - PRIMITIVES

_Type                              id   _ObjC  ___
_Type                             SEL   _Meth  ___
_Type                            void   _Void  ___
_Type                            BOOL   _IsIt  ___
_Type                            long   _Long  ___
_Type                           Class   _Meta  ___
_Type                       NSInteger   _SInt  ___
_Type                      NSUInteger   _UInt  ___
_Type                   unsigned long   _ULng  ___
_Type              NSComparisonResult   _Comp  ___


#define                      _ObjC_   ( _ObjC )
#define                     __ObjC_   : ( _ObjC )
#define                      _OC      - _ObjC_
#define                      _Meth_   ( _Meth )
#define                     __Meth_   : ( _Meth )
#define                      _MH      - _Meth_
#define                      _Void_   ( _Void )
#define                     __Void_   : ( _Void )
#define                      _IsIt_   ( _IsIt )
#define                     __IsIt_   : ( _IsIt )
#define                      _IT      - _IsIt_
#define                      _Long_   ( _Long )
#define                     __Long_   : ( _Long )
#define                      _Meta_   ( _Meta )
#define                     __Meta_   : ( _Meta )
#define                      _MA      - _Meta_
#define                      _SInt_   ( _SInt )
#define                     __SInt_   : ( _SInt )
#define                      _ST      - _SInt_
#define                      _UInt_   ( _UInt )
#define                     __UInt_   : ( _UInt )
#define                      _UT      - _UInt_
#define                      _ULng_   ( _ULng )
#define                     __ULng_   : ( _ULng )
#define                      _Comp_   ( _Comp )
#define                     __Comp_   : ( _Comp )


#pragma mark - END TYPES.PRIMITIVES PROBLEMS: 

#pragma mark - STRUCTS

_Type               CGAffineTransform   _AffT  ___
_Type                         CGFloat   _Flot  ___
_Type                         CGPoint   _Cord  ___
_Type                          CGRect   _Rect  ___
_Type                          CGSize   _Size  ___
_Type                         NSRange   _Rnge  ___


#define                      _AffT_   ( _AffT )
#define                     __AffT_   : ( _AffT )
#define                      _Flot_   ( _Flot )
#define                     __Flot_   : ( _Flot )
#define                      _FT      - _Flot_
#define                      _Cord_   ( _Cord )
#define                     __Cord_   : ( _Cord )
#define                      _CD      - _Cord_
#define                      _Rect_   ( _Rect )
#define                     __Rect_   : ( _Rect )
#define                      _RT      - _Rect_
#define                      _Size_   ( _Size )
#define                     __Size_   : ( _Size )
#define                      _SE      - _Size_
#define                      _Rnge_   ( _Rnge )
#define                     __Rnge_   : ( _Rnge )
#define                      _RE      - _Rnge_


#pragma mark - END TYPES.STRUCTS PROBLEMS: 

#if MAC_ONLY

#pragma mark - POINTERS_MAC

_Type             NSArrayController *   xList  ___
_Type                  NSFileHandle *   _Hndl  ___
_Type                   NSImageView *   _PicV  ___
_Type                        NSMenu *   _Menu  ___
_Type                    NSMenuItem *   _SubM  ___
_Type                 NSOutlineView *   _OutV  ___
_Type                  NSScrollView *   _Scrl  ___
_Type                   NSSplitView *   _Splt  ___
_Type                 NSTableColumn *   _TCol  ___
_Type                   NSTableView *   _Tabl  ___
_Type                        NSTask *   _Task  ___
_Type                   NSTextField *   _Labl  ___
_Type                    NSTextView *   _TxtV  ___
_Type            NSWindowController *   xWind  ___
_Type                       WebView *   _WebV  ___

#define                       ListX   NSArrayController
#define                        Hndl   NSFileHandle
#define                        PicV   NSImageView
#define                        Menu   NSMenu
#define                        SubM   NSMenuItem
#define                        OutV   NSOutlineView
#define                        Scrl   NSScrollView
#define                        Splt   NSSplitView
#define                        TCol   NSTableColumn
#define                        Tabl   NSTableView
#define                        Task   NSTask
#define                        Labl   NSTextField
#define                        TxtV   NSTextView
#define                       WindX   NSWindowController
#define                        WebV   WebView

#define                      xList_   ( xList )
#define                     _xList_   : ( xList )
#define                      _Hndl_   ( _Hndl )
#define                     __Hndl_   : ( _Hndl )
#define                      _PicV_   ( _PicV )
#define                     __PicV_   : ( _PicV )
#define                      _Menu_   ( _Menu )
#define                     __Menu_   : ( _Menu )
#define                      _SubM_   ( _SubM )
#define                     __SubM_   : ( _SubM )
#define                      _OutV_   ( _OutV )
#define                     __OutV_   : ( _OutV )
#define                      _Scrl_   ( _Scrl )
#define                     __Scrl_   : ( _Scrl )
#define                      _Splt_   ( _Splt )
#define                     __Splt_   : ( _Splt )
#define                      _TCol_   ( _TCol )
#define                     __TCol_   : ( _TCol )
#define                      _Tabl_   ( _Tabl )
#define                     __Tabl_   : ( _Tabl )
#define                      _Task_   ( _Task )
#define                     __Task_   : ( _Task )
#define                      _Labl_   ( _Labl )
#define                     __Labl_   : ( _Labl )
#define                      _TxtV_   ( _TxtV )
#define                     __TxtV_   : ( _TxtV )
#define                      xWind_   ( xWind )
#define                     _xWind_   : ( xWind )
#define                      _WebV_   ( _WebV )
#define                     __WebV_   : ( _WebV )


#pragma mark - END TYPES.POINTERS_MAC PROBLEMS: 

#endif // MAC_ONLY

#pragma mark - POINTERS

_Type                 AVAudioPlayer *   _SndP  ___
_Type                       CALayer *   _Layr  ___
_Type                          char *   _Char  ___
_Type                    const char *   _CChr  ___
_Type                 NSApplication *   _Appl  ___
_Type                       NSArray *   _List  ___
_Type            NSAttributedString *   _ATxt  ___
_Type                  NSBezierPath *   _Path  ___
_Type                      NSBundle *   _Bndl  ___
_Type                NSCharacterSet *   _CSet  ___
_Type                       NSColor *   _Colr  ___
_Type                        NSData *   _Data  ___
_Type                  NSDictionary *   _Dict  ___
_Type                       NSError *   _Errr  ___
_Type                       NSEvent *   _Evnt  ___
_Type                  NSFileHandle *   _File  ___
_Type                        NSFont *   _Font  ___
_Type                       NSImage *   _Pict  ___
_Type                      NSIndexSet   _ISet  ___
_Type                  NSInvocation *   _Call  ___
_Type           NSJSONSerialization *   _Json  ___
_Type                NSMutableArray *   mList  ___
_Type     NSMutableAttributedString *   mATxt  ___
_Type         NSMutableCharacterSet *   mCSet  ___
_Type                 NSMutableData *   mData  ___
_Type           NSMutableDictionary *   mDict  ___
_Type             NSMutableIndexSet *   mISet  ___
_Type       NSMutableParagraphStyle *   mPStl  ___
_Type               NSMutableString *   mText  ___
_Type                NSNotification *   _Note  ___
_Type                      NSNumber *   _Numb  ___
_Type                      NSObject *   _NObj  ___
_Type              NSParagraphStyle *   _PStl  ___
_Type                        NSPipe *   _Pipe  ___
_Type                      NSString *   _Text  ___
_Type                   NSTableView *   _TblV  ___
_Type                         NSURL *   _NUrl  ___
_Type                NSUserDefaults *   _Defs  ___
_Type                       NSValue *   _Valu  ___
_Type                        NSView *   _View  ___
_Type                      NSWindow *   _Wind  ___
_Type                 unsigned char *   _UChr  ___

#define                        SndP   AVAudioPlayer
#define                        Layr   CALayer
#define                        Char   char
#define                        CChr   const char
#define                        Appl   NSApplication
#define                        List   NSArray
#define                        ATxt   NSAttributedString
#define                        Path   NSBezierPath
#define                        Bndl   NSBundle
#define                        CSet   NSCharacterSet
#define                        Colr   NSColor
#define                        Data   NSData
#define                        Dict   NSDictionary
#define                        Errr   NSError
#define                        Evnt   NSEvent
#define                        File   NSFileHandle
#define                        Font   NSFont
#define                        Pict   NSImage
#define                        ISet   NSIndexS
#define                        Call   NSInvocation
#define                        Json   NSJSONSerialization
#define                       ListM   NSMutableArray
#define                       ATxtM   NSMutableAttributedString
#define                       CSetM   NSMutableCharacterSet
#define                       DataM   NSMutableData
#define                       DictM   NSMutableDictionary
#define                       ISetM   NSMutableIndexSet
#define                       PStlM   NSMutableParagraphStyle
#define                       TextM   NSMutableString
#define                        Note   NSNotification
#define                        Numb   NSNumber
#define                        NObj   NSObject
#define                        PStl   NSParagraphStyle
#define                        Pipe   NSPipe
#define                        Text   NSString
#define                        TblV   NSTableView
#define                        NUrl   NSURL
#define                        Defs   NSUserDefaults
#define                        Valu   NSValue
#define                        View   NSView
#define                        Wind   NSWindow
#define                        UChr   unsigned char

#define                      _SndP_   ( _SndP )
#define                     __SndP_   : ( _SndP )
#define                      _Layr_   ( _Layr )
#define                     __Layr_   : ( _Layr )
#define                      _LR      - _Layr_
#define                      _Char_   ( _Char )
#define                     __Char_   : ( _Char )
#define                      _CChr_   ( _CChr )
#define                     __CChr_   : ( _CChr )
#define                      _Appl_   ( _Appl )
#define                     __Appl_   : ( _Appl )
#define                      _List_   ( _List )
#define                     __List_   : ( _List )
#define                      _LT      - _List_
#define                      _ATxt_   ( _ATxt )
#define                     __ATxt_   : ( _ATxt )
#define                      _Path_   ( _Path )
#define                     __Path_   : ( _Path )
#define                      _PH      - _Path_
#define                      _Bndl_   ( _Bndl )
#define                     __Bndl_   : ( _Bndl )
#define                      _BL      - _Bndl_
#define                      _CSet_   ( _CSet )
#define                     __CSet_   : ( _CSet )
#define                      _CT      - _CSet_
#define                      _Colr_   ( _Colr )
#define                     __Colr_   : ( _Colr )
#define                      _CR      - _Colr_
#define                      _Data_   ( _Data )
#define                     __Data_   : ( _Data )
#define                      _DA      - _Data_
#define                      _Dict_   ( _Dict )
#define                     __Dict_   : ( _Dict )
#define                      _DT      - _Dict_
#define                      _Errr_   ( _Errr )
#define                     __Errr_   : ( _Errr )
#define                      _ER      - _Errr_
#define                      _Evnt_   ( _Evnt )
#define                     __Evnt_   : ( _Evnt )
#define                      _ET      - _Evnt_
#define                      _File_   ( _File )
#define                     __File_   : ( _File )
#define                      _FE      - _File_
#define                      _Font_   ( _Font )
#define                     __Font_   : ( _Font )
#define                      _Pict_   ( _Pict )
#define                     __Pict_   : ( _Pict )
#define                      _PT      - _Pict_
#define                      _ISet_   ( _ISet )
#define                     __ISet_   : ( _ISet )
#define                      _Call_   ( _Call )
#define                     __Call_   : ( _Call )
#define                      _Json_   ( _Json )
#define                     __Json_   : ( _Json )
#define                      _JN      - _Json_
#define                      mList_   ( mList )
#define                     _mList_   : ( mList )
#define                      mLT      - mList_
#define                      mATxt_   ( mATxt )
#define                     _mATxt_   : ( mATxt )
#define                      mCSet_   ( mCSet )
#define                     _mCSet_   : ( mCSet )
#define                      mCT      - mCSet_
#define                      mData_   ( mData )
#define                     _mData_   : ( mData )
#define                      mDA      - mData_
#define                      mDict_   ( mDict )
#define                     _mDict_   : ( mDict )
#define                      mDT      - mDict_
#define                      mISet_   ( mISet )
#define                     _mISet_   : ( mISet )
#define                      mPStl_   ( mPStl )
#define                     _mPStl_   : ( mPStl )
#define                      mText_   ( mText )
#define                     _mText_   : ( mText )
#define                      mTT      - mText_
#define                      _Note_   ( _Note )
#define                     __Note_   : ( _Note )
#define                      _Numb_   ( _Numb )
#define                     __Numb_   : ( _Numb )
#define                      _NB      - _Numb_
#define                      _NObj_   ( _NObj )
#define                     __NObj_   : ( _NObj )
#define                      _NJ      - _NObj_
#define                      _PStl_   ( _PStl )
#define                     __PStl_   : ( _PStl )
#define                      _PL      - _PStl_
#define                      _Pipe_   ( _Pipe )
#define                     __Pipe_   : ( _Pipe )
#define                      _PE      - _Pipe_
#define                      _Text_   ( _Text )
#define                     __Text_   : ( _Text )
#define                      _TT      - _Text_
#define                      _TblV_   ( _TblV )
#define                     __TblV_   : ( _TblV )
#define                      _TV      - _TblV_
#define                      _NUrl_   ( _NUrl )
#define                     __NUrl_   : ( _NUrl )
#define                      _NL      - _NUrl_
#define                      _Defs_   ( _Defs )
#define                     __Defs_   : ( _Defs )
#define                      _Valu_   ( _Valu )
#define                     __Valu_   : ( _Valu )
#define                      _View_   ( _View )
#define                     __View_   : ( _View )
#define                      _VW      - _View_
#define                      _Wind_   ( _Wind )
#define                     __Wind_   : ( _Wind )
#define                      _WD      - _Wind_
#define                      _UChr_   ( _UChr )
#define                     __UChr_   : ( _UChr )


#pragma mark - END TYPES.POINTERS PROBLEMS: 

#pragma mark - BLOCKS_VOIDS

_Type         _Void (^ ＾Void)  _Void_     ___
_Type              _Void (^ ＾Blok) ()     ___
_Type       _Void (^ ＾Cord) (_Cord p)     ___
_Type       _Void (^ ＾Data) (_Data d)     ___
_Type       _Void (^ ＾Dict) (_Dict d)     ___
_Type       _Void (^ ＾IsIt) (_IsIt b)     ___
_Type       _Void (^ ＾List) (_List a)     ___
_Type       _Void (^ ＾Numb) (_Numb n)     ___
_Type       _Void (^ ＾NUrl) (_NUrl u)     ___
_Type       _Void (^ ＾ObjC) (_ObjC x)     ___
_Type       _Void (^ ＾Rect) (_Rect r)     ___
_Type       _Void (^ ＾Text) (_Text p)     ___


#define                      _＾Void   ( ＾Void )
#define                      ＾Void_   : ( ＾Void )
#define                      _＾Blok   ( ＾Blok )
#define                      ＾Blok_   : ( ＾Blok )
#define                      _＾Cord   ( ＾Cord )
#define                      ＾Cord_   : ( ＾Cord )
#define                      _＾Data   ( ＾Data )
#define                      ＾Data_   : ( ＾Data )
#define                      _＾Dict   ( ＾Dict )
#define                      ＾Dict_   : ( ＾Dict )
#define                      _＾IsIt   ( ＾IsIt )
#define                      ＾IsIt_   : ( ＾IsIt )
#define                      _＾List   ( ＾List )
#define                      ＾List_   : ( ＾List )
#define                      _＾Numb   ( ＾Numb )
#define                      ＾Numb_   : ( ＾Numb )
#define                      _＾NUrl   ( ＾NUrl )
#define                      ＾NUrl_   : ( ＾NUrl )
#define                      _＾ObjC   ( ＾ObjC )
#define                      ＾ObjC_   : ( ＾ObjC )
#define                      _＾Rect   ( ＾Rect )
#define                      ＾Rect_   : ( ＾Rect )
#define                      _＾Text   ( ＾Text )
#define                      ＾Text_   : ( ＾Text )


#pragma mark - END TYPES.BLOCKS_VOIDS PROBLEMS: 

#pragma mark - BLOCKS





#pragma mark - END TYPES.BLOCKS PROBLEMS: 

/*! Good to make shortcuts for ALL  types as method arguments,
    with a leading Underscore to use ase parenthesis-free method parameterts! */

/// For ObjC classes, let's define a preprocessor Macro to call the direct Classes, without the _.

#pragma mark - PROPERTIES

#define                             _AS   @property (AS) 
#define                             _AT   @property 
#define                             _CP   @property (CP) 
#define                             _NA   @property (NA) 
#define                             _NC   @property (NA,CP) 
#define                             _RC   @property (RO,CP) 
#define                             _RO   @property (RO) 
#define                             _WK   @property (WK) 
#define                             ASS   assign 
#define                              CP   copy 
#define                              NA   nonatomic 
#define                              RO   readonly 
#define                              RW   readwrite 
#define                             STR   strong 
#define                            UNSF   unsafe_unretained 
#define                              WK   weak 


#pragma mark - END DEFINES.PROPERTIES PROBLEMS: 

/*! Kind - Interface (Prototypes, Public, Name, etc)
    Vows - Protocol  (Promises, etc)
    Plan - Implemenation
    Xtra - Categories                                      */

#pragma mark - ABBREVIATIONS

#define                             _FM   NSFileManager.defaultManager 
#define                             _PI   NSProcessInfo.processInfo 
#define                             _VD   - _Void_  
#define                             bFK   boolForKey 
#define                              bV   boolValue 
#define                              dV   doubleValue 
#define                              fV   floatValue 
#define                              iV   integerValue 
#define                           mAVFK   mutableArrayValueForKey 
#define                              mC   mutableCopy 
#define                             oFK   objectForKey 
#define                              pV   pointValue 
#define                            rngV   rangeValue 
#define                              rV   rectValue 
#define                            strV   stringValue 
#define                             uIV   unsignedIntegerValue 
#define                             vFK   valueForKey 
#define                            vFKP   valueForKeyPath 


#pragma mark - END DEFINES.ABBREVIATIONS PROBLEMS: 

#pragma mark - MISC

#define                        $UNIC(C)   [NSString stringWithCharacter:C] 
#define                 _Case(Name,...)   @Incl XCTest; @Kind_ (Name,XCTestCase)  ￭ @Plan Name XCTUp(__VA_ARGS__) 
#define                     _Cat(K,...)   @interface K (Sans) __VA_ARGS__; @end 
#define                           _FINI   @end 
#define                           _IFCE   @interface 
#define                           _IMPL   @implementation 
#define                           _IMPT   @import 
#define                           _Kind   @interface 
#define                          _Kind_   (instancetype) /// Sugar for (instancetype) methods. 
#define                           _PRTO   @protocol 
#define                    _Test(X,...)   - (void) test##X { ({ __VA_ARGS__; }); } 
#define                    INIT_(K,...)   [[K alloc] init##__VA_ARGS__] 
#define                  INIT_THEN(...)   SUPERINIT; ({ __VA_ARGS__ }); return self; 
#define                INTERFACE(X,...)   @interface X : __VA_ARGS__ + (instancetype) 
#define                  Kind(Name,...)   Kind_(Name,NObj,__VA_ARGS__) 
#define            Kind_(Name,Meta,...)   interface Name : Meta __VA_ARGS__ 
#define                        NEW(A,B)   A *B = A.new 
#define                   NSStringValue   @"stringValue" 
#define                            Plan   implementation 
#define                   SELFINIT(...)   return self = super.init ? ({ __VA_ARGS__; }), self : nil 
#define                            Vows   protocol 
#define                    XCTDown(...)   - (void) tearDown { ({ __VA_ARGS__; }); [super tearDown]; } 
#define                      XCTUp(...)   - (void) setUp { [super setUp]; ({ __VA_ARGS__; }); } 
#define             Xtra(Extends,Named)   interface Extends      (Named) 
#define         XtraPlan(Extends,Named)   implementation Extends (Named) 
#define                   XtraStop(...)   Stop 


#pragma mark - END DEFINES.MISC PROBLEMS: 

#pragma mark - STRINGS

#define           ATTR(NAME_WITHOUT_NS)   NS##NAME_WITHOUT_NS##AttributeName 
#define                            BNDL   NSBundle.mainBundle 
#define                       BNDL_NAME   [NSBundle.mainBundle objectForInfoDictionaryKey:@"CFBundleDisplayName"] 
#define                       BNDL_RSRC   [NSBundle.mainBundle resourcePath] 
#define                       COLR_PANL   NSColorPanel.sharedColorPanel 
#define                            DEFS   NSUserDefaults.standardUserDefaults 
#define                            DEFX   NSUserDefaultsController.sharedUserDefaultsController 
#define                       EV_GLOBAL   NSEvent addGlobalMonitorForEventsMatchingMask 
#define                        EV_LOCAL   NSEvent addLocalMonitorForEventsMatchingMask  
#define                            FMAN   NSFileManager.defaultManager 
#define                            GCTX   NSGraphicsContext.currentContext 
#define                        KVO_BOTH   NSKeyValueObservingOptionNew|NSKeyValueObservingOptionOld 
#define                         KVO_NEW   NSKeyValueObservingOptionNew 
#define                         KVO_OLD   NSKeyValueObservingOptionOld 
#define                            LAYM   [CAConstraintLayoutManager layoutManager] 
#define                      MOUSE_DOWN   NSLeftMouseDownMask 
#define                      MOUSE_DRAG   NSLeftMouseDraggedMask 
#define                  MOUSE_DRAGGING   MOUSEDOWN | MOUSEDRAG | MOUSEUP 
#define                        MOUSE_UP   NSLeftMouseUpMask 
#define                            NADA   [NSNull  null] 
#define                            NCTR   (NSNotificationCenter*)NSNotificationCenter.defaultCenter 
#define                     NSZeroRange   NSMakeRange(0,0) 
#define                            pBCN   postsBoundsChangedNotifications 
#define                   PDOMAIN(NAME)   [DEFS persistentDomainForName:NAME] 
#define                            pFCN   postsFrameChangedNotifications 
#define                            PROC   NSProcessInfo.processInfo 
#define                       PROC_NAME   [NSProcessInfo.processInfo processName] 
#define                         RNG0(X)   NSMakeRange(0,X) 
#define                            SAPP   NSApplication.sharedApplication 
#define                       V_Colr(c)   [NSVAL valueWithColor: c] 
#define                       V_Cord(p)   [NSVAL valueWithPoint: p] 
#define                       V_Rect(r)   [NSVAL		 valueWithRect: r] 
#define                       V_Rnge(c)   [NSVAL  valueWithRange: c] 
#define                       V_Size(s)   [NSVAL valueWithSize: s] 
#define                        VAL3d(t)   [NSVAL valueWithCATransform3D: t] 
#define                            WORK   NSWorkspace.sharedWorkspace 


#pragma mark - END DEFINES.STRINGS PROBLEMS: 
//#pragma mark - NS

#define                             NSB   NSBundle 
#define                             NSW   NSWindow 
#define                             NSC   NSColor 
#define                             NSD   NSDictionary 
#define                             NSE   NSEvent 
#define                             NSF   NSFont 
#define                             NSG   NSGradient 
#define                             NSI   NSInteger 
#define                             SIG   NSMethodSignature 
#define                             NSM   NSMenu 
#define                             NSN   NSNumber 
#define                             NSO   NSObject 
#define                             NSP   NSPoint 
#define                             NSR   NSRect 
#define                             NSS   NSString 
#define                             NST   NSTimer 
#define                             NSV   NSView 
#define                             NSA   NSArray 
#define                            NSVT   NSValueTransformer 
#define                            NSMS   NSMutableString 
#define                            NSOV   NSOutlineView 
#define                            NSAC   NSArrayController 
#define                            NSUI   NSUInteger 
#define                            NSMI   NSMenuItem 
#define                            NSBP   NSBezierPath 
#define                            NSRE   NSRectEdge 
#define                            NSTI   NSTimeInterval 
#define                            NSIP   NSIndexPath 
#define                            NSCS   NSCountedSet 
#define                            NSPO   NSPopover 
#define                            NSWC   NSWindowController 
#define                            NSGC   NSGraphicsContext 
#define                            NSST   NSSet 
#define                            NSSI   NSStatusItem 
#define                            NSJS   NSJSONSerialization 
#define                            NSTV   NSTableView 
#define                            NSMA   NSMutableArray 
#define                            NSVC   NSViewController 
#define                            NSEM   NSEventMask 
#define                            NSOP   NSOperation 
#define                            NSIS   NSIndexSet 
#define                            NSAS   NSAttributedString 
#define                            NSTA   NSTrackingArea 
#define                            NSOQ   NSOperationQueue 
#define                            NSAT   NSAffineTransform 
#define                            NSCL   NSColorList 
#define                            NSMO   NSManagedObject 
#define                            NSMD   NSMutableDictionary 
#define                            NSED   NSEntityDescription 
#define                            NSTC   NSTableColumn 
#define                            NSPI   NSProgressIndicator 
#define                            NSIV   NSImageView 
#define                            NSDO   NSDragOperation 
#define                            NSSZ   NSSize 
#define                            NSDE   NSDirectoryEnumerator 
#define                            NSFH   NSFileHandle 
#define                           NSPSC   NSPersistentStoreCoordinator 
#define                           NSINV   NSInvocation 
#define                           NSIMG   NSImage 
#define                           NSBIR   NSBitmapImageRep 
#define                           NSNOT   NSNotification 
#define                           NSMOM   NSManagedObjectModel 
#define                           NSBSB   NSBackingStoreBuffered 
#define                           NSCSV   NSCellStateValue 
#define                           NSERR   NSError 
#define                           NSMOC   NSManagedObjectContext 
#define                           NSMAS   NSMutableAttributedString 
#define                           NSMPS   NSMutableParagraphStyle 
#define                           NSBLO   NSBlockOperation 
#define                           NSTSK   NSTask 
#define                           NSBWM   NSBorderlessWindowMask 
#define                           NSRNG   NSRange 
#define                           NSMIS   NSMutableIndexSet 
#define                           NSAPP   NSApplication 
#define                           NSVAL   NSValue 
#define                          NSTXTV   NSTextView 
#define                          NSTABV   NSTabView 
#define                          NSMSet   NSMutableSet 
#define                          NSURLC   NSURLConnection 
#define                          NSTVDO   NSTableViewDropOperation 
#define                          NSSHDW   NSShadow 
#define                          NSTXTF   NSTextField 
#define                          NSSEGC   NSSegmentedControl 
#define                          NSTBAR   NSToolbar 
#define                          NSBUTT   NSButton 
#define                         AZOQMAX   NSOperationQueueDefaultMaxConcurrentOperationCount 
#define                         NSMenuI   NSMenuItem 
#define                         NSRFill   NSRectFill 
#define                         NSSCRLV   NSScrollView 
#define                         NSCOMPR   NSComparisonResult 
#define                         NSMDATA   NSMutableData 
#define                         NSBRWSR   NSBrowser 
#define                         ISADICT   isKindOfClass:NSDictionary.class 
#define                         NSSPLTV   NSSplitView 
#define                        NSSCLASS   NSString.class 
#define                        NSACLASS   NSArray.class 
#define                        NSURLREQ   NSURLRequest 
#define                        NSPUBUTT   NSPopUpButton 
#define                        NSDCLASS   NSDictionary.class 
#define                        NSURLRES   NSURLResponse 
#define                       NSPInRect   NSPointInRect 
#define                       NSMURLREQ   NSMutableURLRequest 
#define                       ISANARRAY   isKindOfClass:NSArray.class 
#define                     NSAorDCLASS   @[NSArray.class, NSDictionary.class] 
#define                  ISADICTorARRAY   isKindOfAnyClass:NSAorDCLASS 


#pragma mark - END DEFINES.NS PROBLEMS: 

@Kind(_ObjC_Load) ￭

#endif //  _ObjC__
#endif // __ObjC__

