
/*!       @note This file is AUTO_GENERATED! Changes will NOT persist!
                Built on Apr 9, 2015, 7:42:27 AM from template:_ObjC.plist with data from:_ObjC_Template.h */

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


/// Let's standarize the preprocessor names too!

@import ObjectiveC ___
 @class AVAudioPlayer,
        WebView ___
#    if MAC_ONLY
@import Cocoa ___
#  elif IOS_ONLY
@import UIKit ___

// Standarize names 1:1 between platforms. (DEFINES.STANDARD_NAMES)

#pragma mark - STANDARD_NAMES

#define                          NSApp  UIApp 
#define                          NSNib  UINib 
#define                         NSRect  CGRect 
#define                         NSFont  UIFont 
#define                         NSSize  CGSize 
#define                         NSView  UIView 
#define                        NSPoint  CGPoint 
#define                        NSImage  UIImage 
#define                        NSEvent  UIEvent 
#define                        NSColor  UIColor 
#define                       NSScreen  UIScreen 
#define                       NSWindow  UIWindow 
#define                     NSZeroRect  CGRectZero 
#define                     NSZeroSize  CGSizeZero 
#define                    NSZeroPoint  CGPointZero 
#define                    NSTableView  UITableView 
#define                   NSBezierPath  UIBezierPath 
#define                  NSApplication  UIApplication 
#define             NSUserNotification  UILocalNotification 


#endif // Per-Platform Imports (DEFINES.STANDARD_NAMES)

#pragma mark - PRIMITIVES

_Type                             id  _ObjC ___
_Type                            SEL  _Meth ___
_Type                           void  _Void ___
_Type                           BOOL  _IsIt ___
_Type                           long  _Long ___
_Type                          Class  _Meta ___
_Type                      NSInteger  _SInt ___
_Type                     NSUInteger  _UInt ___
_Type                  unsigned long  _ULng ___
_Type             NSComparisonResult  _Comp ___


#define                      _ObjC_  (_ObjC)
#define                     __ObjC_ : _ObjC_
#define                      _Meth_  (_Meth)
#define                     __Meth_ : _Meth_
#define                      _Void_  (_Void)
#define                     __Void_ : _Void_
#define                      _IsIt_  (_IsIt)
#define                     __IsIt_ : _IsIt_
#define                      _Long_  (_Long)
#define                     __Long_ : _Long_
#define                      _Meta_  (_Meta)
#define                     __Meta_ : _Meta_
#define                      _SInt_  (_SInt)
#define                     __SInt_ : _SInt_
#define                      _UInt_  (_UInt)
#define                     __UInt_ : _UInt_
#define                      _ULng_  (_ULng)
#define                     __ULng_ : _ULng_
#define                      _Comp_  (_Comp)
#define                     __Comp_ : _Comp_


#pragma mark - STRUCTS

_Type              CGAffineTransform  _AffT ___
_Type                        CGFloat  _Flot ___
_Type                        CGPoint  _Cord ___
_Type                         CGRect  _Rect ___
_Type                         CGSize  _Size ___
_Type                        NSRange  _Rnge ___


#define                      _AffT_  (_AffT)
#define                     __AffT_ : _AffT_
#define                      _Flot_  (_Flot)
#define                     __Flot_ : _Flot_
#define                      _Cord_  (_Cord)
#define                     __Cord_ : _Cord_
#define                      _Rect_  (_Rect)
#define                     __Rect_ : _Rect_
#define                      _Size_  (_Size)
#define                     __Size_ : _Size_
#define                      _Rnge_  (_Rnge)
#define                     __Rnge_ : _Rnge_


#if MAC_ONLY

#pragma mark - POINTERS_MAC

_Type            NSArrayController * xList ___
_Type                  NSImageView * _PicV ___
_Type                       NSMenu * _Menu ___
_Type                   NSMenuItem * _SubM ___
_Type                NSOutlineView * _OutV ___
_Type                 NSScrollView * _Scrl ___
_Type                  NSSplitView * _Splt ___
_Type                NSTableColumn * _TCol ___
_Type                       NSTask * _Task ___
_Type                      WebView * _WebV ___

#define                       ListX  NSArrayController
#define                        PicV  NSImageView
#define                        Menu  NSMenu
#define                        SubM  NSMenuItem
#define                        OutV  NSOutlineView
#define                        Scrl  NSScrollView
#define                        Splt  NSSplitView
#define                        TCol  NSTableColumn
#define                        Task  NSTask
#define                        WebV  WebView

#define                      xList_  (xList)
#define                     _xList_ : xList_
#define                      _PicV_  (_PicV)
#define                     __PicV_ : _PicV_
#define                      _Menu_  (_Menu)
#define                     __Menu_ : _Menu_
#define                      _SubM_  (_SubM)
#define                     __SubM_ : _SubM_
#define                      _OutV_  (_OutV)
#define                     __OutV_ : _OutV_
#define                      _Scrl_  (_Scrl)
#define                     __Scrl_ : _Scrl_
#define                      _Splt_  (_Splt)
#define                     __Splt_ : _Splt_
#define                      _TCol_  (_TCol)
#define                     __TCol_ : _TCol_
#define                      _Task_  (_Task)
#define                     __Task_ : _Task_
#define                      _WebV_  (_WebV)
#define                     __WebV_ : _WebV_


