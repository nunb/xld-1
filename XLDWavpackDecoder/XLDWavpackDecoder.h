
#import <Foundation/Foundation.h>
#import <XLDPlugins/XLDPlugins.h>
#import <wavpack/wavpack.h>

@interface XLDWavpackDecoder : NSObject <XLDDecoder>
{
	WavpackContext *wc;
	int bps;
	int samplerate;
	int channels;
	xldoffset_t totalFrames;
	int isFloat;
	char errstr[256];
	BOOL error;
	NSString *cueData;
	NSMutableDictionary *metadataDic;
	NSString *srcPath;
}

+ (BOOL)canHandleFile:(char *)path;
+ (BOOL)canLoadThisBundle;
- (BOOL)openFile:(char *)path;
- (int)samplerate;
- (int)bytesPerSample;
- (int)channels;
- (int)decodeToBuffer:(int *)buffer frames:(int)count;
- (void)closeFile;
- (xldoffset_t)seekToFrame:(xldoffset_t)count;
- (xldoffset_t)totalFrames;
- (int)isFloat;
- (BOOL)error;
- (XLDEmbeddedCueSheetType)hasCueSheet;
- (id)cueSheet;
- (id)metadata;
- (NSString *)srcPath;

@end