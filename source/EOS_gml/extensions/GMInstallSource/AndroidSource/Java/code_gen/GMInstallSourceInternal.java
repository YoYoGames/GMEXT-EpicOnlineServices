// ##### extgen :: Auto-generated file do not edit!! #####

package ${YYAndroidPackageName};

import java.nio.ByteBuffer;
import java.util.*;
import ${YYAndroidPackageName}.GMExtWire;
import ${YYAndroidPackageName}.GMExtWire.GMFunction;
import ${YYAndroidPackageName}.GMExtWire.GMValue;
import ${YYAndroidPackageName}.enums.*;

public abstract class GMInstallSourceInternal extends RunnerSocial implements GMInstallSourceInterface {

    private final GMExtWire.DispatchQueue __dispatch_queue = new GMExtWire.DispatchQueue();
    public double __EXT_NATIVE__GMInstallSource_invocation_handler(ByteBuffer __ret_buffer, double __ret_buffer_length)
    {
        return __dispatch_queue.fetch(__ret_buffer);
    }

    public double __EXT_NATIVE__install_source_request(ByteBuffer __arg_buffer, double __arg_buffer_length)
    {
        GMExtWire.order(__arg_buffer);

        // field: callback, type: Function
        GMFunction callback = GMExtWire.readGMFunction(__arg_buffer, __dispatch_queue);

        install_source_request(callback);
        return 0;
    }

    public double __EXT_NATIVE__install_source_get_cached(ByteBuffer __ret_buffer, double __ret_buffer_length)
    {
        InstallSource __result = install_source_get_cached();

        GMExtWire.order(__ret_buffer);
        // return: __result, type: enum InstallSource
        GMExtWire.writeI32(__ret_buffer, __result.value());

        return 0;
    }

    public String __EXT_NATIVE__install_source_get_cached_name()
    {
        String __result = install_source_get_cached_name();
        return __result;
    }

    public String __EXT_NATIVE__install_source_get_cached_raw()
    {
        String __result = install_source_get_cached_raw();
        return __result;
    }

}