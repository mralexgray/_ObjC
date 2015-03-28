
@import XCTest;

#import "_ObjC.h"

  _Kind  Kind : NSObject   /// A simple @interface declaration.
+ _Kind_ instanceOfKind ;  /// Sugar for (instancetype) methods.
-        ______________ _  /// use underscore instead of ;
  @Stop                    /// Alias for end.

  @Kind  (KindOfNSObject)  /// Function-like, we can assume it's an NSObject.
  ￭                        /// Symbolic alias for @Stop / @end.

  @Kind_ (KindOfXCTest,XCTestCase) ￭  // Function-like, but Still able to spec the superclass.
  @Kind  (KindWithVows,<NSCoding>) ￭  // Both function-like versions can conform to protocols.

  @Plan   KindOfXCTest

- (void) testIfDefs { BOOL importOK = NO, isMacOsX = NO _

#ifdef _ObjC__
  importOK = YES _ XCTAssert(importOK, @"_ObjC__ should be defined by importing the header!") _
#endif

#ifdef MAC_ONLY
  isMacOsX = YES _ XCTAssert(isMacOsX, @"This is a MAC testing bundle!") _
#endif

}


- (void) testPerformanceExample {
    // This is an example of a performance test case.
    [self measureBlock:^{
        // Put the code you want to measure the time of here.
    }];
}

@end
