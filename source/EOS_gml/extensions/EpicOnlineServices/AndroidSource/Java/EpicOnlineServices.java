package ${YYAndroidPackageName};
import java.lang.String;
import java.nio.ByteBuffer;

import android.app.Activity;
import android.util.Log;

import com.epicgames.mobile.eossdk.EOSSDK;

public final class EpicOnlineServices extends EpicOnlineServicesInternal {

    // Called once by RunnerActivity.setupExtensions() during onCreate (UI thread,
    // before any GML runs). EOS Android requires EOSSDK.init(activity) to store
    // the Activity/Context before EOS_Initialize; without it the native init
    // returns EOS_UnexpectedError. (RunnerActivity is in this same package.)
    @Override
    public void Init() {
        super.Init();

        Activity activity = RunnerActivity.CurrentActivity;
        if (activity == null) {
            Log.e("yoyo", "[EOS] EOSSDK.init skipped: RunnerActivity.CurrentActivity is null");
            return;
        }

        try {
            // EOSSDK.init() logs via the native EOSLogger.Log JNI method, so
            // libEOSSDK.so must be loaded first. Init() runs at onCreate, before
            // the Bridge's static loadLibrary, so load it explicitly here. Loading
            // it via System.loadLibrary also runs its JNI_OnLoad, which stores the
            // JavaVM that EOS_Initialize needs. (loadLibrary is idempotent.)
            System.loadLibrary("EOSSDK");
            EOSSDK.init(activity);
        } catch (Throwable t) {
            Log.e("yoyo", "[EOS] EOSSDK.init FAILED: " + t.toString());
        }
    }
}