#endif // MAC_ONLY

#pragma mark - POINTERS

_Type                AVAudioPlayer * _SndP ___
_Type                      CALayer * _Layr ___
_Type                         char * _Char ___
_Type                   const char * _CChr ___
_Type                NSApplication * _Appl ___
_Type                      NSArray * _List ___
_Type                 NSBezierPath * _Path ___
_Type                     NSBundle * _Bndl ___
_Type                      NSColor * _Colr ___
_Type                       NSData * _Data ___
_Type                 NSDictionary * _Dict ___
_Type                      NSError * _Errr ___
_Type                      NSEvent * _Evnt ___
_Type                 NSFileHandle * _File ___
_Type                       NSFont * _Font ___
_Type                      NSImage * _Pict ___
_Type               NSMutableArray * mList ___
_Type                NSMutableData * mData ___
_Type          NSMutableDictionary * mDict ___
_Type      NSMutableParagraphStyle * mPStl ___
_Type              NSMutableString * mText ___
_Type               NSNotification * _Note ___
_Type                     NSNumber * _Numb ___
_Type                     NSObject * _NObj ___
_Type             NSParagraphStyle * _PStl ___
_Type                       NSPipe * _Pipe ___
_Type                     NSString * _Text ___
_Type                  NSTableView * _TblV ___
_Type                        NSURL * _NUrl ___
_Type               NSUserDefaults * _Defs ___
_Type                       NSView * _View ___
_Type                     NSWindow * _Wind ___
_Type                unsigned char * _UChr ___

#define                        SndP  AVAudioPlayer
#define                        Layr  CALayer
#define                        Char  char
#define                        CChr  const char
#define                        Appl  NSApplication
#define                        List  NSArray
#define                        Path  NSBezierPath
#define                        Bndl  NSBundle
#define                        Colr  NSColor
#define                        Data  NSData
#define                        Dict  NSDictionary
#define                        Errr  NSError
#define                        Evnt  NSEvent
#define                        File  NSFileHandle
#define                        Font  NSFont
#define                        Pict  NSImage
#define                       ListM  NSMutableArray
#define                       DataM  NSMutableData
#define                       DictM  NSMutableDictionary
#define                       PStlM  NSMutableParagraphStyle
#define                       TextM  NSMutableString
#define                        Note  NSNotification
#define                        Numb  NSNumber
#define                        NObj  NSObject
#define                        PStl  NSParagraphStyle
#define                        Pipe  NSPipe
#define                        Text  NSString
#define                        TblV  NSTableView
#define                        NUrl  NSURL
#define                        Defs  NSUserDefaults
#define                        View  NSView
#define                        Wind  NSWindow
#define                        UChr  unsigned char

#define                      _SndP_  (_SndP)
#define                     __SndP_ : _SndP_
#define                      _Layr_  (_Layr)
#define                     __Layr_ : _Layr_
#define                      _Char_  (_Char)
#define                     __Char_ : _Char_
#define                      _CChr_  (_CChr)
#define                     __CChr_ : _CChr_
#define                      _Appl_  (_Appl)
#define                     __Appl_ : _Appl_
#define                      _List_  (_List)
#define                     __List_ : _List_
#define                      _Path_  (_Path)
#define                     __Path_ : _Path_
#define                      _Bndl_  (_Bndl)
#define                     __Bndl_ : _Bndl_
#define                      _Colr_  (_Colr)
#define                     __Colr_ : _Colr_
#define                      _Data_  (_Data)
#define                     __Data_ : _Data_
#define                      _Dict_  (_Dict)
#define                     __Dict_ : _Dict_
#define                      _Errr_  (_Errr)
#define                     __Errr_ : _Errr_
#define                      _Evnt_  (_Evnt)
#define                     __Evnt_ : _Evnt_
#define                      _File_  (_File)
#define                     __File_ : _File_
#define                      _Font_  (_Font)
#define                     __Font_ : _Font_
#define                      _Pict_  (_Pict)
#define                     __Pict_ : _Pict_
#define                      mList_  (mList)
#define                     _mList_ : mList_
#define                      mData_  (mData)
#define                     _mData_ : mData_
#define                      mDict_  (mDict)
#define                     _mDict_ : mDict_
#define                      mPStl_  (mPStl)
#define                     _mPStl_ : mPStl_
#define                      mText_  (mText)
#define                     _mText_ : mText_
#define                      _Note_  (_Note)
#define                     __Note_ : _Note_
#define                      _Numb_  (_Numb)
#define                     __Numb_ : _Numb_
#define                      _NObj_  (_NObj)
#define                     __NObj_ : _NObj_
#define                      _PStl_  (_PStl)
#define                     __PStl_ : _PStl_
#define                      _Pipe_  (_Pipe)
#define                     __Pipe_ : _Pipe_
#define                      _Text_  (_Text)
#define                     __Text_ : _Text_
#define                      _TblV_  (_TblV)
#define                     __TblV_ : _TblV_
#define                      _NUrl_  (_NUrl)
#define                     __NUrl_ : _NUrl_
#define                      _Defs_  (_Defs)
#define                     __Defs_ : _Defs_
#define                      _View_  (_View)
#define                     __View_ : _View_
#define                      _Wind_  (_Wind)
#define                     __Wind_ : _Wind_
#define                      _UChr_  (_UChr)
#define                     __UChr_ : _UChr_


