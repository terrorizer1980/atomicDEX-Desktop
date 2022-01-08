#pragma once

#include <nlohmann/json_fwd.hpp>

namespace mm2::api
{
    struct slp_activation_params
    {
        std::optional<std::size_t> required_confirmations;
    };

    void to_json(nlohmann::json& j, const slp_activation_params& cfg);

    struct enable_slp_request
    {
        std::string ticker;
        std::optional<slp_activation_params> activation_params;
    };

    void to_json(nlohmann::json& j, const enable_slp_request& cfg);
}