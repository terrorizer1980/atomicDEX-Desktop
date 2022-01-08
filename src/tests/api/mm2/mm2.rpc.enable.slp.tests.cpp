//
// Created by milerius on 08/01/2022.
//

//! Deps
#include "doctest/doctest.h"
#include <nlohmann/json.hpp>

#include "atomicdex/api/mm2/mm2.hpp"
#include "atomicdex/api/mm2/rpc.enable.slp.hpp"

TEST_CASE("mm2::api::enable_slp serialisation activation params")
{
    const nlohmann::json        expected_json = R"(
    {
        "required_confirmations": 4
    }
    )"_json;
    mm2::api::slp_activation_params request{.required_confirmations = 4};
    nlohmann::json              j;
    mm2::api::to_json(j, request);
    CHECK_EQ(j, expected_json);
}

TEST_CASE("mm2::api::enable_slp serialisation")
{
    const nlohmann::json        expected_json = R"(
    {
        "method":"enable_slp",
        "mmrpc":"2.0",
        "userpass":"",
        "params":{
            "ticker":"USDF",
            "activation_params": {
              "required_confirmations": 4
            }
        }
    }
    )"_json;
    mm2::api::enable_slp_request request{.ticker = "USDF", .activation_params = mm2::api::slp_activation_params{.required_confirmations = 4}};
    nlohmann::json              j = mm2::api::template_request("enable_slp", true);
    mm2::api::to_json(j, request);
    CHECK_EQ(j, expected_json);
}