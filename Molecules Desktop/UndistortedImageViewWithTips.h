#import <Cocoa/Cocoa.h>
#import "LeapObjectiveC.h"

@interface UndistortedImageViewWithTips : NSOpenGLView <LeapListener>
- (id)initWithFrame:(NSRect)frame pixelFormat:(NSOpenGLPixelFormat *)format andController:(LeapController *)controller andImageID:(int)ID;
@end
