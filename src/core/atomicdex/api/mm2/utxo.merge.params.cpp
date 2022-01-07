//
// Created by milerius on 07/01/2022.
//

//! Dependencies Headers
#include <nlohmann/json.hpp>

//! Project Headers
#include "utxo.merge.params.hpp"

namespace mm2::api
{
    void
    to_json(nlohmann::json& j, const utxo_merge_params& cfg)
    {
        j["merge_at"] = cfg.merge_at;
        j["check_every"] = cfg.check_every;
        j["max_merge_at_once"] = cfg.max_merge_at_once;
    }
}