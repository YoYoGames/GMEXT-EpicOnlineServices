# GMEXT-EpicOnlineServices
Repository for GameMaker's Epic Online Services Extension

This repository was created with the intent of presenting users with the latest version available of the extension (even previous to marketplace updates) and also provide a way for the community to contribute with bug fixes and feature implementation.

This extension will work on Windows and macOS.

* SOURCE CODE: `source/EOS_gml/extensions/EpicOnlineServices/epiconlineservices_cpp/`
* VS PROJECT: `source/EOS_gml/extensions/EpicOnlineServices/epiconlineservices_windows/`
* XCODE PROJECT: `source/EOS_gml/extensions/EpicOnlineServices/epiconlineservices_macos/`

After compilation the exported dll/dylib file is automatically copied into the extension folder inside the included GameMaker project folder.

---

## Requirements

In order to compile for Windows/macOS you are required to download the [EpicOnlineSerives SDK 1.16.3-CL35276460](https://dev.epicgames.com/portal/en-US) and place it inside `source/EOS_sdk/`

> [!IMPORTANT]
> Latest version 2.0.0 is a major release:
>
> * You will need to make sure the SDK is updated to version 1.16.3-CL35276460

---

## Documentation

* Check [the documentation](../../wiki)

The online documentation is regularly updated to ensure it contains the most current information. For those who prefer a different format, we also offer a HTML version. This HTML is directly converted from the GitHub Wiki content, ensuring consistency, although it may follow slightly behind in updates.

We encourage users to refer primarily to the GitHub Wiki for the latest information and updates. The HTML version, included with the extension and within the demo project's data files, serves as a secondary, static reference.

Additionally, if you're contributing new features through PR (Pull Requests), we kindly ask that you also provide accompanying documentation for these features, to maintain the comprehensiveness and usefulness of our resources.

