//
// Created by milerius on 07/01/2022.
//

//! Deps
#include "doctest/doctest.h"
#include <nlohmann/json.hpp>

#include "atomicdex/api/mm2/utxo.merge.params.hpp"

TEST_CASE("mm2::api::utxo_merge_params serialisation")
{
    const nlohmann::json     expected_json = R"(
    {
      "merge_at":50,
      "check_every":10,
      "max_merge_at_once":25
    }
    )"_json;
    mm2::api::utxo_merge_params request{.merge_at = 50, .check_every = 10, .max_merge_at_once = 25};
    nlohmann::json           j;
    mm2::api::to_json(j, request);
    CHECK_EQ(j, expected_json);
}