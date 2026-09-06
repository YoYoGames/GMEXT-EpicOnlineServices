// obj_install_source_demo: Draw GUI Event

var _x = 32;
var _y = 32;
var _line = 28;

draw_set_halign(fa_left);
draw_set_valign(fa_top);

draw_text(_x, _y, "Install Source Demo");
_y += _line * 2;

draw_text(_x, _y, "Ready: " + string(install_source_ready));
_y += _line;

draw_text(_x, _y, "Success: " + string(install_source_success));
_y += _line;

draw_text(_x, _y, "Enum: " + string(install_source_enum));
_y += _line;

draw_text(_x, _y, "Name: " + string(install_source_name));
_y += _line;

draw_text(_x, _y, "Raw: " + string(install_source_raw));
_y += _line * 2;

if (install_source_ready) {
    switch (install_source_enum) {
        case InstallSource.GooglePlay:
            draw_text(_x, _y, "Decision: Google Play Billing");
            break;

        case InstallSource.EpicAndroid:
            draw_text(_x, _y, "Decision: Epic Android flow");
            break;

        case InstallSource.IOSAppStore:
            draw_text(_x, _y, "Decision: Apple StoreKit");
            break;

        case InstallSource.IOSMarketplace:
            draw_text(_x, _y, "Decision: iOS Marketplace / Epic flow");
            break;

        case InstallSource.IOSTestFlight:
            draw_text(_x, _y, "Decision: TestFlight/debug behavior");
            break;

        case InstallSource.AndroidSideload:
            draw_text(_x, _y, "Decision: Sideload fallback");
            break;

        case InstallSource.Unsupported:
            draw_text(_x, _y, "Decision: Unsupported fallback");
            break;

        case InstallSource.Error:
            draw_text(_x, _y, "Decision: Error fallback");
            break;

        default:
            draw_text(_x, _y, "Decision: Unknown fallback");
            break;
    }
} else {
    draw_text(_x, _y, "Decision: Waiting...");
}

