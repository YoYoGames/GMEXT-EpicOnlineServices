#!/bin/bash
#
# Runs on the macOS build host during a Windows-driven (remote) iOS build.
# Windows' pre_build_step.bat stages the RAW EOSSDK.xcframework into
# iOSSourceFromMac (it can't run macOS framework tooling); here we do the
# Mac-only work: strip the vendor code signature and zip with ditto.
# (Mirrors how the Discord extension processes raw libs in remote_build_step.)
#
# On a Mac-host build, pre_build_step.sh already produced EOSSDK.zip and left no
# raw folder, so this is a no-op in that case.

SCRIPT_DIR="$(cd "$(dirname "$0")" && pwd -P)"
IOS_DIR="$SCRIPT_DIR/iOSSourceFromMac"
XCFW="$IOS_DIR/EOSSDK.xcframework"

if [ ! -d "$XCFW" ]; then
    # Nothing staged (e.g. Mac-host build already zipped it) -> nothing to do.
    exit 0
fi

echo "remote_build_step: processing EOS iOS xcframework on macOS"

rm -f "$IOS_DIR/EOSSDK.zip"

# Strip the vendor (Epic) signature. Xcode 15+ rejects an unverifiable
# third-party xcframework signature; the app re-signs embedded frameworks with
# its own identity on embed, so removing it is the standard fix.
find "$XCFW" -type d -name "_CodeSignature" -exec rm -rf {} +
find "$XCFW" -type d -name "*.framework" | while IFS= read -r fw; do
    bin="$fw/$(basename "$fw" .framework)"
    [ -f "$bin" ] && codesign --remove-signature "$bin" >/dev/null 2>&1 || true
done

# Zip with ditto: preserves the (flat iOS) framework structure; --norsrc/
# --noextattr prevent AppleDouble "._" files that break ProcessXCFramework.
ditto -c -k --norsrc --noextattr --keepParent "$XCFW" "$IOS_DIR/EOSSDK.zip"
rc=$?

# Remove the raw framework so only the .zip remains.
rm -rf "$XCFW"

exit $rc
