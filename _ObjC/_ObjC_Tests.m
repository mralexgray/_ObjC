
@import XCTest;
#import <_ObjC.h>


#define 🅺 @Kind
#define 🅚(...) @Kind_(__VA_ARGS__)
#define 🆇 @Xtra
#define 🅧(...) @Xtra(__VA_ARGS__)
#define 🅿︎ @Plan // 🅟
#define 🆅 @Vows // 🅥

_Kind Kind : NObj                   /// A simple \c @interface declaration.
@Stop                               /// Alias for \c @end.

🅺 (KindOfNObj)                     /// Function-like \c @interface declaration, subclasses NSObject.
￭                                   /// @see \c @Stop @see \c @end.

🅚 (KindOfXCTest,Case)          ￭   /// Function-like, but Still able to spec the superclass.

🅺 (KindWithVows,<Code>)        ￭   /// Both function-like versions can conform to protocols.

@Xtra(KindOfNObj,CategoryName)  ￭

🅧 (KindOfNObj,SomeOtherCat)    ￭

@Plan KindOfXCTest                  /// A simple \c @implementation declaration.

_XCTest(IfDefs,                     /// equivalent to - (void)  testIfDefs { .... }

#ifdef _ObjC_
  XCTAssert(YES, @"_ObjC__ should be defined by importing the header!") ___
#if IOS_ONLY
    XCTFail(@"This is a MAC testing bundle!, we should never get here") ___
#endif
#endif
)

//_XCTest(PerformanceExample, // This is an example of a performance test case.
//
//  [self measureBlock:^{ /* Put the code you want to measure the time of here. */  }];
//)

￭

/// AUTO-GENERATED TESTS BELOW(Generated at Apr 24, 2015, 12:11:11 PM)

