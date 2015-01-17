#import <Foundation/Foundation.h>

@class LDPreferencesWindowController;
@class LDMoleculeWindowController;

@interface LDApplicationDelegate : NSObject

@property(readonly, strong) LDPreferencesWindowController *preferencesWindowController;
@property(readonly, strong) LDMoleculeWindowController *moleculeWindowController;
@property(readwrite, weak) IBOutlet NSMenuItem *controlPanelMenuItem, *colorKeyPanelMenuItem;

- (IBAction)showPreferences:(id)sender;
- (IBAction)showOrHideTracking:(id)sender;

- (void)toggleControlPanelMenu:(NSNotification *)note;
- (void)toggleColorKeyPanelMenu:(NSNotification *)note;

@end
