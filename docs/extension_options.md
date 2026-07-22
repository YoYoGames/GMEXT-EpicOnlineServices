@title Extension Options

# Extension Options

To configure the Epic Online Services extension, double click on the **EpicOnlineServices** extension in
your Asset Browser in the IDE. All options below live at the bottom of the extension window.

## Build Options

These paths control where the extension's build step pulls the vendored Epic Online Services SDK from
(relative to the extension folder). See ${page.getting_started} for how to obtain the SDK.

| Option | Type | Default | Description |
|---|---|---|---|
| **EOS SDK Path** | Path | `../EOS_sdk/c/` | Folder containing the desktop (Windows/macOS/Linux) SDK. |
| **EOS Android SDK Path** | Path | `../EOS_sdk/android/` | Folder containing the Android SDK. |
| **EOS iOS SDK Path** | Path | `../EOS_sdk/ios/` | Folder containing the iOS SDK. |

## App Options

These identify your application to Epic's backend. **Product ID**, **Sandbox ID**, and **Deployment ID**
are required and are found on the [Epic Games Dev Portal](https://dev.epicgames.com/portal/en-US/).

| Option | Type | Required | Description |
|---|---|---|---|
| **Is Server** | Bool | No | Set to `true` when this build is a dedicated game server rather than a client. |
| **Product ID** | String | Yes | The product ID for the running application. |
| **Sandbox ID** | String | Yes | The sandbox ID for the running application. |
| **Deployment ID** | String | Yes | The deployment ID for the running application. |
| **Client Credentials ID** | String | No | Client ID of the service permissions entry. Leave empty if no service permissions are used. |
| **Client Credentials Secret** | String | No | Client secret matching **Client Credentials ID**. Leave empty if no service permissions are used. |
| **Encryption Key** | String | No | 256-bit key (64 hex characters) used to encrypt files written via ${module.player_data_storage}/${module.title_storage}. Leave empty if you don't use those modules. |
| **Product Name** | String | Yes | Name of the product, non-empty, max 64 characters. Allowed characters: `A-Z a-z 0-9 . _ space ! ? & - ( ) + : `. |
| **Product Version** | String | Yes | Version of the running application, same character restrictions as **Product Name**. Defaults to `1.0`. |
| **Debug Mode** | Dropdown (`Auto`/`Enabled`) | No | `Auto` (default) enables debug mode only when running from the IDE. `Enabled` forces it on for every build. |

[[Warning: `Enabled` should only be used to hand a standalone debug build to someone for testing. Never ship a store build with **Debug Mode** set to `Enabled` — see ${page.getting_started} for what debug mode changes (skips the launcher relaunch check performed by ${function.eos_platform_check_for_launcher_and_restart}).]]

## Extra Options

| Option | Type | Default | Description |
|---|---|---|---|
| **Log Level** | Dropdown (`0`/`1`/`2`) | `1` | Verbosity of the extension's own startup/diagnostic logging, separate from ${function.eos_logging_set_callback}'s per-category SDK logging (see ${module.logging}). |

## Android

| Option | Type | Default | Description |
|---|---|---|---|
| **Scheme** | String | `eos.<lowercase Client Credentials ID>` | The custom URI scheme Android registers for the Epic account-portal login redirect. Must stay in sync with **Client Credentials ID** above — if you change one, update the other. |

[[Note: The remaining options under **Extra Options** (SDK version/hash pins) are internal build plumbing used to fetch the correct redistributable SDK version and are not meant to be edited by hand.]]
