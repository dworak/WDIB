#import "LDMolecule.h"

@interface LDMolecule (PDB)

- (void)createBondsForPDBResidue:(NSString *)residueType withAtomDictionary:(NSDictionary *)atomDictionary structureNumber:(NSInteger)structureNumber;
- (BOOL)readFromPDBData:(NSData *)fileData;


@end
