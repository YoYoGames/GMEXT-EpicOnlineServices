# GMEXT-EpicOnlineServices
Repository for GameMaker's Epic Online Services Extension

This repository was created with the intent of presenting users with the latest version available of the extension (even previous to marketplace updates) and also provide a way for the community to contribute with bug fixes and feature implementation.

This extension works on Windows, macOS, Linux, Android and iOS.

> [!NOTE]
> On Android only the **arm64-v8a** and **x86_64** ABIs are supported. Epic does not ship a 32-bit
> ARM build of the EOS SDK, so **armeabi-v7a is not available** - remove it from your project's
> Android target ABIs, or the game will build and then fail to load the native library at runtime.

The API surface is declared in a single GMIDL spec and the platform bindings are generated from it,
so the layout is by role rather than by IDE project:

* API SPEC: `source/EOS_gml/extensions/EpicOnlineServices/source/spec.gmidl`
* NATIVE C++ (Windows/macOS/Linux, and the shared implementation): `source/EOS_gml/extensions/EpicOnlineServices/source/src/native/`
* iOS: `source/EOS_gml/extensions/EpicOnlineServices/source/src/ios/`
* ANDROID (Java): `source/EOS_gml/extensions/EpicOnlineServices/AndroidSource/Java/`
* GENERATED BINDINGS: `source/EOS_gml/extensions/EpicOnlineServices/source/code_gen/` (never edit by hand - regenerate from the spec)
* BUILD PRESETS: `source/EOS_gml/extensions/EpicOnlineServices/source/CMakePresets.json`

After compilation the exported dll/dylib file is automatically copied into the extension folder inside the included GameMaker project folder.

---

## News

Version 3.0.0 comes with new previously missing modules:

- P2P API
- Sessions API
- Lobbies API
- ECom API
- RTC API
- Custom Invites API
- Reports API
- Logging API

---

## Requirements

In order to compile you are required to download the [Epic Online Services SDK 1.19.1.2](https://dev.epicgames.com/portal/en-US) and place it inside `source/EOS_sdk/`. The multi-platform bundle is expected: `C/` for desktop, plus `Android/` and `iOS/`.

> [!IMPORTANT]
> Latest version 3.0.0 is a major release:
>
> * You will need to make sure the SDK is updated to version 1.19.1.2
> * Android builds must target arm64-v8a and/or x86_64 only (see the note above)

---

## Documentation

* Check [the documentation](../../wiki)

The online documentation is regularly updated to ensure it contains the most current information. For those who prefer a different format, we also offer a HTML version. This HTML is directly converted from the GitHub Wiki content, ensuring consistency, although it may follow slightly behind in updates.

We encourage users to refer primarily to the GitHub Wiki for the latest information and updates. The HTML version, included with the extension and within the demo project's data files, serves as a secondary, static reference.

Additionally, if you're contributing new features through PR (Pull Requests), we kindly ask that you also provide accompanying documentation for these features, to maintain the comprehensiveness and usefulness of our resources.

