#pragma once

#include <nlohmann/json_fwd.hpp>

namespace mm2::api
{
    struct utxo_merge_params
    {
        std::size_t merge_at;
        std::size_t check_every;
        std::size_t max_merge_at_once;
    };

    void to_json(nlohmann::json& j, const utxo_merge_params& cfg);
}