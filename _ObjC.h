
/*! @note This is an AUTOMATICALLY generated file!
    Built on Apr 3, 2015, 6:35:59 AM from /Volumes/2T/ServiceData/AtoZ.framework/AtoZUniversal/_ObjC/_ObjC.plist */

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

#define                          NSApp UIApp 
#define                          NSNib UINib 
#define                         NSRect CGRect 
#define                         NSFont UIFont 
#define                         NSSize CGSize 
#define                         NSView UIView 
#define                        NSPoint CGPoint 
#define                        NSImage UIImage 
#define                        NSEvent UIEvent 
#define                        NSColor UIColor 
#define                       NSScreen UIScreen 
#define                       NSWindow UIWindow 
#define                     NSZeroRect CGRectZero 
#define                     NSZeroSize CGSizeZero 
#define                    NSZeroPoint CGPointZero 
#define                    NSTableView UITableView 
#define                   NSBezierPath UIBezierPath 
#define                  NSApplication UIApplication 
#define             NSUserNotification UILocalNotification 




#endif // Per-Platform Imports


#pragma mark - primitives 

_Type                           BOOL _IsIt _
_Type                          Class _Meta _
_Type                             id _ObjC _
_Type                           long _Long _
_Type             NSComparisonResult _Comp _
_Type                      NSInteger _SInt _
_Type                     NSUInteger _UInt _
_Type                            SEL _Meth _
_Type                  unsigned long _ULng _
_Type                           void _Void _

#define                  _IsIt_ (_IsIt)
#define                  _Meta_ (_Meta)
#define                  _ObjC_ (_ObjC)
#define                  _Long_ (_Long)
#define                  _Comp_ (_Comp)
#define                  _SInt_ (_SInt)
#define                  _UInt_ (_UInt)
#define                  _Meth_ (_Meth)
#define                  _ULng_ (_ULng)
#define                  _Void_ (_Void)



#pragma mark - structs 

_Type              CGAffineTransform _AffT _
_Type                        CGFloat _Flot _
_Type                        CGPoint _Cord _
_Type                         CGRect _Rect _
_Type                         CGSize _Size _
_Type                        NSRange _Rnge _

#define                  _AffT_ (_AffT)
#define                  _Flot_ (_Flot)
#define                  _Cord_ (_Cord)
#define                  _Rect_ (_Rect)
#define                  _Size_ (_Size)
#define                  _Rnge_ (_Rnge)



#pragma mark - pointers (MAC_ONLY)

#if MAC_ONLY

_Type            NSArrayController * _LstX _
_Type                  NSImageView * _PicV _
_Type                       NSMenu * _Menu _
_Type                   NSMenuItem * _SubM _
_Type                NSOutlineView * _OutV _
_Type                 NSScrollView * _Scrl _
_Type                  NSSplitView * _Splt _
_Type                NSTableColumn * _TCol _
_Type                       NSTask * _Task _
_Type                      WebView * _WebV _

#define                       LstX  NSArrayController
#define                       PicV  NSImageView
#define                       Menu  NSMenu
#define                       SubM  NSMenuItem
#define                       OutV  NSOutlineView
#define                       Scrl  NSScrollView
#define                       Splt  NSSplitView
#define                       TCol  NSTableColumn
#define                       Task  NSTask
#define                       WebV  WebView
#define                  _LstX_ (_LstX)
#define                  _PicV_ (_PicV)
#define                  _Menu_ (_Menu)
#define                  _SubM_ (_SubM)
#define                  _OutV_ (_OutV)
#define                  _Scrl_ (_Scrl)
#define                  _Splt_ (_Splt)
#define                  _TCol_ (_TCol)
#define                  _Task_ (_Task)
#define                  _WebV_ (_WebV)



#endif // MAC_ONLY

#pragma mark - pointers 

_Type                AVAudioPlayer * _SndP _
_Type                      CALayer * _Layr _
_Type                         char * _Char _
_Type                   const char * _CChr _
_Type                NSApplication * _Appl _
_Type                      NSArray * _List _
_Type                 NSBezierPath * _Path _
_Type                     NSBundle * _Bndl _
_Type                      NSColor * _Colr _
_Type                       NSData * _Data _
_Type                 NSDictionary * _Dict _
_Type                      NSError * _Errr _
_Type                      NSEvent * _Evnt _
_Type                 NSFileHandle * _File _
_Type                       NSFont * _Font _
_Type                      NSImage * _Pict _
_Type               NSMutableArray * mList _
_Type                NSMutableData * mData _
_Type          NSMutableDictionary * mDict _
_Type      NSMutableParagraphStyle * mPStl _
_Type              NSMutableString * mText _
_Type               NSNotification * _Note _
_Type                     NSNumber * _Numb _
_Type                     NSObject * _NObj _
_Type             NSParagraphStyle * _PStl _
_Type                       NSPipe * _Pipe _
_Type                     NSString * _Text _
_Type                  NSTableView * _TblV _
_Type                        NSURL * _NUrl _
_Type               NSUserDefaults * _Defs _
_Type                       NSView * _View _
_Type                     NSWindow * _Wind _
_Type                unsigned char * _UChr _

