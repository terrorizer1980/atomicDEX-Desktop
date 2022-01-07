//
// Created by milerius on 07/01/2022.
//

//! Deps
#include "doctest/doctest.h"
#include <nlohmann/json.hpp>

#include "atomicdex/api/mm2/mm2.hpp"
#include "atomicdex/api/mm2/rpc.enable.bch.with.tokens.hpp"

TEST_CASE("mm2::api::enable_bch_with_tokens serialisation slp tickers with confirmations")
{
    const nlohmann::json        expected_json = R"(
    {
        "ticker":"USDF",
        "required_confirmations": 4
    }
    )"_json;
    mm2::api::slp_token_request request{.ticker = "USDF", .required_confirmations = 4};
    nlohmann::json              j;
    mm2::api::to_json(j, request);
    CHECK_EQ(j, expected_json);
}

TEST_CASE("mm2::api::enable_bch_with_tokens serialisation slp tickers without confirmations")
{
    const nlohmann::json        expected_json = R"(
    {
        "ticker":"USDF"
    }
    )"_json;
    mm2::api::slp_token_request request{.ticker = "USDF"};
    nlohmann::json              j;
    mm2::api::to_json(j, request);
    CHECK_EQ(j, expected_json);
}

TEST_CASE("mm2::api::enable_bch_with_tokens serialisation servers")
{
    const nlohmann::json      expected_json = R"(
   {
    "servers":[
      {
        "url":"electroncash.de:50003",
        "disable_cert_verification": false,
        "protocol":"TCP"
      },
      {
        "url":"tbch.loping.net:60001",
        "disable_cert_verification": false,
        "protocol":"TCP"
      },
      {
        "url":"blackie.c3-soft.com:60001",
        "disable_cert_verification": false,
        "protocol":"TCP"
      },
      {
        "url":"bch0.kister.net:51001",
        "disable_cert_verification": false,
        "protocol":"TCP"
      },
      {
        "url":"testnet.imaginary.cash:50001",
        "disable_cert_verification": false,
        "protocol":"TCP"
      }
    ]
   }
    )"_json;
    mm2::api::enable_rpc_data request{
        .servers = {
            atomic_dex::electrum_server{.url = "electroncash.de:50003"}, atomic_dex::electrum_server{.url = "tbch.loping.net:60001"},
            atomic_dex::electrum_server{.url = "blackie.c3-soft.com:60001"}, atomic_dex::electrum_server{.url = "bch0.kister.net:51001"},
            atomic_dex::electrum_server{.url = "testnet.imaginary.cash:50001"}}};
    nlohmann::json j;
    mm2::api::to_json(j, request);
    CHECK_EQ(j, expected_json);
}

TEST_CASE("mm2::api::enable_bch_with_tokens serialisation mode")
{
    const nlohmann::json      expected_json = R"(
    {
            "rpc":"Electrum",
            "rpc_data":{
                "servers":[
                  {
                    "url":"electroncash.de:50003",
                    "disable_cert_verification": false,
                    "protocol":"TCP"
                  },
                  {
                    "url":"tbch.loping.net:60001",
                    "disable_cert_verification": false,
                    "protocol":"TCP"
                  },
                  {
                    "url":"blackie.c3-soft.com:60001",
                    "disable_cert_verification": false,
                    "protocol":"TCP"
                  },
                  {
                    "url":"bch0.kister.net:51001",
                    "disable_cert_verification": false,
                    "protocol":"TCP"
                  },
                  {
                    "url":"testnet.imaginary.cash:50001",
                    "disable_cert_verification": false,
                    "protocol":"TCP"
                  }
                ]
            }
    }
    )"_json;
    mm2::api::enable_rpc_data enable_rpc_data{
        .servers = {
            atomic_dex::electrum_server{.url = "electroncash.de:50003"}, atomic_dex::electrum_server{.url = "tbch.loping.net:60001"},
            atomic_dex::electrum_server{.url = "blackie.c3-soft.com:60001"}, atomic_dex::electrum_server{.url = "bch0.kister.net:51001"},
            atomic_dex::electrum_server{.url = "testnet.imaginary.cash:50001"}}};
    mm2::api::enable_mode request{.rpc = "Electrum", .rpc_data = std::move(enable_rpc_data)};
    nlohmann::json        j;
    mm2::api::to_json(j, request);
    CHECK_EQ(j, expected_json);
}

TEST_CASE("mm2::api::enable_bch_with_tokens serialisation")
{
    const nlohmann::json expected_json = R"(
    {
        "method":"enable_bch_with_tokens",
        "mmrpc":"2.0",
        "userpass":"",
        "params": {
            "allow_slp_unsafe_conf": false,
            "bchd_urls": [
                "https://bchd-testnet.greyh.at:18335"
            ],
            "mode": {
                "rpc": "Electrum",
                "rpc_data": {
                "servers": [
                      {
                        "disable_cert_verification": false,
                        "protocol": "TCP",
                        "url": "electroncash.de:50003"
                      },
                      {
                        "disable_cert_verification": false,
                        "protocol": "TCP",
                        "url": "tbch.loping.net:60001"
                      },
                      {
                        "disable_cert_verification": false,
                        "protocol": "TCP",
                        "url": "blackie.c3-soft.com:60001"
                      },
                      {
                        "disable_cert_verification": false,
                        "protocol": "TCP",
                        "url": "bch0.kister.net:51001"
                      },
                      {
                        "disable_cert_verification": false,
                        "protocol": "TCP",
                        "url": "testnet.imaginary.cash:50001"
                      }
                    ]
                }
            },
            "slp_tokens_requests": [
                {
                "required_confirmations": 4,
                "ticker": "USDF"
                }
            ],
            "ticker": "tBCH",
            "tx_history": true
        }
    }
    )"_json;

    nlohmann::json            j         = mm2::api::template_request("enable_bch_with_tokens", true);
    std::vector<std::string>  bchd_urls = std::vector<std::string>{"https://bchd-testnet.greyh.at:18335"};
    mm2::api::enable_rpc_data enable_rpc_data{
        .servers = {
            atomic_dex::electrum_server{.url = "electroncash.de:50003"}, atomic_dex::electrum_server{.url = "tbch.loping.net:60001"},
            atomic_dex::electrum_server{.url = "blackie.c3-soft.com:60001"}, atomic_dex::electrum_server{.url = "bch0.kister.net:51001"},
            atomic_dex::electrum_server{.url = "testnet.imaginary.cash:50001"}}};
    mm2::api::enable_mode                        mode{.rpc = "Electrum", .rpc_data = std::move(enable_rpc_data)};
    mm2::api::slp_token_request                  slp_tokens{.ticker = "USDF", .required_confirmations = 4};
    atomic_dex::t_enable_bch_with_tokens_request request{
        .ticker = "tBCH",
        .allow_slp_unsafe_conf = false,
        .bchd_urls = std::move(bchd_urls),
        .mode = std::move(mode),
        .tx_history = true, .slp_token_requests = {std::move(slp_tokens)}};
    mm2::api::to_json(j, request);
    CHECK_EQ(j, expected_json);
}