_XCTCase(DefinesTestCase)
_XCTest(TheyWorked,

	XCTAssert(@encode(CGSize) == @encode(_Size), @"%s should equal %s!",@encode(CGSize),@encode(_Size));
	XCTAssert(@encode(NSRange) == @encode(_Rnge), @"%s should equal %s!",@encode(NSRange),@encode(_Rnge));
	XCTAssert(@encode(CGPoint) == @encode(_Cord), @"%s should equal %s!",@encode(CGPoint),@encode(_Cord));
	XCTAssert(@encode(CGFloat) == @encode(_Flot), @"%s should equal %s!",@encode(CGFloat),@encode(_Flot));
	XCTAssert(@encode(CGAffineTransform) == @encode(_AffT), @"%s should equal %s!",@encode(CGAffineTransform),@encode(_AffT));
	XCTAssert(@encode(CGRect) == @encode(_Rect), @"%s should equal %s!",@encode(CGRect),@encode(_Rect));


	XCTAssert(@encode(NSMutableData *) == @encode(mData), @"%s should equal %s!",@encode(NSMutableData *),@encode(mData));
	XCTAssert(@encode(NSEvent *) == @encode(_Evnt), @"%s should equal %s!",@encode(NSEvent *),@encode(_Evnt));
	XCTAssert(@encode(NSFont *) == @encode(_Font), @"%s should equal %s!",@encode(NSFont *),@encode(_Font));
	XCTAssert(@encode(char *) == @encode(_Char), @"%s should equal %s!",@encode(char *),@encode(_Char));
	XCTAssert(@encode(NSScanner *) == @encode(_Scnr), @"%s should equal %s!",@encode(NSScanner *),@encode(_Scnr));
	XCTAssert(@encode(NSMutableIndexSet *) == @encode(mISet), @"%s should equal %s!",@encode(NSMutableIndexSet *),@encode(mISet));
	XCTAssert(@encode(NSMutableCharacterSet *) == @encode(mCSet), @"%s should equal %s!",@encode(NSMutableCharacterSet *),@encode(mCSet));
	XCTAssert(@encode(NSMutableParagraphStyle *) == @encode(mPStl), @"%s should equal %s!",@encode(NSMutableParagraphStyle *),@encode(mPStl));
	XCTAssert(@encode(NSAttributedString *) == @encode(_ATxt), @"%s should equal %s!",@encode(NSAttributedString *),@encode(_ATxt));
	XCTAssert(@encode(NSArray *) == @encode(_List), @"%s should equal %s!",@encode(NSArray *),@encode(_List));
	XCTAssert(@encode(NSColor *) == @encode(_Colr), @"%s should equal %s!",@encode(NSColor *),@encode(_Colr));
	XCTAssert(@encode(NSMutableDictionary *) == @encode(mDict), @"%s should equal %s!",@encode(NSMutableDictionary *),@encode(mDict));
	XCTAssert(@encode(NSIndexSet) == @encode(_ISet), @"%s should equal %s!",@encode(NSIndexSet),@encode(_ISet));
	XCTAssert(@encode(AVAudioPlayer *) == @encode(_SndP), @"%s should equal %s!",@encode(AVAudioPlayer *),@encode(_SndP));
	XCTAssert(@encode(NSURL *) == @encode(_NUrl), @"%s should equal %s!",@encode(NSURL *),@encode(_NUrl));
	XCTAssert(@encode(NSTableView *) == @encode(_TblV), @"%s should equal %s!",@encode(NSTableView *),@encode(_TblV));
	XCTAssert(@encode(NSValue *) == @encode(_Valu), @"%s should equal %s!",@encode(NSValue *),@encode(_Valu));
	XCTAssert(@encode(NSNumber *) == @encode(_Numb), @"%s should equal %s!",@encode(NSNumber *),@encode(_Numb));
	XCTAssert(@encode(NSMutableArray *) == @encode(mList), @"%s should equal %s!",@encode(NSMutableArray *),@encode(mList));
	XCTAssert(@encode(NSError *) == @encode(_Errr), @"%s should equal %s!",@encode(NSError *),@encode(_Errr));
	XCTAssert(@encode(CALayer *) == @encode(_Layr), @"%s should equal %s!",@encode(CALayer *),@encode(_Layr));
	XCTAssert(@encode(NSData *) == @encode(_Data), @"%s should equal %s!",@encode(NSData *),@encode(_Data));
	XCTAssert(@encode(NSParagraphStyle *) == @encode(_PStl), @"%s should equal %s!",@encode(NSParagraphStyle *),@encode(_PStl));
	XCTAssert(@encode(unsigned char *) == @encode(_UChr), @"%s should equal %s!",@encode(unsigned char *),@encode(_UChr));
	XCTAssert(@encode(NSDate *) == @encode(_Date), @"%s should equal %s!",@encode(NSDate *),@encode(_Date));
	XCTAssert(@encode(NSDictionary *) == @encode(_Dict), @"%s should equal %s!",@encode(NSDictionary *),@encode(_Dict));
	XCTAssert(@encode(NSString *) == @encode(_Text), @"%s should equal %s!",@encode(NSString *),@encode(_Text));
	XCTAssert(@encode(NSJSONSerialization *) == @encode(_Json), @"%s should equal %s!",@encode(NSJSONSerialization *),@encode(_Json));
	XCTAssert(@encode(NSBezierPath *) == @encode(_Path), @"%s should equal %s!",@encode(NSBezierPath *),@encode(_Path));
	XCTAssert(@encode(NSNotification *) == @encode(_Note), @"%s should equal %s!",@encode(NSNotification *),@encode(_Note));
	XCTAssert(@encode(NSPipe *) == @encode(_Pipe), @"%s should equal %s!",@encode(NSPipe *),@encode(_Pipe));
	XCTAssert(@encode(NSFileHandle *) == @encode(_File), @"%s should equal %s!",@encode(NSFileHandle *),@encode(_File));
	XCTAssert(@encode(NSWindow *) == @encode(_Wind), @"%s should equal %s!",@encode(NSWindow *),@encode(_Wind));
	XCTAssert(@encode(NSBundle *) == @encode(_Bndl), @"%s should equal %s!",@encode(NSBundle *),@encode(_Bndl));
	XCTAssert(@encode(NSMutableAttributedString *) == @encode(mATxt), @"%s should equal %s!",@encode(NSMutableAttributedString *),@encode(mATxt));
	XCTAssert(@encode(NSObject *) == @encode(_NObj), @"%s should equal %s!",@encode(NSObject *),@encode(_NObj));
	XCTAssert(@encode(NSCharacterSet *) == @encode(_CSet), @"%s should equal %s!",@encode(NSCharacterSet *),@encode(_CSet));
	XCTAssert(@encode(NSUserDefaults *) == @encode(_Defs), @"%s should equal %s!",@encode(NSUserDefaults *),@encode(_Defs));
	XCTAssert(@encode(XCTestCase *) == @encode(_Case), @"%s should equal %s!",@encode(XCTestCase *),@encode(_Case));
	XCTAssert(@encode(NSView *) == @encode(_View), @"%s should equal %s!",@encode(NSView *),@encode(_View));
	XCTAssert(@encode(NSInvocation *) == @encode(_Call), @"%s should equal %s!",@encode(NSInvocation *),@encode(_Call));
	XCTAssert(@encode(NSDateFormatter *) == @encode(_DFmt), @"%s should equal %s!",@encode(NSDateFormatter *),@encode(_DFmt));
	XCTAssert(@encode(NSImage *) == @encode(_Pict), @"%s should equal %s!",@encode(NSImage *),@encode(_Pict));
	XCTAssert(@encode(NSMutableString *) == @encode(mText), @"%s should equal %s!",@encode(NSMutableString *),@encode(mText));
	XCTAssert(@encode(NSApplication *) == @encode(_Appl), @"%s should equal %s!",@encode(NSApplication *),@encode(_Appl));


	XCTAssert(@encode(NSOutlineView *) == @encode(_OutV), @"%s should equal %s!",@encode(NSOutlineView *),@encode(_OutV));
	XCTAssert(@encode(NSTableView *) == @encode(_Tabl), @"%s should equal %s!",@encode(NSTableView *),@encode(_Tabl));
	XCTAssert(@encode(NSMenuItem *) == @encode(_SubM), @"%s should equal %s!",@encode(NSMenuItem *),@encode(_SubM));
	XCTAssert(@encode(NSImageView *) == @encode(_PicV), @"%s should equal %s!",@encode(NSImageView *),@encode(_PicV));
	XCTAssert(@encode(NSUserNotification *) == @encode(uNote), @"%s should equal %s!",@encode(NSUserNotification *),@encode(uNote));
	XCTAssert(@encode(NSFileHandle *) == @encode(_Hndl), @"%s should equal %s!",@encode(NSFileHandle *),@encode(_Hndl));
	XCTAssert(@encode(NSUserNotificationCenter *) == @encode(uNCtr), @"%s should equal %s!",@encode(NSUserNotificationCenter *),@encode(uNCtr));
	XCTAssert(@encode(WebView *) == @encode(_WebV), @"%s should equal %s!",@encode(WebView *),@encode(_WebV));
	XCTAssert(@encode(NSArrayController *) == @encode(xList), @"%s should equal %s!",@encode(NSArrayController *),@encode(xList));
	XCTAssert(@encode(NSWindowController *) == @encode(xWind), @"%s should equal %s!",@encode(NSWindowController *),@encode(xWind));
	XCTAssert(@encode(NSAppleScript *) == @encode(_Scpt), @"%s should equal %s!",@encode(NSAppleScript *),@encode(_Scpt));
	XCTAssert(@encode(NSMenu *) == @encode(_Menu), @"%s should equal %s!",@encode(NSMenu *),@encode(_Menu));
	XCTAssert(@encode(NSScrollView *) == @encode(_Scrl), @"%s should equal %s!",@encode(NSScrollView *),@encode(_Scrl));
	XCTAssert(@encode(NSSplitView *) == @encode(_Splt), @"%s should equal %s!",@encode(NSSplitView *),@encode(_Splt));
	XCTAssert(@encode(NSTextView *) == @encode(_TxtV), @"%s should equal %s!",@encode(NSTextView *),@encode(_TxtV));
	XCTAssert(@encode(NSAppleEventDescriptor *) == @encode(_AEvD), @"%s should equal %s!",@encode(NSAppleEventDescriptor *),@encode(_AEvD));
	XCTAssert(@encode(NSTask *) == @encode(_Task), @"%s should equal %s!",@encode(NSTask *),@encode(_Task));
	XCTAssert(@encode(NSTableColumn *) == @encode(_TCol), @"%s should equal %s!",@encode(NSTableColumn *),@encode(_TCol));
	XCTAssert(@encode(NSTextField *) == @encode(_Labl), @"%s should equal %s!",@encode(NSTextField *),@encode(_Labl));


)
@end
