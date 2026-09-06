// ##### extgen :: Auto-generated file do not edit!! #####

package ${YYAndroidPackageName}.enums;

public enum InstallSource
{
    Unknown((int)0),
    GooglePlay((int)1),
    EpicAndroid((int)2),
    AndroidOther((int)3),
    AndroidSideload((int)4),
    IOSAppStore((int)5),
    IOSTestFlight((int)6),
    IOSMarketplace((int)7),
    IOSOther((int)8),
    Unsupported((int)9),
    Error((int)10);

    private final int value;
    private InstallSource(int v)
    {
        this.value = v;
    }
    public int value()
    {
        return this.value;
    }
    public static InstallSource from(int v)
    {
        switch (v)
        {
            case 0:
                return InstallSource.Unknown;
            case 1:
                return InstallSource.GooglePlay;
            case 2:
                return InstallSource.EpicAndroid;
            case 3:
                return InstallSource.AndroidOther;
            case 4:
                return InstallSource.AndroidSideload;
            case 5:
                return InstallSource.IOSAppStore;
            case 6:
                return InstallSource.IOSTestFlight;
            case 7:
                return InstallSource.IOSMarketplace;
            case 8:
                return InstallSource.IOSOther;
            case 9:
                return InstallSource.Unsupported;
            case 10:
                return InstallSource.Error;
            default:
                throw new IllegalArgumentException("Unknown InstallSource value: " + v);
        }
    }
}