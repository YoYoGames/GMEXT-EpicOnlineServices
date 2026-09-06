#pragma once

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// ObjC-visible bridge over gm::ExtUtils C++ helpers.
/// Implemented in Objective-C++ (.mm).
@interface GMExtUtilsBridge : NSObject

/// Returns the extension option as an NSString.
/// Swift imports this as:
///   GMExtUtilsBridge.getExtensionOption(_:optionName:)
+(nullable NSString*)GetExtensionOption : (NSString*)extName
optionName : (NSString*)optName
NS_SWIFT_NAME(getExtensionOption(_:optionName:));

@end

NS_ASSUME_NONNULL_END