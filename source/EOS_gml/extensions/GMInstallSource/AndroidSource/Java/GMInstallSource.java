package ${YYAndroidPackageName};

import ${YYAndroidPackageName}.enums.InstallSource;

import android.app.Activity;
import android.content.Context;
import android.content.pm.InstallSourceInfo;
import android.content.pm.PackageManager;
import android.os.Build;

import ${YYAndroidPackageName}.enums.*;

import ${YYAndroidPackageName}.GMExtWire;
import ${YYAndroidPackageName}.GMExtWire.GMFunction;
import ${YYAndroidPackageName}.GMExtWire.GMValue;
import ${YYAndroidPackageName}.GMExtUtils;

public class GMInstallSource extends GMInstallSourceInternal {

    private InstallSource cachedSource = InstallSource.Unknown;
    private String cachedName = "unknown";
    private String cachedRaw = "";

    public void install_source_request(GMFunction callback) {
        detectInstallSource();

        if (callback != null) {
            callback.call(
                true,
                cachedSource.value(),
                cachedName,
                cachedRaw
            );
        }
    }

    public InstallSource install_source_get_cached() {
        return cachedSource;
    }

    public String install_source_get_cached_name() {
        return cachedName;
    }

    public String install_source_get_cached_raw() {
        return cachedRaw;
    }

    private void detectInstallSource() {
        Activity activity = RunnerActivity.CurrentActivity;

        if (activity == null) {
            setCached(
                InstallSource.Error,
                "error",
                "RunnerActivity.CurrentActivity is null"
            );
            return;
        }

        try {
            Context context = activity.getApplicationContext();
            PackageManager packageManager = context.getPackageManager();
            String packageName = context.getPackageName();

            String installerPackage = null;

            if (Build.VERSION.SDK_INT >= 30) {
                InstallSourceInfo info = packageManager.getInstallSourceInfo(packageName);

                if (info != null) {
                    installerPackage = info.getInstallingPackageName();

                    if (installerPackage == null || installerPackage.length() == 0) {
                        installerPackage = info.getInitiatingPackageName();
                    }
                }
            } else {
                installerPackage = packageManager.getInstallerPackageName(packageName);
            }

            if (installerPackage == null || installerPackage.length() == 0) {
                setCached(
                    InstallSource.AndroidSideload,
                    "android_sideload",
                    ""
                );
                return;
            }

            mapAndroidInstaller(installerPackage);

        } catch (Throwable throwable) {
            String message = throwable.getMessage();

            setCached(
                InstallSource.Error,
                "error",
                message != null ? message : throwable.toString()
            );
        }
    }

    private void mapAndroidInstaller(String installerPackage) {
        String lowerInstaller = installerPackage.toLowerCase();

        if ("com.android.vending".equals(installerPackage)) {
            setCached(
                InstallSource.GooglePlay,
                "google_play",
                installerPackage
            );
            return;
        }

        // Confirm this value from a real Epic Android install.
        // Keeping the contains("epic") fallback helps during early testing.
        if ("com.epicgames.portal".equals(installerPackage)
                || lowerInstaller.contains("epic")) {
            setCached(
                InstallSource.EpicAndroid,
                "epic_android",
                installerPackage
            );
            return;
        }

        setCached(
            InstallSource.AndroidOther,
            "android_other",
            installerPackage
        );
    }

    private void setCached(InstallSource source, String name, String raw) {
        cachedSource = source;
        cachedName = name != null ? name : "unknown";
        cachedRaw = raw != null ? raw : "";
    }
}