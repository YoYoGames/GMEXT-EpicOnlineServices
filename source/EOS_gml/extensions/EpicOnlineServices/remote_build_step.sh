#!/bin/bash
#
# Runs on the macOS build host during a Windows-driven (remote) build.
#
# Igor copies THIS SCRIPT ALONE to <output_dir>/<project>FromPC/ and runs it
# there - nothing else from the extension folder comes with it - so the only
# things worth touching are what Igor has already put on the Mac. By the time
# this runs, the extension zips staged in iOSSourceFromMac have been copied over
# and unzipped into <project>FromPC/Fw/, and the subsequent rsync into the real
# Xcode project directory has not happened yet.
#
# So the job here is the one piece of work Windows could not do: strip the vendor
# (Epic) code signature from the already-unzipped EOSSDK.xcframework, in place.
# Xcode 15+ verifies a bundled xcframework's signature and fails with "signature
# cannot be verified" for a third-party one; the app re-signs embedded frameworks
# with its own identity during signing, so removing the vendor signature is the
# standard fix.
#
# On a Mac-host build pre_build_step.sh already stripped the framework before
# zipping it, and for a macOS (rather than iOS) target there is no such framework
# here at all, so this is a no-op in both those cases.

SCRIPT_DIR="$(cd "$(dirname "$0")" && pwd -P)"
XCFW="$SCRIPT_DIR/Fw/EOSSDK.xcframework"

if [ ! -d "$XCFW" ]; then
    # Nothing unzipped here -> nothing to do.
    exit 0
fi

echo "remote_build_step: stripping vendor signature from EOSSDK.xcframework"

# Drop every _CodeSignature bundle seal and each framework binary's embedded
# signature. Stripping an already-stripped framework is harmless.
find "$XCFW" -type d -name "_CodeSignature" -exec rm -rf {} +
find "$XCFW" -type d -name "*.framework" | while IFS= read -r fw; do
    bin="$fw/$(basename "$fw" .framework)"
    [ -f "$bin" ] && codesign --remove-signature "$bin" >/dev/null 2>&1 || true
done

exit 0
