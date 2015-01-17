#import <Foundation/Foundation.h>

@class LDOpenGLRenderer;

// TODO: Convert enum to elemental number
typedef enum { CARBON, HYDROGEN, OXYGEN, NITROGEN, SULFUR, PHOSPHOROUS, IRON, UNKNOWN, SILICON, FLUORINE, CHLORINE, BROMINE, IODINE, CALCIUM, ZINC, CADMIUM, SODIUM, MAGNESIUM, NUM_ATOMTYPES } LDAtomType;
typedef enum { BALLANDSTICK, SPACEFILLING, CYLINDRICAL, } LDVisualizationType;
typedef enum { UNKNOWNRESIDUE, DEOXYADENINE, DEOXYCYTOSINE, DEOXYGUANINE, DEOXYTHYMINE, ADENINE, CYTOSINE, GUANINE, URACIL, GLYCINE, ALANINE, VALINE, 
				LEUCINE, ISOLEUCINE, SERINE, CYSTEINE, THREONINE, METHIONINE, PROLINE, PHENYLALANINE, TYROSINE, TRYPTOPHAN, HISTIDINE,
				LYSINE, ARGININE, ASPARTICACID, GLUTAMICACID, ASPARAGINE, GLUTAMINE, WATER, NUM_RESIDUETYPES } LDResidueType;
typedef enum { MOLECULESOURCE, MOLECULEAUTHOR, JOURNALAUTHOR, JOURNALTITLE, JOURNALREFERENCE, MOLECULESEQUENCE } LDMetadataType;
typedef enum { SINGLEBOND, DOUBLEBOND, TRIPLEBOND } LDBondType;

typedef struct { 
	GLfloat x; 
	GLfloat y; 
	GLfloat z; 
} LD3DPoint;

typedef struct {
	LDAtomType atomType;
	LD3DPoint center;
    NSInteger structureNumber;
    LDResidueType residueKey;
} LDAtomContainer;

typedef struct {
	LD3DPoint startPoint;
	LD3DPoint endPoint;
    LDBondType bondType;
    NSInteger structureNumber;
    LDResidueType residueKey;
} LDBondContainer;


@protocol LDMoleculeRenderingDelegate <NSObject>
- (void)renderingStarted;
- (void)renderingUpdated:(CGFloat)renderingProgress;
- (void)renderingEnded;
@end

@interface LDMolecule : NSObject 
{
	// Metadata from the Protein Data Bank
	unsigned int numberOfAtoms, numberOfBonds, numberOfStructures;
	NSString *filename, *filenameWithoutExtension, *title, *keywords, *journalAuthor, *journalTitle, *journalReference, *sequence, *compound, *source, *author;

	// Status of the molecule
	BOOL isBeingDisplayed, isDoneRendering, isRenderingCancelled;
	LDVisualizationType currentVisualizationType;
	unsigned int numberOfStructureBeingDisplayed;
	unsigned int totalNumberOfFeaturesToRender, currentFeatureBeingRendered;
	BOOL stillCountingAtomsInFirstStructure;

	// A holder for rendering connecting bonds
	NSValue *previousTerminalAtomValue;
	BOOL reverseChainDirection;
		
    // Molecule properties for scaling and translation
	float centerOfMassInX, centerOfMassInY, centerOfMassInZ;
	float minimumXPosition, maximumXPosition, minimumYPosition, maximumYPosition, minimumZPosition, maximumZPosition;
	float scaleAdjustmentForX, scaleAdjustmentForY, scaleAdjustmentForZ;

    NSMutableArray *atomArray, *bondArray;
    BOOL _elementsPresentInMolecule[NUM_ATOMTYPES];
    
    LDOpenGLRenderer *currentRenderer;
}

@property (readonly) float centerOfMassInX, centerOfMassInY, centerOfMassInZ;
@property (readonly) NSString *filename, *filenameWithoutExtension, *title, *keywords, *journalAuthor, *journalTitle, *journalReference, *sequence, *compound, *source, *author;
@property (readwrite, nonatomic) BOOL isBeingDisplayed, isRenderingCancelled;
@property (readonly) BOOL isDoneRendering;
@property (readonly) unsigned int numberOfAtoms, numberOfBonds, numberOfStructures;
@property (readwrite, strong) NSValue *previousTerminalAtomValue;
@property (readwrite, nonatomic) LDVisualizationType currentVisualizationType;
@property (readwrite) unsigned int numberOfStructureBeingDisplayed;
@property (readwrite, unsafe_unretained) id<LDMoleculeRenderingDelegate> renderingDelegate;

- (id)initWithData:(NSData *)fileData extension:(NSString *)fileExtension renderingDelegate:(id<LDMoleculeRenderingDelegate>)newRenderingDelegate;

+ (BOOL)isFiletypeSupportedForFile:(NSString *)filePath;
+ (void)setBondColor:(GLubyte *)bondColor forResidueType:(LDResidueType)residueType;

// Database methods
- (void)addMetadataToDatabase:(NSString *)metadata type:(LDMetadataType)metadataType;
- (NSInteger)addAtomToDatabase:(LDAtomType)atomType atPoint:(LD3DPoint)newPoint structureNumber:(NSInteger)structureNumber residueKey:(LDResidueType)residueKey;
- (void)addBondToDatabaseWithStartPoint:(NSValue *)startValue endPoint:(NSValue *)endValue bondType:(LDBondType)bondType structureNumber:(NSInteger)structureNumber residueKey:(NSInteger)residueKey;
- (BOOL *)elementsPresentInMolecule;

// Status notification methods
- (void)showStatusIndicator;
- (void)updateStatusIndicator;
- (void)hideStatusIndicator;

// Rendering
- (void)switchToDefaultVisualizationMode;
- (BOOL)renderMolecule:(LDOpenGLRenderer *)openGLRenderer;
- (void)readAndRenderAtoms:(LDOpenGLRenderer *)openGLRenderer;
- (void)readAndRenderBonds:(LDOpenGLRenderer *)openGLRenderer;

@end