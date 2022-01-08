//
// Created by milerius on 08/01/2022.
//

// Dependencies
#include <nlohmann/json.hpp>

// Project headers
#include "rpc.enable.slp.hpp"

namespace mm2::api
{
    void
    to_json(nlohmann::json& j, const slp_activation_params& cfg)
    {
        if (cfg.required_confirmations.has_value())
        {
            j["required_confirmations"] = cfg.required_confirmations.value();
        }
    }
    void
    to_json(nlohmann::json& j, const enable_slp_request& cfg)
    {
        nlohmann::json obj = nlohmann::json::object();
        obj["ticker"] = cfg.ticker;
        if (cfg.activation_params.has_value())
        {
            obj["activation_params"] = cfg.activation_params.value();
        }
        if (j.contains("mmrpc") && j.at("mmrpc").get<std::string>() == "2.0")
        {
            j["params"] = obj;
        }
    }
} // namespace mm2::api