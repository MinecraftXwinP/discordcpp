#include <gtest/gtest.h>

#include "persistent_state.hpp"
#include <cstdio>

#define TEST_STATE_FILE "persistent_state_test.cbor"

namespace {

    class PersistentState: public ::testing::Test {
        void TearDown() {
            remove(TEST_STATE_FILE);
        }
    };

    TEST_F(PersistentState, SaveAndLoad) {
        {
            discordcpp::persistent_state to_save(TEST_STATE_FILE);
            to_save["testKey"] = "aString";
            to_save.save();
        }
        discordcpp::persistent_state to_load(TEST_STATE_FILE);
        to_load.load();
        ASSERT_EQ("aString", to_load["testKey"]);
    }

    TEST_F(PersistentState, WontCrashIfElementNotExists) {
        discordcpp::persistent_state s(TEST_STATE_FILE);
        ASSERT_NO_FATAL_FAILURE(s["randomKey"]);
    }
}