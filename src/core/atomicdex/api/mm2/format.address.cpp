//
// Created by milerius on 07/01/2022.
//

//! Dependencies Headers
#include <nlohmann/json.hpp>

//! Project Headers
#include "format.address.hpp"

namespace mm2::api
{
    void
    to_json(nlohmann::json& j, const format_address& cfg)
    {
        j["format"] = cfg.format;
        j["network"] = cfg.network;
    }
}