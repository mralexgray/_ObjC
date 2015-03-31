
/*! @note This is an AUTOMATICALLY generated file!
    Built on Mar 31, 2015, 9:20:29 AM from /Volumes/2T/ServiceData/AtoZ.framework/AtoZUniversal/_ObjC/_ObjC.plist */


#ifdef   __OBJC__
#ifndef   _ObjC__
#define   _ObjC__
/*!   @abstract _ObjC is concise dialect of ObjC that is terse and compatible - without needless tricks.
    @discussion It strives to minimize excessive *'s, {}'s, and ()'s, and so on, and so forth.
                Class pointers and types are typedef'd to aliases, with no pointer,
                formatted like _Four lettes, starting with an underscore, capitalized. */


#define             IOS_ONLY  TARGET_OS_IPHONE
#define             MAC_ONLY  !IOS_ONLY
#define                    _  ;
#define                _Type  typedef
#define                   _C  const
#define                   _E  extern
#define                   _I  inline
#define                   _S  static
#define                   _U  unsigned


/// Let's standarize the preprocessor names too!


#define                 Reqd  required
#define                 Optn  optional
#define                 Incl  import
#define                 Stop  end
#define                       ￭ @Stop


@import ObjectiveC _
 @class WebView,

             AVAudioPlayer _
#    if MAC_ONLY
@import Cocoa _
#  elif IOS_ONLY
@import UIKit _


// Standarize names 1:1 between platforms.


#define                NSNib  UINib
#define                NSApp  UIApp
#define               NSFont  UIFont
#define               NSView  UIView
#define               NSRect  CGRect
#define               NSSize  CGSize
#define              NSImage  UIImage
#define              NSColor  UIColor
#define              NSPoint  CGPoint
#define              NSEvent  UIEvent
#define             NSScreen  UIScreen
#define             NSWindow  UIWindow
#define           NSZeroSize  CGSizeZero
#define           NSZeroRect  CGRectZero
#define          NSZeroPoint  CGPointZero
#define          NSTableView  UITableView
#define         NSBezierPath  UIBezierPath
#define        NSApplication  UIApplication
#define   NSUserNotification  UILocalNotification


#endif

#pragma mark - types 

_Type                             id  _ObjC _
_Type                            SEL  _Meth _
_Type                          Class  _Meta _
_Type                           void  _Void _
_Type                           BOOL  _IsIt _
_Type                  unsigned long  _ULng _
_Type                           long  _Long _
_Type                      NSInteger  _SInt _
_Type                     NSUInteger  _UInt _
_Type             NSComparisonResult  _Comp _


#pragma mark - structs 

_Type                         CGSize  _Size _
_Type                         CGRect  _Rect _
_Type                        CGFloat  _Flot _
_Type                        CGPoint  _Cord _
_Type                        NSRange  _Rnge _
_Type              CGAffineTransform  _AffT _


#if MAC_ONLY
#pragma mark - pointers_MAC_ONLY 

_Type                       NSTask *  _Task _
_Type                       NSMenu *  _Menu _
_Type                      WebView *  _WebV _
_Type                   NSMenuItem *  _SubM _
_Type                  NSImageView *  _PicV _
_Type                  NSSplitView *  _Splt _
_Type                 NSScrollView *  _Scrl _
_Type                NSOutlineView *  _OutV _
_Type                NSTableColumn *  _TCol _
_Type            NSArrayController *  _LstX _

#endif // MAC_ONLY

#pragma mark - pointers 

