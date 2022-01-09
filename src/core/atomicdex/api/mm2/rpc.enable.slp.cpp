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
        obj["ticker"]      = cfg.ticker;
        if (cfg.activation_params.has_value())
        {
            obj["activation_params"] = cfg.activation_params.value();
        }
        if (j.contains("mmrpc") && j.at("mmrpc").get<std::string>() == "2.0")
        {
            j["params"] = obj;
        }
    }

    void
    from_json(const nlohmann::json& j, enable_slp_answer_success& answer)
    {
        answer.token_id               = j.at("token_id").get<std::string>();
        answer.platform_coin          = j.at("platform_coin").get<std::string>();
        answer.balances               = j.at("balances").get<std::unordered_map<std::string, balance_infos>>();
        answer.required_confirmations = j.at("required_confirmations").get<std::size_t>();
    }

    void
    from_json(const nlohmann::json& j, enable_slp_answer& answer)
    {
        if (j.count("error") >= 1)
        {
            answer.error = j;
        }
        else
        {
            if (j.contains("result") && j.contains("mmrpc") && j.at("mmrpc").get<std::string>() == "2.0")
            {
                answer.result = j.at("result").get<enable_slp_answer_success>();
            }
        }
    }
} // namespace mm2::api