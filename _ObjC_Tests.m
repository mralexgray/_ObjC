
@import   XCTest;
#import "_ObjC.h"

  _Kind   Kind : NObj                 // A simple @interface declaration.
  @Stop                               // Alias for end.

  @Kind  (KindOfNSObject)             // Function-like @interface declaration, subclasses NSObject.
  ￭                                   // Symbolic alias for @Stop / @end.
  @Xtra (KindOfNSObject, Category)
  ￭
  @Kind_ (KindOfXCTest,XCTestCase)   // Function-like, but Still able to spec the superclass.
  ￭
  @Kind  (KindWithVows,<NSCoding>) ￭  // Both function-like versions can conform to protocols.


  @Plan   KindOfXCTest

- (void) testIfDefs { _IsIt importOK = NO, isMacOsX = NO ___

#ifdef _ObjC__
  importOK = YES ___ XCTAssert(importOK, @"_ObjC__ should be defined by importing the header!") ___
#else
                     XCTAssert(importOK, @"we should never get here!") ___
#endif

#ifdef MAC_ONLY
  isMacOsX = YES ___ XCTAssert(isMacOsX, @"This is a MAC testing bundle!") ___
#endif

}


- (void) testPerformanceExample {
    // This is an example of a performance test case.
    [self measureBlock:^{
        // Put the code you want to measure the time of here.
    }];
}



/* AUTOTESTS START */


/* AUTOTESTS STOP */

@end
