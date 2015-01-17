#import <Foundation/Foundation.h>
#include <OpenGL/gl3.h>

@interface OpenGLUtil : NSObject

+ (GLuint) createProgramForContext:(NSOpenGLContext *)context
                     vertexShader:(NSString *)vertexFilePath
                   fragmentShader:(NSString *)fragmentFilePath;

+ (GLuint) createProgramForContext:(NSOpenGLContext *)context
                     vertexShader:(NSString *)vertexFilePath
                   fragmentShader:(NSString *)fragmentFilePath
                   geometryShader:(NSString *)geometryFilePath;

+ (GLuint) bindTextureUnitForContext:(NSOpenGLContext *)context inSlot:(int)textureUnit;

+(void) checkGLError:(NSString *)contextMessage;
@end
