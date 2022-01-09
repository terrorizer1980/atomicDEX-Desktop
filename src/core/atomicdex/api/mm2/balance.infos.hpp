#pragma once

#include <nlohmann/json_fwd.hpp>

namespace mm2::api
{
    struct balance_infos
    {
        std::string spendable;
        std::string unspendable;
    };

    void from_json(const nlohmann::json& j, balance_infos& answer);
}