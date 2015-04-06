
#ifdef   __OBJC__
#ifndef   _ObjC__
#define   _ObjC__

/*! @abstract _ObjC is concise dialect of ObjC that is terse and compatible - without needless tricks.
    @brief  It strives to minimize excessive *'s, {}'s, and ()'s, and so on, and so forth.
            Class pointers and types are typedef'd to aliases, with no pointer,
            formatted like _Four lettes, starting with an underscore, capitalized. */

@import ObjectiveC; @class WebView, AVAudioPlayer;


#define   IOS_ONLY TARGET_OS_IPHONE
#define   MAC_ONLY !IOS_ONLY
#define   _  ;

#define _U  unsigned
#define _S  static
#define _I  inline
#define _E  extern
#define _C  const

#if         MAC_ONLY
  @import   Cocoa ___

#elif       IOS_ONLY
  @import   UIKit ___

  #define              NSNib UINib      // Standarize names 1:1 between platforms.
  #define              NSApp UIApp
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
  #define        NSTableView UITableView
  #define       NSBezierPath UIBezierPath
  #define      NSApplication UIApplication
  #define NSUserNotification UILocalNotification
#else 
  #define  NSAffineTransform CGAffineTransform *

#endif // Import Platform Umbrellas, Standarize NS <-> UI names.


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
_Type            NSRange   _Rnge;
_Type  CGAffineTransform   _AffT;

                  /* POINTERS */

_Type        const char * _CChr;
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
_Type      NSFileHandle * _File;

_Type            NSPipe * _Pipe;

_Type     NSApplication * _Appl;

_Type      NSBezierPath * _Path;
_Type    NSUserDefaults * _Defs;
_Type      NSDictionary * _Dict;
_Type  NSParagraphStyle * _PStl;
_Type    NSNotification * _Note;
_Type       NSTableView * _TblV;
_Type     NSApplication * _Appl;
_Type     AVAudioPlayer* _SndP;

#if MAC_ONLY


  _Type _Void(^_MBlk)(_SubM menu);

#else 

  _Type      struct CGGradient   _Grad;

#endif

// For ObjC classes, let's define a preprocessor Macro to call the direct Classes, without the _.

#define   Char  char
#define   NUrl  NSURL
#define   Menu  NSMenu
#define   Font  NSFont
#define   View  NSView
#define   Data  NSData
#define   Colr  NSColor
#define   Errr  NSError
#define   Evnt  NSEvent
#define   Layr  CALayer
#define   List  NSArray
#define   Pict  NSImage
#define   Bndl  NSBundle
#define   NObj  NSObject
#define   Numb  NSNumber
#define   Text  NSString
#define   Wind  NSWindow
#define   Grad  NSGradient
#define   SubM  NSMenuItem
#define   PicV  NSImageView
#define   Splt  NSSplitView
#define   TblV  NSTableView
#define   Dict  NSDictionary
#define   Scrl  NSScrollView
#define   SndP  AVAudioPlayer
#define   Appl  NSApplication
#define   OutV  NSOutlineView
#define   TCol  NSTableColumn
#define   MLst  NSMutableArray
#define   Defs  NSUserDefaults
#define   Note  NSNotification
#define   PStl  NSParagraphStyle

#define   File NSFileHandle
#define   Task NSTask
#define   Pipe NSPipe


/// Good to make "shortcuts" for ALL `_ObjC` types as "method arguments"
/// with a leading Underscore to use ase parenthesis-free method parameterts!



#define _Appl_ (_Appl)
#define _Bndl_ (_Bndl)
#define _Char_ (_Char)
#define _Colr_ (_Colr)
#define _Comp_ (_Comp)
#define _Cord_ (_Cord)
#define _Data_ (_Data)
#define _Dict_ (_Dict)
#define _Errr_ (_Errr)
#define _Errr__ (_Errr __autoreleasing *)
#define _Evnt_ (_Evnt)
#define _File_ (_File)
#define _Flot_ (_Flot)
#define _Font_ (_Font)
#define _Grad_ (_Grad)
#define _IsIt_ (_IsIt)
#define _Layr_ (_Layr)
#define _List_ (_List)
#define _Long_ (_Long)
#define _LstX_ (_LstX)
#define _MBlk_ (_MBlk)
#define _Menu_ (_Menu)
#define _Meta_ (_Meta)
#define _Meth_ (_Meth)
#define _NObj_ (_NObj)
#define _NUrl_ (_NUrl)
#define _Note_ (_Note)
#define _Numb_ (_Numb)
#define _ObjC_ (_ObjC)
#define _OutV_ (_OutV)
#define _PStl_ (_PStl)
#define _PicV_ (_PicV)
#define _Pict_ (_Pict)
#define _Pipe_ (_Pipe)
#define _Rect_ (_Rect)
#define _Rnge_ (_Rnge)
#define _SInt_ (_SInt)
#define _Scrl_ (_Scrl)
#define _Size_ (_Size)
#define _SndP_ (_SndP)
#define _Splt_ (_Splt)
#define _SubM_ (_SubM)
#define _TCol_ (_TCol)
#define _Task_ (_Task)
#define _TblV_ (_TblV)
#define _Text_ (_Text)
#define _UChr_ (_UChr)
#define _UInt_ (_UInt)
#define _ULng_ (_ULng)
#define _View_ (_View)
#define _Void_ (_Void)
#define _WebV_ (_WebV)
#define _Wind_ (_Wind)


