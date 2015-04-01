
/*! @note This is an AUTOMATICALLY generated file!
    Built on Apr 1, 2015, 6:00:23 AM from /Volumes/2T/ServiceData/AtoZ.framework/AtoZUniversal/_ObjC/_ObjC.plist */

// 7


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

// Potpourri


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


// Objective-C Keywords



#define                 Reqd  required
#define                 Optn  optional
#define                 Incl  import
#define                 Stop  end
#define                       ￭ @Stop


// Imports

@import ObjectiveC _
 @class WebView,

             AVAudioPlayer _
#    if MAC_ONLY
@import Cocoa _
#  elif IOS_ONLY
@import UIKit _



// AllCLasses

ABAddressBook
ABGroup
ABMultiValue
ABMutableMultiValue
ABPeoplePickerView
ABPerson
ABPersonView
ABRecord
ABSearchElement
CAAnimation
CAAnimationGroup
CABasicAnimation
CAConstraint
CAConstraintLayoutManager
CAEmitterCell
CAEmitterLayer
CAGradientLayer
CAKeyframeAnimation
CALayer
CAMediaTimingFunction
CAOpenGLLayer
CAPropertyAnimation
CARemoteLayerClient
CARemoteLayerServer
CARenderer
CAReplicatorLayer
CAScrollLayer
CAShapeLayer
CATextLayer
CATiledLayer
CATransaction
CATransformLayer
CATransition
CAValueFunction
CIColor
CIContext
CIDetector
CIFaceFeature
CIFeature
CIFilter
CIFilterGenerator
CIFilterShape
CIImage
CIImageAccumulator
CIKernel
CIPlugIn
CIQRCodeFeature
CIRectangleFeature
CISampler
CIVector
DOMAbstractView
DOMAttr
DOMBlob
DOMCDATASection
DOMCSSCharsetRule
DOMCSSFontFaceRule
DOMCSSImportRule
DOMCSSMediaRule
DOMCSSPageRule
DOMCSSPrimitiveValue
DOMCSSRule
DOMCSSRuleList
DOMCSSStyleDeclaration
DOMCSSStyleRule
DOMCSSStyleSheet
DOMCSSUnknownRule
DOMCSSValue
DOMCSSValueList
DOMCharacterData
DOMComment
DOMCounter
DOMDocument
DOMDocumentFragment
DOMDocumentType
DOMElement
DOMEntity
DOMEntityReference
DOMEvent
DOMFile
DOMFileList
DOMHTMLAnchorElement
DOMHTMLAppletElement
DOMHTMLAreaElement
DOMHTMLBRElement
DOMHTMLBaseElement
DOMHTMLBaseFontElement
DOMHTMLBodyElement
DOMHTMLButtonElement
DOMHTMLCollection
DOMHTMLDListElement
DOMHTMLDirectoryElement
DOMHTMLDivElement
DOMHTMLDocument
DOMHTMLElement
DOMHTMLEmbedElement
DOMHTMLFieldSetElement
DOMHTMLFontElement
DOMHTMLFormElement
DOMHTMLFrameElement
DOMHTMLFrameSetElement
DOMHTMLHRElement
DOMHTMLHeadElement
DOMHTMLHeadingElement
DOMHTMLHtmlElement
DOMHTMLIFrameElement
DOMHTMLImageElement
DOMHTMLInputElement
DOMHTMLLIElement
DOMHTMLLabelElement
DOMHTMLLegendElement
DOMHTMLLinkElement
DOMHTMLMapElement
DOMHTMLMarqueeElement
DOMHTMLMenuElement
DOMHTMLMetaElement
DOMHTMLModElement
DOMHTMLOListElement
DOMHTMLObjectElement
DOMHTMLOptGroupElement
DOMHTMLOptionElement
DOMHTMLOptionsCollection
DOMHTMLParagraphElement
DOMHTMLParamElement
DOMHTMLPreElement
DOMHTMLQuoteElement
DOMHTMLScriptElement
DOMHTMLSelectElement
DOMHTMLStyleElement
DOMHTMLTableCaptionElement
DOMHTMLTableCellElement
DOMHTMLTableColElement
DOMHTMLTableElement
DOMHTMLTableRowElement
DOMHTMLTableSectionElement
DOMHTMLTextAreaElement
DOMHTMLTitleElement
DOMHTMLUListElement
DOMImplementation
DOMKeyboardEvent
DOMMediaList
DOMMouseEvent
DOMMutationEvent
DOMNamedNodeMap
DOMNode
DOMNodeIterator
DOMNodeList
DOMNotation
DOMObject
DOMOverflowEvent
DOMProcessingInstruction
DOMProgressEvent
DOMRGBColor
DOMRange
DOMRect
DOMStyleSheet
DOMStyleSheetList
DOMText
DOMTreeWalker
DOMUIEvent
DOMWheelEvent
DOMXPathExpression
DOMXPathResult
ICCameraDevice
ICCameraFile
ICCameraFolder
ICCameraItem
ICDevice
ICDeviceBrowser
ICScannerBandData
ICScannerDevice
ICScannerFeature
ICScannerFeatureBoolean
ICScannerFeatureEnumeration
ICScannerFeatureRange
ICScannerFeatureTemplate
ICScannerFunctionalUnit
ICScannerFunctionalUnitDocumentFeeder
ICScannerFunctionalUnitFlatbed
ICScannerFunctionalUnitNegativeTransparency
ICScannerFunctionalUnitPositiveTransparency
IKCameraDeviceView
IKDeviceBrowserView
IKFilterBrowserPanel
IKFilterBrowserView
IKFilterUIView
IKImageBrowserCell
IKImageBrowserView
IKImageEditPanel
IKImageView
IKPictureTaker
IKSaveOptions
IKScannerDeviceView
IKSlideshow
NSATSTypesetter
NSAccessibilityElement
NSActionCell
NSAffineTransform
NSAlert
NSAnimation
NSAnimationContext
NSAppearance
NSAppleEventDescriptor
NSAppleEventManager
NSAppleScript
NSApplication
NSArchiver
NSArray
NSArrayController
NSAssertionHandler
NSAsynchronousFetchRequest
NSAsynchronousFetchResult
NSAtomicStore
NSAtomicStoreCacheNode
NSAttributeDescription
NSAttributedString
NSAutoreleasePool
NSBackgroundActivityScheduler
NSBatchUpdateRequest
NSBatchUpdateResult
NSBezierPath
NSBitmapImageRep
NSBlockOperation
NSBox
NSBrowser
NSBrowserCell
NSBundle
NSButton
NSButtonCell
NSByteCountFormatter
NSCIImageRep
NSCache
NSCachedURLResponse
NSCalendar
NSCalendarDate
NSCell
NSCharacterSet
NSClassDescription
NSClickGestureRecognizer
NSClipView
NSCloneCommand
NSCloseCommand
NSCoder
NSCollectionView
NSCollectionViewItem
NSColor
NSColorList
NSColorPanel
NSColorPicker
NSColorSpace
NSColorWell
NSComboBox
NSComboBoxCell
NSComparisonPredicate
NSCompoundPredicate
NSCondition
NSConditionLock
NSConnection
NSConstantString
NSControl
NSController
NSCountCommand
NSCountedSet
NSCreateCommand
NSCursor
NSCustomImageRep
NSData
NSDataDetector
NSDate
NSDateComponents
NSDateComponentsFormatter
NSDateFormatter
NSDateIntervalFormatter
NSDatePicker
NSDatePickerCell
NSDecimalNumber
NSDecimalNumberHandler
NSDeleteCommand
NSDictionary
NSDictionaryController
NSDirectoryEnumerator
NSDistantObject
NSDistantObjectRequest
NSDistributedLock
NSDistributedNotificationCenter
NSDockTile
NSDocument
NSDocumentController
NSDraggingImageComponent
NSDraggingItem
NSDraggingSession
NSDrawer
NSEPSImageRep
NSEnergyFormatter
NSEntityDescription
NSEntityMapping
NSEntityMigrationPolicy
NSEnumerator
NSError
NSEvent
NSException
NSExceptionHandler
NSExistsCommand
NSExpression
NSExpressionDescription
NSExtensionContext
NSExtensionItem
NSFetchRequest
NSFetchRequestExpression
NSFetchedPropertyDescription
NSFileAccessIntent
NSFileCoordinator
NSFileHandle
NSFileManager
NSFileSecurity
NSFileVersion
NSFileWrapper
NSFont
NSFontCollection
NSFontDescriptor
NSFontManager
NSFontPanel
NSForm
NSFormCell
NSFormatter
NSGarbageCollector
NSGestureRecognizer
NSGetCommand
NSGlyphGenerator
NSGlyphInfo
NSGradient
NSGraphicsContext
NSHTTPCookie
NSHTTPCookieStorage
NSHTTPURLResponse
NSHashTable
NSHelpManager
NSHost
NSImage
NSImageCell
NSImageRep
NSImageView
NSIncrementalStore
NSIncrementalStoreNode
NSIndexPath
NSIndexSet
NSIndexSpecifier
NSInputStream
NSInvocation
NSInvocationOperation
NSItemProvider
NSJSONSerialization
NSKeyedArchiver
NSKeyedUnarchiver
NSLayoutConstraint
NSLayoutManager
NSLengthFormatter
NSLevelIndicator
NSLevelIndicatorCell
NSLinguisticTagger
NSLocale
NSLock
NSLogicalTest
NSMachBootstrapServer
NSMachPort
NSMagnificationGestureRecognizer
NSManagedObject
NSManagedObjectContext
NSManagedObjectID
NSManagedObjectModel
NSMapTable
NSMappingModel
NSMassFormatter
NSMatrix
NSMediaLibraryBrowserController
NSMenu
NSMenuItem
NSMenuItemCell
NSMergeConflict
NSMergePolicy
NSMessagePort
NSMessagePortNameServer
NSMetadataItem
NSMetadataQuery
NSMetadataQueryAttributeValueTuple
NSMetadataQueryResultGroup
NSMethodSignature
NSMiddleSpecifier
NSMigrationManager
NSMoveCommand
NSMutableArray
NSMutableAttributedString
NSMutableCharacterSet
NSMutableData
NSMutableDictionary
NSMutableFontCollection
NSMutableIndexSet
NSMutableOrderedSet
NSMutableParagraphStyle
NSMutableSet
NSMutableString
NSMutableURLRequest
NSNameSpecifier
NSNetService
NSNetServiceBrowser
NSNib
NSNotification
NSNotificationCenter
NSNotificationQueue
NSNull
NSNumber
NSNumberFormatter
NSObject
NSObjectController
NSOpenGLContext
NSOpenGLLayer
NSOpenGLPixelFormat
NSOpenGLView
NSOpenPanel
NSOperation
NSOperationQueue
NSOrderedSet
NSOrthography
NSOutlineView
NSOutputStream
NSPDFImageRep
NSPDFInfo
NSPDFPanel
NSPICTImageRep
NSPageController
NSPageLayout
NSPanGestureRecognizer
NSPanel
NSParagraphStyle
NSPasteboard
NSPasteboardItem
NSPathCell
NSPathComponentCell
NSPathControl
NSPathControlItem
NSPersistentDocument
NSPersistentStore
NSPersistentStoreAsynchronousResult
NSPersistentStoreCoordinator
NSPersistentStoreRequest
NSPersistentStoreResult
NSPipe
NSPointerArray
NSPointerFunctions
NSPopUpButton
NSPopUpButtonCell
NSPopover
NSPort
NSPortCoder
NSPortMessage
NSPortNameServer
NSPositionalSpecifier
NSPredicate
NSPredicateEditor
NSPredicateEditorRowTemplate
NSPreferencePane
NSPressGestureRecognizer
NSPrintInfo
NSPrintOperation
NSPrintPanel
NSPrinter
NSProcessInfo
NSProgress
NSProgressIndicator
NSPropertyDescription
NSPropertyListSerialization
NSPropertyMapping
NSPropertySpecifier
NSProtocolChecker
NSProxy
NSPurgeableData
NSQuitCommand
NSRandomSpecifier
NSRangeSpecifier
NSRecursiveLock
NSRegularExpression
NSRelationshipDescription
NSRelativeSpecifier
NSResponder
NSRotationGestureRecognizer
NSRuleEditor
NSRulerMarker
NSRulerView
NSRunLoop
NSRunningApplication
NSSaveChangesRequest
NSSavePanel
NSScanner
NSScreen
NSScriptClassDescription
NSScriptCoercionHandler
NSScriptCommand
NSScriptCommandDescription
NSScriptExecutionContext
NSScriptObjectSpecifier
NSScriptSuiteRegistry
NSScriptWhoseTest
NSScrollView
NSScroller
NSSearchField
NSSearchFieldCell
NSSecureTextField
NSSecureTextFieldCell
NSSegmentedCell
NSSegmentedControl
NSSet
NSSetCommand
NSShadow
NSSharingService
NSSharingServicePicker
NSSimpleCString
NSSlider
NSSliderCell
NSSocketPort
NSSocketPortNameServer
NSSortDescriptor
NSSound
NSSpecifierTest
NSSpeechRecognizer
NSSpeechSynthesizer
NSSpellChecker
NSSpellServer
NSSplitView
NSSplitViewController
NSSplitViewItem
NSStackView
NSStatusBar
NSStatusBarButton
NSStatusItem
NSStepper
NSStepperCell
NSStoryboard
NSStoryboardSegue
NSStream
NSString
NSTabView
NSTabViewController
NSTabViewItem
NSTableCellView
NSTableColumn
NSTableHeaderCell
NSTableHeaderView
NSTableRowView
NSTableView
NSTask
NSText
NSTextAlternatives
NSTextAttachment
NSTextAttachmentCell
NSTextBlock
NSTextCheckingResult
NSTextContainer
NSTextField
NSTextFieldCell
NSTextFinder
NSTextInputContext
NSTextList
NSTextStorage
NSTextTab
NSTextTable
NSTextTableBlock
NSTextView
NSThread
NSTimeZone
NSTimer
NSTitlebarAccessoryViewController
NSTokenField
NSTokenFieldCell
NSToolbar
NSToolbarItem
NSToolbarItemGroup
NSTouch
NSTrackingArea
NSTreeController
NSTreeNode
NSTypesetter
NSURL
NSURLAuthenticationChallenge
NSURLCache
NSURLComponents
NSURLConnection
NSURLCredential
NSURLCredentialStorage
NSURLDownload
NSURLHandle
NSURLProtectionSpace
NSURLProtocol
NSURLQueryItem
NSURLRequest
NSURLResponse
NSURLSession
NSURLSessionConfiguration
NSURLSessionDataTask
NSURLSessionDownloadTask
NSURLSessionTask
NSURLSessionUploadTask
NSUUID
NSUbiquitousKeyValueStore
NSUnarchiver
NSUndoManager
NSUniqueIDSpecifier
NSUserActivity
NSUserAppleScriptTask
NSUserAutomatorTask
NSUserDefaults
NSUserDefaultsController
NSUserNotification
NSUserNotificationAction
NSUserNotificationCenter
NSUserScriptTask
NSUserUnixTask
NSValue
NSValueTransformer
NSView
NSViewAnimation
NSViewController
NSVisualEffectView
NSWhoseSpecifier
NSWindow
NSWindowController
NSWorkspace
NSXMLDTD
NSXMLDTDNode
NSXMLDocument
NSXMLElement
NSXMLNode
NSXMLParser
NSXPCConnection
NSXPCInterface
NSXPCListener
NSXPCListenerEndpoint
PDFAction
PDFActionGoTo
PDFActionNamed
PDFActionRemoteGoTo
PDFActionResetForm
PDFActionURL
PDFAnnotation
PDFAnnotationButtonWidget
PDFAnnotationChoiceWidget
PDFAnnotationCircle
PDFAnnotationFreeText
PDFAnnotationInk
PDFAnnotationLine
PDFAnnotationLink
PDFAnnotationMarkup
PDFAnnotationPopup
PDFAnnotationSquare
PDFAnnotationStamp
PDFAnnotationText
PDFAnnotationTextWidget
PDFBorder
PDFDestination
PDFDocument
PDFOutline
PDFPage
PDFSelection
PDFThumbnailView
PDFView
QCComposition
QCCompositionLayer
QCCompositionParameterView
QCCompositionPickerPanel
QCCompositionPickerView
QCCompositionRepository
QCPatchController
QCPlugIn
QCPlugInViewController
QCRenderer
QCView
QLPreviewPanel
QLPreviewView
QTCaptureAudioPreviewOutput
QTCaptureConnection
QTCaptureDecompressedAudioOutput
QTCaptureDecompressedVideoOutput
QTCaptureDevice
QTCaptureDeviceInput
QTCaptureFileOutput
QTCaptureInput
QTCaptureLayer
QTCaptureMovieFileOutput
QTCaptureOutput
QTCaptureSession
QTCaptureVideoPreviewOutput
QTCaptureView
QTCompressionOptions
QTDataReference
QTFormatDescription
QTMedia
QTMetadataItem
QTMovie
QTMovieLayer
QTMovieModernizer
QTMovieView
QTSampleBuffer
QTTrack
QuartzFilter
QuartzFilterManager
QuartzFilterView
ScreenSaverDefaults
ScreenSaverView
WKBackForwardList
WKBackForwardListItem
WKFrameInfo
WKNavigation
WKNavigationAction
WKNavigationResponse
WKPreferences
WKProcessPool
WKScriptMessage
WKUserContentController
WKUserScript
WKWebView
WKWebViewConfiguration
WKWindowFeatures
WebArchive
WebBackForwardList
WebDataSource
WebDownload
WebFrame
WebFrameView
WebHistory
WebHistoryItem
WebPreferences
WebResource
WebScriptObject
WebUndefined
WebView

