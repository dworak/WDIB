#import "LDApplicationDelegate.h"
#import "LDPreferencesWindowController.h"
#import "LDMoleculeWindowController.h"

@implementation LDApplicationDelegate

@synthesize preferencesWindowController = _preferencesWindowController;
@synthesize moleculeWindowController = _moleculeWindowController;
@synthesize controlPanelMenuItem = _controlPanelMenuItem, colorKeyPanelMenuItem = _colorKeyPanelMenuItem;

- (void)applicationDidFinishLaunching:(NSNotification *)aNotification
{
	[[NSUserDefaults standardUserDefaults] registerDefaults:[NSDictionary dictionaryWithObjectsAndKeys:
															 [NSNumber numberWithInt:3], @"leapControlStyle",
															 nil]];    

    [self.moleculeWindowController showWindow:self];
    
    NSNotificationCenter *nc = [NSNotificationCenter defaultCenter];    
    [nc addObserver:self selector:@selector(toggleControlPanelMenu:) name:kSLSMoleculeControlPanelNotification object:nil];
    [nc addObserver:self selector:@selector(toggleColorKeyPanelMenu:) name:kSLSMoleculeColorKeyPanelNotification object:nil];

}

- (BOOL)applicationShouldOpenUntitledFile:(NSApplication *)sender
{
    return YES;
}

- (BOOL)applicationOpenUntitledFile:(NSApplication *)theApplication
{
    return YES;
}

- (BOOL)applicationShouldTerminateAfterLastWindowClosed:(NSApplication *)theApplication
{
	return YES;
}

- (BOOL)application:(NSApplication *)theApplication openFile:(NSString *)filename
{
    [self.moleculeWindowController openFileWithPath:filename extension:[[filename pathExtension] lowercaseString]];
     
    return YES;
}

- (IBAction)showPreferences:(id)sender;
{
	[self.preferencesWindowController showWindow:self];
}

- (IBAction)showOrHideTracking:(id)sender
{
    [[self.moleculeWindowController left] removeFromSuperview];
    [[self.moleculeWindowController right] removeFromSuperview];
}

- (void)toggleControlPanelMenu:(NSNotification *)note;
{
    BOOL isControlPanelShown = [[note object] boolValue];
    if (isControlPanelShown)
    {
        [self.controlPanelMenuItem setTitle:@"Hide Controls"];
    }
    else
    {
        [self.controlPanelMenuItem setTitle:@"Show Controls"];
    }
}

- (void)toggleColorKeyPanelMenu:(NSNotification *)note;
{
    BOOL isColorKeyPanelShown = [[note object] boolValue];
    if (isColorKeyPanelShown)
    {
        [self.colorKeyPanelMenuItem setTitle:@"Hide Color Key"];
    }
    else
    {
        [self.colorKeyPanelMenuItem setTitle:@"Show Color Key"];
    }
}

- (LDPreferencesWindowController *)preferencesWindowController;
{
	if (_preferencesWindowController == nil)
	{
		_preferencesWindowController = [[LDPreferencesWindowController alloc] initWithWindowNibName:@"LDPreferencesWindowController"];
	}
	
	return _preferencesWindowController;
}

- (LDMoleculeWindowController *)moleculeWindowController;
{
	if (_moleculeWindowController == nil)
	{
		_moleculeWindowController = [[LDMoleculeWindowController alloc] initWithWindowNibName:@"LDMoleculeWindowController"];
	}
	
	return _moleculeWindowController;
}

@end
