#import "LDDocumentController.h"
#import "LDApplicationDelegate.h"

@implementation LDDocumentController

- (void)removeDocument:(NSDocument *)document
{
    [super removeDocument:document];
    
    if ([[self documents] count] < 1)
    {
//        [(LDApplicationDelegate *)[[NSApplication sharedApplication] delegate] showInitialHelp];
    }
}
@end