/*! Good to make shortcuts for ALL  types as method arguments,
    with a leading Underscore to use ase parenthesis-free method parameterts! */

/// For ObjC classes, let's define a preprocessor Macro to call the direct Classes, without the _.


/*! Kind - Interface (Prototypes, Public, Name, etc)
    Vows - Protocol  (Promises, etc)
    Plan - Implemenation
    Xtra - Categories                                      */

#pragma mark - MISC

#define                _Case(Name,...)  @Incl XCTest; @Kind_ (Name,XCTestCase)  ￭ @Plan Name XCTUp(__VA_ARGS__) 
#define                    _Cat(K,...)  @interface K (Sans) __VA_ARGS__; @end 
#define                          _FINI  @end 
#define                          _IFCE  @interface 
#define                          _IMPL  @implementation 
#define                          _IMPT  @import 
#define                          _Kind  @interface 
#define                         _Kind_  (instancetype) /// Sugar for (instancetype) methods. 
#define                          _PRTO  @protocol 
#define                   _Test(X,...)  - (void) test##X { ({ __VA_ARGS__; }); } 
#define                   INIT_(K,...)  [[K alloc] init##__VA_ARGS__] 
#define                 INIT_THEN(...)  SUPERINIT; ({ __VA_ARGS__ }); return self; 
#define               INTERFACE(X,...)  @interface X : __VA_ARGS__ + (instancetype) 
#define                 Kind(Name,...)  Kind_(Name,NObj,__VA_ARGS__) 
#define           Kind_(Name,Meta,...)  interface Name : Meta __VA_ARGS__ 
#define                       NEW(A,B)  A *B = A.new 
#define                         P(...)  id<__VA_ARGS__> 
#define                           Plan  implementation 
#define                           Vows  protocol 
#define                   XCTDown(...)  - (void) tearDown { ({ __VA_ARGS__; }); [super tearDown]; } 
#define                     XCTUp(...)  - (void) setUp { [super setUp]; ({ __VA_ARGS__; }); } 
#define            Xtra(Extends,Named)  interface Extends      (Named) 
#define        XtraPlan(Extends,Named)  implementation Extends (Named) 
#define                  XtraStop(...)  Stop 


#pragma mark - ABBREVIATIONS

#define                            _AS  @property (AS) 
#define                            _AT  @property 
#define                            _CP  @property (CP) 
#define                            _FM  NSFileManager.defaultManager 
#define                            _NA  @property (NA) 
#define                            _NC  @property (NA,CP) 
#define                            _PI  NSProcessInfo.processInfo 
#define                            _RC  @property (RO,CP) 
#define                            _RO  @property (RO) 
#define                            _VD  - _Void_  
#define                            _WK  @property (WK) 
#define                            ASS  assign 
#define                            bFK  boolForKey 
#define                             bV  boolValue 
#define                             CP  copy 
#define                             dV  doubleValue 
#define                             fV  floatValue 
#define                             iV  integerValue 
#define                          mAVFK  mutableArrayValueForKey 
#define                             mC  mutableCopy 
#define                             NA  nonatomic 
#define                            oFK  objectForKey 
#define                             pV  pointValue 
#define                           rngV  rangeValue 
#define                             RO  readonly 
#define                             rV  rectValue 
#define                             RW  readwrite 
#define                            STR  strong 
#define                           strV  stringValue 
#define                            uIV  unsignedIntegerValue 
#define                           UNSF  unsafe_unretained 
#define                            vFK  valueForKey 
#define                           vFKP  valueForKeyPath 
#define                             WK  weak 


#if IOS_ONLY //

#pragma mark - GEOMETRY_TRANSLATIONS

#define                      rectValue  CGRectValue 
#define                     NSMakeRect  CGRectMake 
#define                     NSMakeSize  CGSizeMake 
#define                     pointValue  CGPointValue 
#define                    NSMakePoint  CGPointMake 
#define                   NSEqualRects  CGRectEqualToRect 
#define                   NSEqualSizes  CGSizeEqualToSize 
#define                  NSEqualPoints  CGPointEqualToPoint 
#define             NSPointInRect(P,R)  CGRectContainsPoint(R,P) 


#endif // IOS_ONLY/GEOMETRY

@Kind(_ObjC_Load) ￭

#endif //  _ObjC__
#endif // __ObjC__