#define LstX NSArrayController

/// Let's standarize the preprocessor names too!

#define  Reqd required
#define  Optn optional
#define  Incl import
#define  Stop end
#define     ￭ @Stop

#define _Test(X,...) - (void) test##X { ({ __VA_ARGS__; }); }
#define XCTUp(...) - (void) setUp { [super setUp]; ({ __VA_ARGS__; }); }
#define XCTDown(...) - (void) tearDown { ({ __VA_ARGS__; }); [super tearDown]; }


#define _Case(Name,...) @Incl XCTest; @Kind_ (Name,XCTestCase) ￭ @Plan Name XCTUp(__VA_ARGS__)


/*! Kind - Interface (Prototypes, Public, Name, etc)
    Vows - Protocol  (Promises, etc)
    Plan - Implemenation
    Xtra - Categories                                      */


#define  ￮(s) _Pragma(#s)             // This # is the "stringify" operator.

￮("mark - \"Kind of\"")

#define Plan implementation
#define ＿ Plan

/// A simple @interface declaration.

#define   _Kind                  @interface

#define   Kind_(Name,Meta,...)   interface Name : Meta __VA_ARGS__
#define   Kind(Name,...)         Kind_(Name,NObj,__VA_ARGS__)

/// Sugar for (instancetype) methods.

#define  _Kind_ (instancetype)

#pragma mark - Vows

#define Vows protocol

#pragma mark -  Xtra


#define   Xtra(Extends,Named) interface Extends      (Named)

//＞＜＝＠＿￦￡￠￮￬￫￪￩

#define  ＞(...) @Xtra(__VA_ARGS__)
#define  ＜(...) @XtraPlan(__VA_ARGS__)
#define   XtraPlan(Extends,Named) implementation Extends (Named)

#define   XtraStop(...)        Stop

//#define  _Plus Category

#define _Cat(K,...) @interface K (Sans) __VA_ARGS__; @end


#define _IMPL @implementation
#define _IFCE @interface
#define _PRTO @protocol
#define _IMPT @import
#define _FINI @end

//#define Impl implementation
//#define Desc interface
//#define Plan protocol

#define Fini end

//#define IMPL implementation
//#define IFCE interface
//#define PRTO protocol
//#define IMPT import
//#define FINI end


#define P(...) id<__VA_ARGS__>
#define INTERFACE(X,...)    @interface X : __VA_ARGS__ + (instancetype)

#define INIT_(K,...) [[K alloc] init##__VA_ARGS__]
#define NEW(A,B) A *B = A.new

#define oFK     objectForKey
#define vFK     valueForKey
#define vFKP    valueForKeyPath
#define mC      mutableCopy
#define mAVFK   mutableArrayValueForKey
#define bFK     boolForKey

#define bV     boolValue
#define dV     doubleValue
#define fV     floatValue
#define iV     integerValue
#define uIV    unsignedIntegerValue
#define rngV   rangeValue
#define strV   stringValue
#define rV     rectValue
#define pV     pointValue

#if IOS_ONLY                                    // GEOMETRY TRANSLATIONS
#define rectValue           CGRectValue
#define pointValue          CGPointValue
#define NSMakeSize          CGSizeMake
#define NSMakePoint         CGPointMake
#define NSMakeSize          CGSizeMake
#define NSMakeRect          CGRectMake
#define NSEqualSizes        CGSizeEqualToSize
#define NSEqualPoints       CGPointEqualToPoint
#define NSEqualRects        CGRectEqualToRect
#define NSPointInRect(P,R)  CGRectContainsPoint(R,P)
#endif


#endif //  _ObjC
#endif // __Objc__


//#define STRINGIFY(x) #x
//
//#pragma mark Vows
//
//_Pragma(STRINGIFY(mark whatever))
