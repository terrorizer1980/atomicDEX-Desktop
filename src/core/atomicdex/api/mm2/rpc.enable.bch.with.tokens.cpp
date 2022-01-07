//
// Created by milerius on 07/01/2022.
//

//! Dependencies
#include <nlohmann/json.hpp>

//! Project Headers
#include "rpc.enable.bch.with.tokens.hpp"

namespace mm2::api
{
    void
    to_json(nlohmann::json& j, const slp_token_request& cfg)
    {
        j["ticker"] = cfg.ticker;
        if (cfg.required_confirmations.has_value())
        {
            j["required_confirmations"] = cfg.required_confirmations.value();
        }
    }
}