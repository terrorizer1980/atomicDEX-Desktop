//
// Created by milerius on 07/01/2022.
//

//! Deps
#include "doctest/doctest.h"
#include <nlohmann/json.hpp>

#include "atomicdex/api/mm2/rpc.enable.bch.with.tokens.hpp"

TEST_CASE("mm2::api::enable_bch_with_tokens serialisation slp tickers with confirmations")
{
    const nlohmann::json     expected_json = R"(
    {
        "ticker":"USDF",
        "required_confirmations": 4
    }
    )"_json;
    mm2::api::slp_token_request request{.ticker = "USDF", .required_confirmations = 4};
    nlohmann::json           j;
    mm2::api::to_json(j, request);
    CHECK_EQ(j, expected_json);
}

TEST_CASE("mm2::api::enable_bch_with_tokens serialisation slp tickers without confirmations")
{
    const nlohmann::json     expected_json = R"(
    {
        "ticker":"USDF"
    }
    )"_json;
    mm2::api::slp_token_request request{.ticker = "USDF"};
    nlohmann::json           j;
    mm2::api::to_json(j, request);
    CHECK_EQ(j, expected_json);
}