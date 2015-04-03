
/*! @note This is an AUTOMATICALLY generated file!
    Built on Apr 3, 2015, 12:50:32 AM from /Volumes/2T/ServiceData/AtoZ.framework/AtoZUniversal/_ObjC/_ObjC.plist */

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

/// Let's standarize the preprocessor names too!

@import ObjectiveC _
 @class AVAudioPlayer,
        WebView _
#    if MAC_ONLY
@import Cocoa _
#  elif IOS_ONLY
@import UIKit _


// Standarize names 1:1 between platforms.


#define                        NSPoint CGPoint
#define                    NSZeroPoint CGPointZero
#define                         NSRect CGRect
#define                     NSZeroRect CGRectZero
#define                         NSSize CGSize
#define                     NSZeroSize CGSizeZero
#define                          NSApp UIApp
#define                  NSApplication UIApplication
#define                   NSBezierPath UIBezierPath
#define                        NSColor UIColor
#define                        NSEvent UIEvent
#define                         NSFont UIFont
#define                        NSImage UIImage
#define             NSUserNotification UILocalNotification
#define                          NSNib UINib
#define                       NSScreen UIScreen
#define                    NSTableView UITableView
#define                         NSView UIView
#define                       NSWindow UIWindow


#endif // Per-Platform Imports

#pragma mark - primitives 

////////////
// VAGEEN //
////////////
_Type             NSComparisonResult  _Comp _
_Type                           BOOL  _IsIt _
_Type                           long  _Long _
_Type                          Class  _Meta _
_Type                            SEL  _Meth _
_Type                             id  _ObjC _
_Type                      NSInteger  _SInt _
_Type                     NSUInteger  _UInt _
_Type                  unsigned long  _ULng _
_Type                           void  _Void _


#pragma mark - structs 

////////////
// VAGEEN //
////////////
_Type              CGAffineTransform  _AffT _
_Type                        CGPoint  _Cord _
_Type                        CGFloat  _Flot _
_Type                         CGRect  _Rect _
_Type                        NSRange  _Rnge _
_Type                         CGSize  _Size _


#if MAC_ONLY // $@

#pragma mark - pointers_MAC_ONLY 

////////////
// VAGEEN //
////////////
_Type            NSArrayController *  _LstX _
_Type                       NSMenu *  _Menu _
_Type                NSOutlineView *  _OutV _
_Type                  NSImageView *  _PicV _
_Type                 NSScrollView *  _Scrl _
_Type                  NSSplitView *  _Splt _
_Type                   NSMenuItem *  _SubM _
_Type                NSTableColumn *  _TCol _
_Type                       NSTask *  _Task _
_Type                      WebView *  _WebV _

#endif // MAC_ONLY

#pragma mark - pointers 

////////////
// VAGEEN //
////////////
_Type                NSApplication *  _Appl _
_Type                     NSBundle *  _Bndl _
_Type                   const char *  _CChr _
_Type                         char *  _Char _
_Type                      NSColor *  _Colr _
_Type                       NSData *  _Data _
_Type               NSUserDefaults *  _Defs _
_Type                 NSDictionary *  _Dict _
_Type                      NSError *  _Errr _
_Type                      NSEvent *  _Evnt _
_Type                 NSFileHandle *  _File _
_Type                       NSFont *  _Font _
_Type                      CALayer *  _Layr _
_Type                      NSArray *  _List _
_Type                     NSObject *  _NObj _
_Type                        NSURL *  _NUrl _
_Type               NSNotification *  _Note _
_Type                     NSNumber *  _Numb _
_Type             NSParagraphStyle *  _PStl _
_Type                 NSBezierPath *  _Path _
_Type                      NSImage *  _Pict _
_Type                       NSPipe *  _Pipe _
_Type                AVAudioPlayer *  _SndP _
_Type                  NSTableView *  _TblV _
_Type                     NSString *  _Text _
_Type                unsigned char *  _UChr _
_Type                       NSView *  _View _
_Type                     NSWindow *  _Wind _
_Type                NSMutableData *  mData _
_Type          NSMutableDictionary *  mDict _
_Type               NSMutableArray *  mList _
_Type      NSMutableParagraphStyle *  mPStl _
_Type              NSMutableString *  mText _


#define           _AffT_  (_AffT)
#define           _Appl_  (_Appl)
#define           _Bndl_  (_Bndl)
#define           _CChr_  (_CChr)
#define           _Char_  (_Char)
#define           _Colr_  (_Colr)
#define           _Comp_  (_Comp)
#define           _Cord_  (_Cord)
#define           _Data_  (_Data)
#define           _Defs_  (_Defs)
#define           _Dict_  (_Dict)
#define           _Errr_  (_Errr)
#define           _Evnt_  (_Evnt)
#define           _File_  (_File)
#define           _Flot_  (_Flot)
#define           _Font_  (_Font)
#define           _IsIt_  (_IsIt)
#define           _Layr_  (_Layr)
#define           _List_  (_List)
#define           _Long_  (_Long)
#define           _LstX_  (_LstX)
#define           _Menu_  (_Menu)
#define           _Meta_  (_Meta)
#define           _Meth_  (_Meth)
#define           _NObj_  (_NObj)
#define           _NUrl_  (_NUrl)
#define           _Note_  (_Note)
#define           _Numb_  (_Numb)
#define           _ObjC_  (_ObjC)
#define           _OutV_  (_OutV)
#define           _PStl_  (_PStl)
#define           _Path_  (_Path)
#define           _PicV_  (_PicV)
#define           _Pict_  (_Pict)
#define           _Pipe_  (_Pipe)
#define           _Rect_  (_Rect)
#define           _Rnge_  (_Rnge)
#define           _SInt_  (_SInt)
#define           _Scrl_  (_Scrl)
#define           _Size_  (_Size)
#define           _SndP_  (_SndP)
#define           _Splt_  (_Splt)
#define           _SubM_  (_SubM)
#define           _TCol_  (_TCol)
#define           _Task_  (_Task)
#define           _TblV_  (_TblV)
#define           _Text_  (_Text)
#define           _UChr_  (_UChr)
#define           _UInt_  (_UInt)
#define           _ULng_  (_ULng)
#define           _View_  (_View)
#define           _Void_  (_Void)
#define           _WebV_  (_WebV)
#define           _Wind_  (_Wind)
#define           mData_  (mData)
#define           mDict_  (mDict)
#define           mList_  (mList)
#define           mPStl_  (mPStl)
#define           mText_  (mText)
/// Good to make shortcuts for ALL  types as method arguments
/// with a leading Underscore to use ase parenthesis-free method parameterts!