_Type                AVAudioPlayer *  _SndP _
_Type                      CALayer *  _Layr _
_Type                NSApplication *  _Appl _
_Type                      NSArray *  _List _
_Type               NSMutableArray *  mList _
_Type                 NSBezierPath *  _Path _
_Type                     NSBundle *  _Bndl _
_Type                      NSColor *  _Colr _
_Type                       NSData *  _Data _
_Type                NSMutableData *  mData _
_Type                 NSDictionary *  _Dict _
_Type          NSMutableDictionary *  mDict _
_Type                      NSError *  _Errr _
_Type                      NSEvent *  _Evnt _
_Type                 NSFileHandle *  _File _
_Type                       NSFont *  _Font _
_Type                      NSImage *  _Pict _
_Type               NSNotification *  _Note _
_Type                     NSNumber *  _Numb _
_Type                     NSObject *  _NObj _
_Type             NSParagraphStyle *  _PStl _
_Type      NSMutableParagraphStyle *  mPStl _
_Type                       NSPipe *  _Pipe _
_Type                     NSString *  _Text _
_Type              NSMutableString *  mText _
_Type                  NSTableView *  _TblV _
_Type                        NSURL *  _NUrl _
_Type               NSUserDefaults *  _Defs _
_Type                       NSView *  _View _
_Type                     NSWindow *  _Wind _
_Type                         char *  _Char _
_Type                   const char *  _CChr _
_Type                unsigned char *  _UChr _


/// Good to make "shortcuts" for ALL `_ObjC` types as "method arguments"
/// with a leading Underscore to use ase parenthesis-free method parameterts!

#define           _ObjC_  (_ObjC)
#define           _Meth_  (_Meth)
#define           _Meta_  (_Meta)
#define           _Void_  (_Void)
#define           _IsIt_  (_IsIt)
#define           _ULng_  (_ULng)
#define           _Long_  (_Long)
#define           _SInt_  (_SInt)
#define           _UInt_  (_UInt)
#define           _Comp_  (_Comp)
#define           _Size_  (_Size)
#define           _Rect_  (_Rect)
#define           _Flot_  (_Flot)
#define           _Cord_  (_Cord)
#define           _Rnge_  (_Rnge)
#define           _AffT_  (_AffT)
#define           _Task_  (_Task)
#define           _Menu_  (_Menu)
#define           _WebV_  (_WebV)
#define           _SubM_  (_SubM)
#define           _PicV_  (_PicV)
#define           _Splt_  (_Splt)
#define           _Scrl_  (_Scrl)
#define           _OutV_  (_OutV)
#define           _TCol_  (_TCol)
#define           _LstX_  (_LstX)
#define           _SndP_  (_SndP)
#define           _Layr_  (_Layr)
#define           _Appl_  (_Appl)
#define           _List_  (_List)
#define           mList_  (mList)
#define           _Path_  (_Path)
#define           _Bndl_  (_Bndl)
#define           _Colr_  (_Colr)
#define           _Data_  (_Data)
#define           mData_  (mData)
#define           _Dict_  (_Dict)
#define           mDict_  (mDict)
#define           _Errr_  (_Errr)
#define           _Evnt_  (_Evnt)
#define           _File_  (_File)
#define           _Font_  (_Font)
#define           _Pict_  (_Pict)
#define           _Note_  (_Note)
#define           _Numb_  (_Numb)
#define           _NObj_  (_NObj)
#define           _PStl_  (_PStl)
#define           mPStl_  (mPStl)
#define           _Pipe_  (_Pipe)
#define           _Text_  (_Text)
#define           mText_  (mText)
#define           _TblV_  (_TblV)
#define           _NUrl_  (_NUrl)
#define           _Defs_  (_Defs)
#define           _View_  (_View)
#define           _Wind_  (_Wind)
#define           _Char_  (_Char)
#define           _CChr_  (_CChr)
#define           _UChr_  (_UChr)

/// For ObjC classes, let's define a preprocessor Macro to call the direct Classes, without the _.

