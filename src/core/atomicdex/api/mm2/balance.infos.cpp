//
// Created by milerius on 09/01/2022.
//

#include <nlohmann/json.hpp>

// Project Headers
#include "balance.infos.hpp"

namespace mm2::api
{
    void
    from_json(const nlohmann::json& j, balance_infos& answer)
    {
        answer.spendable = j.at("spendable").get<std::string>();
        answer.unspendable = j.at("unspendable").get<std::string>();
    }
}