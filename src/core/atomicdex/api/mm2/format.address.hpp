#pragma once

//! STD
#include <string>

//! Dependencies Headers
#include <nlohmann/json_fwd.hpp>

namespace mm2::api
{
    struct format_address
    {
        std::string format;
        std::string network;
    };

    void to_json(nlohmann::json& j, const format_address& cfg);
}