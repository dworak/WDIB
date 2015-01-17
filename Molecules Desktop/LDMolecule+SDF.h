#import "LDMolecule.h"

@interface LDMolecule (SDF)

- (BOOL)readFromSDFData:(NSData *)fileData;

@end
