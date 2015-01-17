#import <Cocoa/Cocoa.h>

@protocol LDGLViewDelegate <NSObject>

- (void)resizeView;
- (void)rotateModelFromScreenDisplacementInX:(float)xRotation inY:(float)yRotation;
- (void)scaleModelByFactor:(float)scaleFactor;
- (void)translateModelByScreenDisplacementInX:(float)xTranslation inY:(float)yTranslation;

@end

@interface LDMoleculeGLView : NSOpenGLView
{
    NSPoint lastMovementPosition;
}
@property(readwrite, unsafe_unretained) id<LDGLViewDelegate>renderingDelegate;

@end