#define                           Appl  NSApplication
#define                           Bndl  NSBundle
#define                           Colr  NSColor
#define                           Data  NSData
#define                           Defs  NSUserDefaults
#define                           Dict  NSDictionary
#define                           Errr  NSError
#define                           Evnt  NSEvent
#define                           File  NSFileHandle
#define                           Font  NSFont
#define                           Layr  CALayer
#define                           List  NSArray
#define                           LstX  NSArrayController
#define                           Menu  NSMenu
#define                           NObj  NSObject
#define                           NUrl  NSURL
#define                           Note  NSNotification
#define                           Numb  NSNumber
#define                           OutV  NSOutlineView
#define                           PStl  NSParagraphStyle
#define                           Path  NSBezierPath
#define                           PicV  NSImageView
#define                           Pict  NSImage
#define                           Pipe  NSPipe
#define                           Scrl  NSScrollView
#define                           SndP  AVAudioPlayer
#define                           Splt  NSSplitView
#define                           SubM  NSMenuItem
#define                           TCol  NSTableColumn
#define                           Task  NSTask
#define                           TblV  NSTableView
#define                           Text  NSString
#define                           View  NSView
#define                           Wind  NSWindow
#define                          DataM  NSMutableData
#define                          DictM  NSMutableDictionary
#define                          ListM  NSMutableArray
#define                          PStlM  NSMutableParagraphStyle
#define                          TextM  NSMutableString
/// For ObjC classes, let's define a preprocessor Macro to call the direct Classes, without the _.


/*! Kind - Interface (Prototypes, Public, Name, etc)
    Vows - Protocol  (Promises, etc)
    Plan - Implemenation
    Xtra - Categories                                      */


#define                         _Kind_ (instancetype) /// Sugar for (instancetype) methods.
#define                     XCTUp(...) - (void) setUp { [super setUp]; ({ __VA_ARGS__; }); }
#define                   XCTDown(...) - (void) tearDown { ({ __VA_ARGS__; }); [super tearDown]; }
#define                   _Test(X,...) - (void) test##X { ({ __VA_ARGS__; }); }
#define                _Case(Name,...) @Incl XCTest; @Kind_ (Name,XCTestCase)  ￭ @Plan Name XCTUp(__VA_ARGS__)
#define                          _FINI @end
#define                          _IMPL @implementation
#define                          _IMPT @import
#define                          _Kind @interface
#define                          _IFCE @interface
#define                    _Cat(K,...) @interface K (Sans) __VA_ARGS__; @end
#define               INTERFACE(X,...) @interface X : __VA_ARGS__ + (instancetype)
#define                          _PRTO @protocol
#define                       NEW(A,B) A *B = A.new
#define                 Kind(Name,...) Kind_(Name,NObj,__VA_ARGS__)
#define                            Ôºø Plan
#define                  XtraStop(...) Stop
#define                   INIT_(K,...) [[K alloc] init##__VA_ARGS__]
#define                         P(...) id<__VA_ARGS__>
#define                           Plan implementation
#define        XtraPlan(Extends,Named) implementation Extends (Named)
#define            Xtra(Extends,Named) interface Extends      (Named)
#define           Kind_(Name,Meta,...) interface Name : Meta __VA_ARGS__
#define                           Vows protocol



#define                            bFK boolForKey
#define                             bV boolValue
#define                             _C const
#define                             dV doubleValue
#define                             _E extern
#define                             fV floatValue
#define                             _I inline
#define                             iV integerValue
#define                          mAVFK mutableArrayValueForKey
#define                             mC mutableCopy
#define                            oFK objectForKey
#define                             pV pointValue
#define                           rngV rangeValue
#define                             rV rectValue
#define                             _S static
#define                           strV stringValue
#define                             _U unsigned
#define                            uIV unsignedIntegerValue
#define                            vFK valueForKey
#define                           vFKP valueForKeyPath


// GEOMETRY TRANSLATIONS

#if IOS_ONLY // $@

#define                  NSEqualPoints CGPointEqualToPoint
#define                    NSMakePoint CGPointMake
#define                     pointValue CGPointValue
#define             NSPointInRect(P,R) CGRectContainsPoint(R,P)
#define                   NSEqualRects CGRectEqualToRect
#define                     NSMakeRect CGRectMake
#define                      rectValue CGRectValue
#define                   NSEqualSizes CGSizeEqualToSize
#define                     NSMakeSize CGSizeMake

#endif // IOS_ONLY

#endif // _ObjC__
#endif // __ObjC__

