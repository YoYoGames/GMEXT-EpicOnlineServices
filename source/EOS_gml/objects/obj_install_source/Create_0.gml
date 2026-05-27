// obj_install_source_demo: Create Event

install_source_ready = false;
install_source_success = false;
install_source_enum = InstallSource.Unknown;
install_source_name = "checking...";
install_source_raw = "";

show_debug_message("[InstallSource] Requesting install source...");

install_source_request(function(_success, _source, _name, _raw) {
    install_source_ready = true;
    install_source_success = _success;
    install_source_enum = _source;
    install_source_name = _name;
    install_source_raw = _raw;

    show_debug_message("[InstallSource] success = " + string(_success));
    show_debug_message("[InstallSource] source enum = " + string(_source));
    show_debug_message("[InstallSource] source name = " + string(_name));
    show_debug_message("[InstallSource] raw = " + string(_raw));

    switch (_source) {
        case InstallSource.GooglePlay:
            show_debug_message("[InstallSource] Use Google Play Billing.");
            break;

        case InstallSource.EpicAndroid:
            show_debug_message("[InstallSource] Use Epic Android flow.");
            break;

        case InstallSource.IOSAppStore:
            show_debug_message("[InstallSource] Use Apple StoreKit flow.");
            break;

        case InstallSource.IOSTestFlight:
            show_debug_message("[InstallSource] Running from TestFlight.");
            break;

        case InstallSource.IOSMarketplace:
            show_debug_message("[InstallSource] Use iOS alternative marketplace / Epic flow.");
            break;

        case InstallSource.AndroidSideload:
            show_debug_message("[InstallSource] Android sideload or unknown installer.");
            break;

        case InstallSource.AndroidOther:
            show_debug_message("[InstallSource] Android other installer: " + string(_raw));
            break;

        case InstallSource.IOSOther:
            show_debug_message("[InstallSource] iOS other distributor.");
            break;

        case InstallSource.Unsupported:
            show_debug_message("[InstallSource] Unsupported on this OS/version/build.");
            break;

        case InstallSource.Error:
            show_debug_message("[InstallSource] Error: " + string(_raw));
            break;

        default:
            show_debug_message("[InstallSource] Unknown install source.");
            break;
    }
});

