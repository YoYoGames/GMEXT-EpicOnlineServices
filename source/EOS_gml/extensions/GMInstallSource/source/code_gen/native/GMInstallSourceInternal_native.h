// ##### extgen :: Auto-generated file do not edit!! #####

#pragma once
#include <cstdint>
#include <string_view>
#include <vector>
#include <array>
#include <optional>
#include "core/GMExtWire.h"

namespace gm_consts
{
}


namespace gm_enums
{
    enum class InstallSource : std::uint32_t
    {
        Unknown = 0,
        GooglePlay = 1,
        EpicAndroid = 2,
        AndroidOther = 3,
        AndroidSideload = 4,
        IOSAppStore = 5,
        IOSTestFlight = 6,
        IOSMarketplace = 7,
        IOSOther = 8,
        Unsupported = 9,
        Error = 10
    };

}


namespace gm_structs
{

}

namespace gm::wire::codec
{
}

namespace gm::wire::details
{
}

void install_source_request(const gm::wire::GMFunction& callback);
gm_enums::InstallSource install_source_get_cached();
std::string install_source_get_cached_name();
std::string install_source_get_cached_raw();
