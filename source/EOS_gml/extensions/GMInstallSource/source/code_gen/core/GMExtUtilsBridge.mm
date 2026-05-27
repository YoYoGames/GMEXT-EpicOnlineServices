#import "GMExtUtilsBridge.h"

// Include the C++ header that declares gm::ExtUtils.
// Adjust this include path if needed for your project layout.
#import "core/GMExtUtils.h"

@implementation GMExtUtilsBridge

+ (nullable NSString *)GetExtensionOption:(NSString *)extName
                               optionName:(NSString *)optName
{
    if (extName == nil || optName == nil) {
        return nil;
    }

    const std::string value = gm::ExtUtils::GetExtensionOption(
        extName.UTF8String,
        optName.UTF8String
    );

    // Match C++ behavior naturally:
    // empty string -> @""
    // invalid UTF-8 -> nil
    return [NSString stringWithUTF8String:value.c_str()];
}

@end