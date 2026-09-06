#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <AuthenticationServices/AuthenticationServices.h>

#include <cstdlib>

#include <eos_IOS.h>   // EOS_IOS_Auth_CredentialsOptions (this header #imports UIKit)

#include "eos_ios_auth.h"

// Presentation anchor provider for the Account Portal's ASWebAuthenticationSession.
API_AVAILABLE(ios(13.0))
@interface EOSAuthPresentationContext : NSObject <ASWebAuthenticationPresentationContextProviding>
@end

@implementation EOSAuthPresentationContext

- (ASPresentationAnchor)presentationAnchorForWebAuthenticationSession:(ASWebAuthenticationSession *)session
{
    // Prefer the foreground-active key window.
    for (UIScene *scene in UIApplication.sharedApplication.connectedScenes) {
        if (![scene isKindOfClass:[UIWindowScene class]]) continue;
        UIWindowScene *windowScene = (UIWindowScene *)scene;
        for (UIWindow *window in windowScene.windows) {
            if (window.isKeyWindow) return window;
        }
    }
    // Fallback: first window of any window scene.
    for (UIScene *scene in UIApplication.sharedApplication.connectedScenes) {
        if (![scene isKindOfClass:[UIWindowScene class]]) continue;
        UIWindowScene *windowScene = (UIWindowScene *)scene;
        if (windowScene.windows.count > 0) return windowScene.windows.firstObject;
    }
    return nil;
}

@end

extern "C" void* eos_ios_auth_credentials_options_create(void)
{
    EOS_IOS_Auth_CredentialsOptions* options =
        (EOS_IOS_Auth_CredentialsOptions*)calloc(1, sizeof(EOS_IOS_Auth_CredentialsOptions));
    if (!options) return nullptr;

    options->ApiVersion = EOS_IOS_AUTH_CREDENTIALSOPTIONS_API_LATEST;
    options->CreateBackgroundSnapshotView = nullptr;
    options->CreateBackgroundSnapshotViewContext = nullptr;

    // iOS 13+: provide the presentation context (required). EOS releases this
    // bridged object once it consumes it. On iOS < 13 it must be null.
    if (@available(iOS 13.0, *)) {
        EOSAuthPresentationContext *ctx = [[EOSAuthPresentationContext alloc] init];
        options->PresentationContextProviding = (void *)CFBridgingRetain(ctx);
    } else {
        options->PresentationContextProviding = nullptr;
    }

    return options;
}

extern "C" void eos_ios_auth_credentials_options_free(void* options)
{
    // Frees only the options struct; the PresentationContextProviding object is
    // owned/released by the EOS SDK after it consumes it.
    if (options) free(options);
}
