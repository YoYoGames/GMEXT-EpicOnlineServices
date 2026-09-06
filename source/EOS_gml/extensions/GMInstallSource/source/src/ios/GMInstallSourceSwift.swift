import Foundation
import CxxStdlib

#if canImport(MarketplaceKit)
import MarketplaceKit
#endif

public class GMInstallSourceSwift: GMInstallSourceInternalSwift
{
    private var cachedSource: InstallSource = InstallSource.Unknown
    private var cachedName: String = "unknown"
    private var cachedRaw: String = ""

    public override init()
    {
        super.init()
    }

    public override func install_source_request(callback: GMFunction)
    {
        #if canImport(MarketplaceKit)

        if #available(iOS 17.4, *) {
            Task {
                do {
                    let distributor = try await AppDistributor.current
                    let result = self.mapIOSDistributor(distributor)

                    self.cachedSource = result.source
                    self.cachedName = result.name
                    self.cachedRaw = result.raw

                    callback.call(
                        true,
                        result.source.rawValue,
                        result.name,
                        result.raw
                    )
                } catch {
                    self.cachedSource = InstallSource.Error
                    self.cachedName = "error"
                    self.cachedRaw = String(describing: error)

                    callback.call(
                        false,
                        InstallSource.Error.rawValue,
                        self.cachedName,
                        self.cachedRaw
                    )
                }
            }
        } else {
            cachedSource = InstallSource.Unsupported
            cachedName = "unsupported"
            cachedRaw = "MarketplaceKit requires iOS 17.4+"

            callback.call(
                false,
                InstallSource.Unsupported.rawValue,
                cachedName,
                cachedRaw
            )
        }

        #else

        cachedSource = InstallSource.Unsupported
        cachedName = "unsupported"
        cachedRaw = "MarketplaceKit is unavailable in this build"

        callback.call(
            false,
            InstallSource.Unsupported.rawValue,
            cachedName,
            cachedRaw
        )

        #endif
    }

    public override func install_source_get_cached() -> InstallSource
    {
        return cachedSource
    }

    public override func install_source_get_cached_name() -> String
    {
        return cachedName
    }

    public override func install_source_get_cached_raw() -> String
    {
        return cachedRaw
    }

    #if canImport(MarketplaceKit)
    @available(iOS 17.4, *)
    private func mapIOSDistributor(_ distributor: AppDistributor) -> (source: InstallSource, name: String, raw: String)
    {
        switch distributor {
        case .appStore:
            return (
                InstallSource.IOSAppStore,
                "ios_app_store",
                "appStore"
            )

        case .testFlight:
            return (
                InstallSource.IOSTestFlight,
                "ios_testflight",
                "testFlight"
            )

        case .marketplace(let bundleId):
            return (
                InstallSource.IOSMarketplace,
                "ios_marketplace",
                bundleId
            )

        case .other:
            return (
                InstallSource.IOSOther,
                "ios_other",
                "other"
            )

        @unknown default:
            return (
                InstallSource.Unknown,
                "unknown",
                "unknown"
            )
        }
    }
    #endif
}

