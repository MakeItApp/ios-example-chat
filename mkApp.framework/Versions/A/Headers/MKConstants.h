//
//  MKConstants.h
//  mkApp
//

#import <Foundation/Foundation.h>


enum {
  MKAPPIgnoreCache = NSURLRequestReloadIgnoringLocalCacheData,
  MKAPPUseCacheElseLoad = NSURLRequestReturnCacheDataElseLoad,
  MKAPPUseCacheDontLoad = NSURLRequestReturnCacheDataDontLoad
};
typedef NSInteger MKAPPCachePolicy;

enum {
  MKAPPErrorNone = 0,
  MKAPPErrorInvalidParams = 100,
  MKAPPErrorOperationFailed = 101,
  MKAPPErrorOperationNotAllowed = 102,
  MKAPPErrorDuplicateKey = 103,
  MKAPPErrorNullFileName,
  MKAPPErrorNullFileSize,
  MKAPPErrorNullFileUrl,
  MKAPPErrorMalformedEmail,
  MKAPPErrorConnectionFailed = 200,
  MKAPPErrorInvalidResponse,
  MKAPPErrorUnknownStatus,
  MKAPPErrorUnknownFileName,
  MKAPPErrorAdvGenericError =300,
  MKAPPErrorAdvNoSpotAvailable,
  MKAPPErrorAdvNotConfigured
};
typedef NSInteger MKAPPError;

enum {
  MKAPPRegexOptionCaseInsensitive = (1 << 0),
  MKAPPRegexOptionMultiline = (1 << 1),
  MKAPPRegexOptionDotall = (1 << 2)
};
typedef NSInteger MKAPPRegexOption;