// Make iOS universal


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


// Abbreviations


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
#define                   _C  const
#define                   _E  extern
#define                   _I  inline
#define                   _S  static
#define                   _U  unsigned


// AllTypes

NSAffineTransformStruct
NSAlertStyle
NSAnimationEffect
NSAnimationProgress
NSAppleEventManagerSuspensionID
NSApplicationDelegateReply
NSApplicationPrintReply
NSApplicationTerminateReply
NSBackingStoreType
NSBezelStyle
NSBitmapImageFileType
NSBorderType
NSBrowserColumnResizingType
NSButtonType
NSCellAttribute
NSCellImagePosition
NSCellState
NSCellType
NSComparisonResult
NSCompositingOperation
NSControlSize
NSControlTint
NSDatePickerElementFlags
NSDocumentChangeType
NSDragOperation
NSDrawerState
NSEventType
NSFocusRingType
NSFontAction
NSFontSymbolicTraits
NSFontTraitMask
NSGlyph
NSGlyphLayoutMode
NSGlyphRelation
NSGradientType
NSHandler
NSHandler2
NSHashEnumerator
NSHashTable
NSImageInterpolation
NSKeyValueObservingOptions
NSLayoutDirection
NSLayoutStatus
NSLineBreakMode
NSMapEnumerator
NSMapTable
NSMatrixMode
NSModalSession
NSOpenGLContextAuxiliary
NSOpenGLPixelFormatAuxiliary
NSPoint
NSPrintingPageOrder
NSProgressIndicatorStyle
NSProgressIndicatorThickness
NSProgressIndicatorThreadInfo
NSRange
NSRect
NSRectEdge
NSSaveOperationType
NSScreenAuxiliaryOpaque
NSScrollArrowPosition
NSScrollerArrow
NSScrollerPart
NSSelectionAffinity
NSSelectionDirection
NSSelectionGranularity
NSSize
NSSocketNativeHandle
NSStringEncoding
NSSwappedDouble
NSSwappedFloat
NSTIFFCompression
NSTabState
NSTabViewType
NSTableViewDropOperation
NSTextAlignment
NSTextTabType
NSThreadPrivate
NSTickMarkPosition
NSTimeInterval
NSTitlePosition
NSTokenStyle
NSToolTipTag
NSToolbarDisplayMode
NSToolbarSizeMode
NSTrackingRectTag
NSTypesetterGlyphInfo
NSUsableScrollerParts
NSWindowDepth
NSWindowOrderingMode
NSWorkspaceIconCreationOptions
NSWorkspaceLaunchOptions
NSWritingDirection
NSZone

// Sugar


#define             IOS_ONLY  TARGET_OS_IPHONE
#define             MAC_ONLY  !IOS_ONLY
#define                    _  ;
#define                _Type  typedef


// Types


// Intro

#ifdef   __OBJC__
#ifndef   _ObjC__
#define   _ObjC__
/*!   @abstract _ObjC is concise dialect of ObjC that is terse and compatible - without needless tricks.
    @discussion It strives to minimize excessive *'s, {}'s, and ()'s, and so on, and so forth.
                Class pointers and types are typedef'd to aliases, with no pointer,
                formatted like _Four lettes, starting with an underscore, capitalized. */

