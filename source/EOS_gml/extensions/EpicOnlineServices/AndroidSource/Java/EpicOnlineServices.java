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

        // Logged under "yoyo" so it appears in the GameMaker console.
        Log.i("yoyo", "[EOS] EpicOnlineServices.Init() called");

        Activity activity = RunnerActivity.CurrentActivity;
        if (activity == null) {
            Log.e("yoyo", "[EOS] EOSSDK.init skipped: RunnerActivity.CurrentActivity is null");
            return;
        }

        try {
            // EOSSDK.init() logs via the native EOSLogger.Log JNI method, so
            // libEOSSDK.so must be loaded FIRST. Init() runs at onCreate, before
            // the Bridge's static loadLibrary, so load it explicitly here.
            // (loadLibrary is idempotent; the later Bridge load is a no-op.)
            System.loadLibrary("EOSSDK");
            EOSSDK.init(activity);
            Log.i("yoyo", "[EOS] EOSSDK.init succeeded");
        } catch (Throwable t) {
            Log.e("yoyo", "[EOS] EOSSDK.init FAILED: " + t.toString());
        }
    }
}
