//
// Created by milerius on 07/01/2022.
//

//! Deps
#include "doctest/doctest.h"
#include <nlohmann/json.hpp>

#include "atomicdex/api/mm2/format.address.hpp"

TEST_CASE("mm2::api::address_format serialisation")
{
    const nlohmann::json     expected_json = R"(
    {
      "format":"cashaddress",
      "network":"bchtest"
    }
    )"_json;
    mm2::api::format_address request{.format = "cashaddress", .network = "bchtest"};
    nlohmann::json           j;
    mm2::api::to_json(j, request);
    CHECK_EQ(j, expected_json);
}