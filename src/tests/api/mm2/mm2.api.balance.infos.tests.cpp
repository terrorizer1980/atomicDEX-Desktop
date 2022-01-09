#include "doctest/doctest.h"
#include <nlohmann/json.hpp>

#include "atomicdex/api/mm2/balance.infos.hpp"

TEST_CASE("mm2::api::balance_infos deserialization")
{
    const nlohmann::json json = R"(
    {
       "balances":{
           "spendable":"0.11398301",
           "unspendable":"0.00001"
       }
    })"_json;
    mm2::api::balance_infos infos;
    mm2::api::from_json(json.at("balances"), infos);
    CHECK_EQ(infos.spendable, "0.11398301");
    CHECK_EQ(infos.unspendable, "0.00001");
}