#define                           SInt  NSInteg
#define                           UInt  NSUInteg
#define                           Comp  NSComparisonResu
#define                           Rnge  NSRan
#define                           Task  NSTask
#define                           Menu  NSMenu
#define                           SubM  NSMenuItem
#define                           PicV  NSImageView
#define                           Splt  NSSplitView
#define                           Scrl  NSScrollView
#define                           OutV  NSOutlineView
#define                           TCol  NSTableColumn
#define                           LstX  NSArrayController
#define                           SndP  AVAudioPlayer
#define                           Layr  CALayer
#define                           Appl  NSApplication
#define                           List  NSArray
#define                           ListM  NSMutableArray
#define                           Path  NSBezierPath
#define                           Bndl  NSBundle
#define                           Colr  NSColor
#define                           Data  NSData
#define                           DataM  NSMutableData
#define                           Dict  NSDictionary
#define                           DictM  NSMutableDictionary
#define                           Errr  NSError
#define                           Evnt  NSEvent
#define                           File  NSFileHandle
#define                           Font  NSFont
#define                           Pict  NSImage
#define                           Note  NSNotification
#define                           Numb  NSNumber
#define                           NObj  NSObject
#define                           PStl  NSParagraphStyle
#define                           PStlM  NSMutableParagraphStyle
#define                           Pipe  NSPipe
#define                           Text  NSString
#define                           TextM  NSMutableString
#define                           TblV  NSTableView
#define                           NUrl  NSURL
#define                           Defs  NSUserDefaults
#define                           View  NSView
#define                           Wind  NSWindow

/*! Kind - Interface (Prototypes, Public, Name, etc)
    Vows - Protocol  (Promises, etc)
    Plan - Implemenation
    Xtra - Categories                                      */


#define                 Plan  implementation
#define                _Kind  @interface
#define Kind_(Name,Meta,...)  interface Name : Meta __VA_ARGS__
#define       Kind(Name,...)  Kind_(Name,NObj,__VA_ARGS__)
#define               _Kind_  (instancetype) /// Sugar for (instancetype) methods.
#define                 Vows  protocol
#define  Xtra(Extends,Named)  interface Extends      (Named)
#define          _Cat(K,...)  @interface K (Sans) __VA_ARGS__; @end
#define XtraPlan(Extends,Named)  implementation Extends (Named)
#define        XtraStop(...)  Stop
#define                _IMPL  @implementation
#define                _IFCE  @interface
#define                _PRTO  @protocol
#define                _IMPT  @import
#define                _FINI  @end
#define                       ＞(...) @Xtra(__VA_ARGS__)
#define                       ＜(...) @XtraPlan(__VA_ARGS__)
#define                       ＿ Plan
#define         _Test(X,...)  - (void) test##X { ({ __VA_ARGS__; }); }
#define           XCTUp(...)  - (void) setUp { [super setUp]; ({ __VA_ARGS__; }); }
#define         XCTDown(...)  - (void) tearDown { ({ __VA_ARGS__; }); [super tearDown]; }
#define      _Case(Name,...)  @Incl XCTest; @Kind_ (Name,XCTestCase)  ￭ @Plan Name XCTUp(__VA_ARGS__)
#define               P(...)  id<__VA_ARGS__>
#define     INTERFACE(X,...)  @interface X : __VA_ARGS__ + (instancetype)
#define         INIT_(K,...)  [[K alloc] init##__VA_ARGS__]
#define             NEW(A,B)  A *B = A.new



#define                  oFK  objectForKey
#define                  vFK  valueForKey
#define                 vFKP  valueForKeyPath
#define                   mC  mutableCopy
#define                mAVFK  mutableArrayValueForKey
#define                  bFK  boolForKey
#define                   bV  boolValue
#define                   dV  doubleValue
#define                   fV  floatValue
#define                   iV  integerValue
#define                  uIV  unsignedIntegerValue
#define                 rngV  rangeValue
#define                 strV  stringValue
#define                   rV  rectValue
#define                   pV  pointValue


// GEOMETRY TRANSLATIONS

#if IOS_ONLY
#define            rectValue  CGRectValue
#define           pointValue  CGPointValue
#define           NSMakeSize  CGSizeMake
#define          NSMakePoint  CGPointMake
#define           NSMakeSize  CGSizeMake
#define           NSMakeRect  CGRectMake
#define         NSEqualSizes  CGSizeEqualToSize
#define        NSEqualPoints  CGPointEqualToPoint
#define         NSEqualRects  CGRectEqualToRect
#define   NSPointInRect(P,R)  CGRectContainsPoint(R,P)

#endif // IOS_ONLY

#endif // _ObjC__
#endif // __ObjC__
