GMInstallSource

GMInstallSource is a GameMaker extension for detecting the app’s installation source on Android and iOS.

It helps your game decide which store-specific behavior to use, such as Google Play Billing, Apple StoreKit, Epic/EOS flows, marketplace behavior, analytics tagging, or fallback handling.

The extension exposes one shared GameMaker API for both Android and iOS. Android detection is performed through the installer package reported by the system, while iOS detection uses Apple’s MarketplaceKit distributor result where available. The Android implementation maps known installer packages to GooglePlay, EpicAndroid, AndroidOther, or AndroidSideload. The iOS implementation maps Apple distributor results to IOSAppStore, IOSTestFlight, IOSMarketplace, IOSOther, Unsupported, or Error.

Main Function
install_source_request(callback)

Requests the install source.

This is the recommended function to call when your game starts.

Although Android can return the result immediately, iOS may complete asynchronously. For that reason, developers should always treat this function as asynchronous and wait for the callback before using the result.

The callback returns:

Argument	Description
success	Whether the request completed successfully.
source	The InstallSource enum value.
name	A normalized string name for the source.
raw	The raw platform value or error message.
Cached Functions
install_source_get_cached()

Returns the last detected InstallSource value.

Before install_source_request() completes, this usually returns InstallSource.Unknown.

install_source_get_cached_name()

Returns the normalized name for the last detected install source.

Examples include:

Name	Meaning
google_play	Android app installed from Google Play.
epic_android	Android app installed from Epic or an Epic-like installer.
android_other	Android returned an installer, but it is not mapped to a known store.
android_sideload	Android did not return an installer package.
ios_app_store	iOS app installed from the App Store.
ios_testflight	iOS app installed from TestFlight.
ios_marketplace	iOS app installed from an alternative marketplace.
ios_other	iOS returned another distributor type.
unsupported	Detection is not supported on this device, OS version, or build.
error	Detection failed.
unknown	No source has been detected yet, or the source is unknown.
install_source_get_cached_raw()

Returns the raw platform value from the last detection request.

This is useful for debugging, analytics, and identifying installers that are not yet mapped.

Examples may include Android package names such as com.android.vending, com.epicgames.portal, or com.android.shell, and iOS distributor values such as appStore, testFlight, or other.

Enum: InstallSource
Unknown

The install source has not been detected yet, or the platform returned an unknown result.

GooglePlay

The Android app was installed from Google Play.

Use this when enabling Google Play-specific behavior, such as Google Play Billing.

EpicAndroid

The Android app was installed from Epic or an Epic-like installer.

Use this when enabling Epic or EOS-specific behavior on Android.

AndroidOther

Android returned an installer package, but it was not mapped to Google Play or Epic.

This can happen with development installs, ADB installs, GameMaker deploys, Android Studio deploys, OEM stores, or other Android stores.

This is not an error.

AndroidSideload

Android did not return an installer package.

This can mean the app was sideloaded, the installer is unknown, or installer data is unavailable.

IOSAppStore

The iOS app was installed from the App Store.

Use this when enabling Apple StoreKit or App Store-specific behavior.

IOSTestFlight

The iOS app was installed from TestFlight.

Use this for QA, beta testing, or test-only behavior.

IOSMarketplace

The iOS app was installed from an alternative marketplace.

Use this when enabling Epic, EOS, or marketplace-specific behavior on iOS.

IOSOther

iOS returned another distributor type.

This can happen with Xcode deploys, GameMaker direct deploys, development installs, enterprise distribution, or other custom distribution paths.

This is not an error.

Unsupported

Install source detection is not supported on the current platform, OS version, or build.

On iOS, this may happen if MarketplaceKit is unavailable or the device is running an unsupported iOS version.

Error

The extension failed while detecting the install source.

The raw value may contain an error message.

Typical Results During Testing
Platform / Install Method	Expected Name	Notes
Android via GameMaker or ADB	android_other	Raw value may be com.android.shell.
Android from Google Play	google_play	Used for Google Play Billing routing.
Android from Epic	epic_android	Exact raw installer should be confirmed from a real Epic install.
iOS via GameMaker or Xcode	ios_other	Expected for local development deploys.
iOS TestFlight	ios_testflight	Expected for TestFlight builds.
iOS App Store	ios_app_store	Used for StoreKit routing.
iOS alternative marketplace	ios_marketplace	Raw value should contain the marketplace identifier.
Recommended Usage

Call install_source_request() once during game startup.

Store the returned result in global variables or your own app state.

Before showing store-specific purchases or features, check whether the install source result is ready.

Use the enum value for logic, the normalized name for logging, and the raw value for debugging or analytics.

Common Use Cases

Good uses for this extension:

Use Case	Supported
Choosing Google Play Billing, StoreKit, or Epic/EOS flow	Yes
Showing store-specific UI	Yes
Analytics by install source	Yes
Debugging unknown store installs	Yes
Handling TestFlight or development builds	Yes

Not recommended as the only check for:

Use Case	Reason
Proving ownership	Store/backend validation is still required.
Unlocking paid content without receipt validation	Client-side install source can be incomplete or insufficient.
Anti-piracy enforcement	Use proper entitlement validation instead.

For purchases and entitlements, validate with the correct platform or backend service: Google Play purchase validation, Apple transaction validation, or Epic/EOS entitlement validation.

Notes for Developers Using the Extension

AndroidOther and IOSOther are valid results. They should not automatically be treated as failures.

The extension uses a callback-based API so GameMaker code can work the same way on Android and iOS.

For local development, android_other and ios_other are expected and usually mean the app was installed through GameMaker, ADB, Android Studio, or Xcode.