#define                       SndP  AVAudioPlayer
#define                       Layr  CALayer
#define                       Char  char
#define                       CChr  const char
#define                       Appl  NSApplication
#define                       List  NSArray
#define                       Path  NSBezierPath
#define                       Bndl  NSBundle
#define                       Colr  NSColor
#define                       Data  NSData
#define                       Dict  NSDictionary
#define                       Errr  NSError
#define                       Evnt  NSEvent
#define                       File  NSFileHandle
#define                       Font  NSFont
#define                       Pict  NSImage
#define                      ListM  NSMutableArray
#define                      DataM  NSMutableData
#define                      DictM  NSMutableDictionary
#define                      PStlM  NSMutableParagraphStyle
#define                      TextM  NSMutableString
#define                       Note  NSNotification
#define                       Numb  NSNumber
#define                       NObj  NSObject
#define                       PStl  NSParagraphStyle
#define                       Pipe  NSPipe
#define                       Text  NSString
#define                       TblV  NSTableView
#define                       NUrl  NSURL
#define                       Defs  NSUserDefaults
#define                       View  NSView
#define                       Wind  NSWindow
#define                       UChr  unsigned char
#define                  _SndP_ (_SndP)
#define                  _Layr_ (_Layr)
#define                  _Char_ (_Char)
#define                  _CChr_ (_CChr)
#define                  _Appl_ (_Appl)
#define                  _List_ (_List)
#define                  _Path_ (_Path)
#define                  _Bndl_ (_Bndl)
#define                  _Colr_ (_Colr)
#define                  _Data_ (_Data)
#define                  _Dict_ (_Dict)
#define                  _Errr_ (_Errr)
#define                  _Evnt_ (_Evnt)
#define                  _File_ (_File)
#define                  _Font_ (_Font)
#define                  _Pict_ (_Pict)
#define                  mList_ (mList)
#define                  mData_ (mData)
#define                  mDict_ (mDict)
#define                  mPStl_ (mPStl)
#define                  mText_ (mText)
#define                  _Note_ (_Note)
#define                  _Numb_ (_Numb)
#define                  _NObj_ (_NObj)
#define                  _PStl_ (_PStl)
#define                  _Pipe_ (_Pipe)
#define                  _Text_ (_Text)
#define                  _TblV_ (_TblV)
#define                  _NUrl_ (_NUrl)
#define                  _Defs_ (_Defs)
#define                  _View_ (_View)
#define                  _Wind_ (_Wind)
#define                  _UChr_ (_UChr)



/*! Good to make shortcuts for ALL  types as method arguments,
    with a leading Underscore to use ase parenthesis-free method parameterts! */

/// For ObjC classes, let's define a preprocessor Macro to call the direct Classes, without the _.


/*! Kind - Interface (Prototypes, Public, Name, etc)
    Vows - Protocol  (Promises, etc)
    Plan - Implemenation
    Xtra - Categories                                      */


#define                           Vows protocol 
#define                           Plan implementation 
#define                          _FINI @end 
#define                          _IMPT @import 
#define                          _Kind @interface 
#define                          _IFCE @interface 
#define                          _PRTO @protocol 
#define                          _IMPL @implementation 
#define                         _Kind_ (instancetype) /// Sugar for (instancetype) methods. 
#define                         P(...) id<__VA_ARGS__> 
#define                       NEW(A,B) A *B = A.new 
#define                     XCTUp(...) - (void) setUp { [super setUp]; ({ __VA_ARGS__; }); } 
#define                    _Cat(K,...) @interface K (Sans) __VA_ARGS__; @end 
#define                   _Test(X,...) - (void) test##X { ({ __VA_ARGS__; }); } 
#define                   INIT_(K,...) [[K alloc] init##__VA_ARGS__] 
#define                   XCTDown(...) - (void) tearDown { ({ __VA_ARGS__; }); [super tearDown]; } 
#define                  XtraStop(...) Stop 
#define                 Kind(Name,...) Kind_(Name,NObj,__VA_ARGS__) 
#define                _Case(Name,...) @Incl XCTest; @Kind_ (Name,XCTestCase)  ￭ @Plan Name XCTUp(__VA_ARGS__) 
#define               INTERFACE(X,...) @interface X : __VA_ARGS__ + (instancetype) 
#define            Xtra(Extends,Named) interface Extends      (Named) 
#define           Kind_(Name,Meta,...) interface Name : Meta __VA_ARGS__ 
#define        XtraPlan(Extends,Named) implementation Extends (Named) 




#define                             _S static 
#define                             _C const 
#define                             dV doubleValue 
#define                             pV pointValue 
#define                             _U unsigned 
#define                             _E extern 
#define                             bV boolValue 
#define                             fV floatValue 
#define                             _I inline 
#define                             iV integerValue 
#define                             mC mutableCopy 
#define                             rV rectValue 
#define                            vFK valueForKey 
#define                            oFK objectForKey 
#define                            uIV unsignedIntegerValue 
#define                            bFK boolForKey 
#define                           vFKP valueForKeyPath 
#define                           rngV rangeValue 
#define                           strV stringValue 
#define                          mAVFK mutableArrayValueForKey 




// GEOMETRY TRANSLATIONS

#if IOS_ONLY // $@

#define                      rectValue CGRectValue 
#define                     NSMakeRect CGRectMake 
#define                     NSMakeSize CGSizeMake 
#define                     pointValue CGPointValue 
#define                    NSMakePoint CGPointMake 
#define                   NSEqualRects CGRectEqualToRect 
#define                   NSEqualSizes CGSizeEqualToSize 
#define                  NSEqualPoints CGPointEqualToPoint 
#define             NSPointInRect(P,R) CGRectContainsPoint(R,P) 




#endif // IOS_ONLY

#endif // _ObjC__
#endif // __ObjC__

