
#ifdef  __OBJC__
#ifndef  _ObjC__
#define  _ObjC__

@import ObjectiveC;
#import <TargetConditionals.h>

#define IOS_ONLY TARGET_OS_IPHONE
#define MAC_ONLY !IOS_ONLY

#if       MAC_ONLY
  @import Cocoa;

#elif     IOS_ONLY
  @import UIKit;

  #define              NSNib UINib      /* Standarize names 1:1 between platforms. */
  #define             NSFont UIFont
  #define             NSView UIView
  #define             NSRect CGRect
  #define             NSSize CGSize
  #define            NSImage UIImage
  #define            NSColor UIColor
  #define            NSPoint CGPoint
  #define            NSEvent UIEvent
  #define           NSScreen UIScreen
  #define           NSWindow UIWindow
  #define         NSZeroSize CGSizeZero
  #define         NSZeroRect CGRectZero
  #define        NSZeroPoint CGPointZero
  #define NSUserNotification UILocalNotification

#endif // IOS_ONLY

// AtoZ is a terse dialect of ObjC that is more concise, yet 100% compatible. \
   It strives to minimize excessive *'s, {}'s, and ()'s. \
   Class pointers and types are typedef'd to aliases, with no pointer, \
   formatted like _Four lettes, starting with an underscore, capitalized.

#define _Type typedef /* TYPES */

_Type                 id   _ObjC;
_Type                SEL   _Meth;
_Type              Class   _Meta;
_Type               void   _Void;

_Type               BOOL   _IsIt;
_Type      unsigned long   _ULng;
_Type               long   _Long;
_Type          NSInteger   _SInt;
_Type         NSUInteger   _UInt;
_Type NSComparisonResult   _Comp;


                    /* STRUTS */
_Type             CGSize   _Size;
_Type             CGRect   _Rect;
_Type            CGFloat   _Flot;
_Type            CGPoint   _Cord;

                  /* POINTERS */

_Type              char * _Char;
_Type     unsigned char * _UChr;
_Type             NSURL * _NUrl;
_Type            NSView * _View;
_Type            NSData * _Data;
_Type            NSFont * _Font;
_Type           CALayer * _Layr;
_Type           NSArray * _List;
_Type           NSColor * _Colr;
_Type           NSError * _Errr;
_Type           NSEvent * _Evnt;
_Type           NSImage * _Pict;
_Type          NSBundle * _Bndl;
_Type          NSNumber * _Numb;
_Type          NSObject * _NObj;
_Type          NSString * _Text;
_Type          NSWindow * _Wind;
_Type      NSDictionary * _Dict;
_Type  NSParagraphStyle * _PStl;
_Type    NSNotification * _Note;

#if MAC_ONLY

  _Type            NSMenu * _Menu;
  _Type           WebView * _WebV;
  _Type        NSMenuItem * _SubM;
  _Type       NSImageView * _PicV;
  _Type       NSSplitView * _Splt;
  _Type       NSTableView * _TblV;
  _Type      NSScrollView * _Scrl;
  _Type     NSApplication * _Appl;
  _Type     NSOutlineView * _OutV;
  _Type     NSTableColumn * _TCol;
  _Type NSArrayController * _LstX;


  _Type _Void(^_MBlk)(_SubM menu);

#endif

// For ObjC classes, let's define a preprocessor Macro to call the direct Classes, without the _.

#define   Menu NSMenu
#define   Font NSFont
#define   View NSView
#define   Data NSData
#define   Colr NSColor
#define   Errr NSError
#define   Evnt NSEvent
#define   Layr CALayer
#define   List NSArray
#define   Pict NSImage
#define   Bndl NSBundle
#define   NObj NSObject
#define   NUrl NSURL
#define   Numb NSNumber
#define   Text NSString
#define   Wind NSWindow
#define   SubM NSMenuItem
#define   PicV NSImageView
#define   Splt NSSplitView
#define   TblV NSTableView
#define   Dict NSDictionary
#define   Scrl NSScrollView
#define   Appl NSApplication
#define   OutV NSOutlineView
#define   TCol NSTableColumn
#define   PStl NSParagraphStyle
#define   Note NSNotification

#define   Char char

/// Good to make "shortcuts" for ALL `_ObjC` types as "method arguments"
/// with a leading Underscore to use ase parenthesis-free method parameterts!

#define _Appl_ (_Appl)
#define _Bndl_ (_Bndl)
#define _Colr_ (_Colr)
#define _Comp_ (_Comp)
#define _Cord_ (_Cord)
#define _Data_ (_Data)
#define _Dict_ (_Dict)
#define _Errr_ (_Errr)
#define _Errr__ (_Errr*)
#define _Evnt_ (_Evnt)
#define _Flot_ (_Flot)
#define _Font_ (_Font)
#define _IsIt_ (_IsIt)
#define _Layr_ (_Layr)
#define _List_ (_List)
#define _LstX_ (_LstX)
#define _MBlk_ (_MBlk)
#define _Menu_ (_Menu)
#define _Meta_ (_Meta)
#define _Meth_ (_Meth)
#define _Note_ (_Note)
#define _Numb_ (_Numb)
#define _NObj_ (_NObj)
#define _NUrl_ (_NUrl)
#define _ObjC_ (_ObjC)
#define _OutV_ (_OutV)
#define _Pict_ (_Pict)
#define _PicV_ (_PicV)
#define _PStl_ (_PStl)
#define _Rect_ (_Rect)
#define _Scrl_ (_Scrl)
#define _SInt_ (_SInt)
#define _Size_ (_Size)
#define _Splt_ (_Splt)
#define _SubM_ (_SubM)
#define _TblV_ (_TblV)
#define _TCol_ (_TCol)
#define _Text_ (_Text)
#define _UInt_ (_UInt)
#define _View_ (_View)
#define _Void_ (_Void)
#define _WebV_ (_WebV)
#define _Wind_ (_Wind)

#define _Char_ (_Char)
#define _UChr_ (_UChr)
#define _ULng_ (_ULng)
#define _Long_ (_Long)

#define LstX NSArrayController


#define     _Kind instancetype
#define     _Kind_ (_Kind)

typedef     void(^_VBlk)();     //typedef     _Void(^)() _VBlk;
#define      _VBlk_ (_VBlk)

#define _IMPL @implementation
#define _IFCE @interface
#define _PRTO @protocol
#define _IMPT @import
#define _FINI @end

#define Impl implementation
#define Desc interface
#define Plan protocol
#define Incl import
#define Fini end


#define IMPL implementation
#define IFCE interface
#define PRTO protocol
#define IMPT import
#define FINI end

#define _U    unsigned
#define _S    static
#define _I    inline
#define _E    external
#define _C    const



#endif //  _ObjC
#endif // __Objc__