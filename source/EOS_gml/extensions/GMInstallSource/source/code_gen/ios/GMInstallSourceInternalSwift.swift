import Foundation
import os.log
import CxxStdlib

open class GMInstallSourceInternalSwift
{
    internal var __dispatch_queue: GMDispatchQueue = GMDispatchQueue()

    public init()
    {
    }

    open func install_source_request(callback: GMFunction)
    {
        // default stub for install_source_request
    }

    open func install_source_get_cached() -> InstallSource
    {
        // default stub for install_source_get_cached
        return InstallSource(rawValue: 0)!
    }

    open func install_source_get_cached_name() -> String
    {
        // default stub for install_source_get_cached_name
        return ""
    }

    open func install_source_get_cached_raw() -> String
    {
        // default stub for install_source_get_cached_raw
        return ""
    }

    public func __EXT_SWIFT__install_source_request(_ __arg_buffer: UnsafeMutablePointer<CChar>?, arg1 __arg_buffer_length: Double) -> Double
    {
        do
        {
            var __br = BufferReader(base: UnsafeRawPointer(__arg_buffer!), size: Int(__arg_buffer_length))

            // field: callback, type: Function
            let callback: GMFunction = try __br.readGMFunction(__dispatch_queue)

            self.install_source_request(callback: callback)
            return 0.0
        }
        catch
        {
            os_log("Corrupted buffer when calling 'install_source_request'", log: .default, type: .error)
            return -1
        }
    }

    public func __EXT_SWIFT__install_source_get_cached(_ __ret_buffer: UnsafeMutablePointer<CChar>?, arg1 __ret_buffer_length: Double) -> Double
    {
        do
        {
            let __result = self.install_source_get_cached()
            var __bw = BufferWriter(base: UnsafeMutableRawPointer(__ret_buffer!), size: Int(__ret_buffer_length))

            // return: __result, type: enum InstallSource
            try __bw.writeRaw(__result.rawValue)
            return 0.0
        }
        catch
        {
            os_log("Corrupted buffer when calling 'install_source_get_cached'", log: .default, type: .error)
            return -1
        }
    }

    public func __EXT_SWIFT__install_source_get_cached_name() -> String
    {
        let __result = self.install_source_get_cached_name()
        return __result
    }

    public func __EXT_SWIFT__install_source_get_cached_raw() -> String
    {
        let __result = self.install_source_get_cached_raw()
        return __result
    }

    public func __EXT_SWIFT__GMInstallSource_invocation_handler(_ __ret_buffer: UnsafeMutablePointer<CChar>?, arg1 __ret_buffer_length: Double) -> Double
    {
        var __bw = BufferWriter(base: UnsafeMutableRawPointer(__ret_buffer!), size: Int(__ret_buffer_length))
        return __dispatch_queue.fetch(into: &__bw)
    }

}
