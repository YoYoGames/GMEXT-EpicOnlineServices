#pragma once

// iOS-only helper for EOS Account Portal login.
//
// On iOS 13+ EOS_Auth_Login requires EOS_Auth_Credentials.SystemAuthCredentialsOptions
// to point at an EOS_IOS_Auth_CredentialsOptions whose PresentationContextProviding
// implements ASWebAuthenticationPresentationContextProviding (the anchor used to
// present the login web sheet). Without it EOS_Auth_Login returns EOS_NotConfigured.
//
// This is implemented in ObjC++ (eos_ios_auth.mm) so the plain-C++ auth code never
// has to include UIKit / eos_IOS.h (eos_IOS.h #imports UIKit).

#ifdef __cplusplus
extern "C" {
#endif

// Allocates and returns an EOS_IOS_Auth_CredentialsOptions* (as an opaque void*)
// configured with a presentation context for the app's key window. Assign it to
// EOS_Auth_Credentials.SystemAuthCredentialsOptions before EOS_Auth_Login.
// Returns NULL on failure.
void* eos_ios_auth_credentials_options_create(void);

// Frees the options struct returned above. Call AFTER EOS_Auth_Login returns
// (EOS copies the options synchronously). The retained PresentationContextProviding
// object is owned and released by the EOS SDK itself, so it is NOT freed here.
void eos_ios_auth_credentials_options_free(void* options);

#ifdef __cplusplus
}
#endif
