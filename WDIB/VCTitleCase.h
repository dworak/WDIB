#import <Foundation/Foundation.h>

/*!
 This category adds a "titlecaseString" method to NSString objects.
*/
@interface NSString (VCTitleCase)

/*!
 Returns a title-cased version of the string.
 
 This changes all words to Title Caps, and attempts to be clever
 about *un*capitalizing small words like a/an/the in the input.
 
 The list of "small words" which are not capped comes from
 the New York Times Manual of Style, plus "vs" ans "v".
*/
- (NSString *)titlecaseString;

@end
