#import <Foundation/Foundation.h>


@interface NSData (Gzip)
- (id)initWithGzippedData: (NSData *)gzippedData;
- (NSData *) gzipDeflate;

@end