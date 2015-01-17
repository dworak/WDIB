#import "LDMolecule.h"

@interface LDMolecule (XYZ)

- (BOOL)readFromXYZData:(NSData *)fileData;

@end
