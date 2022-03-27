#include <gtest/gtest.h>


// Google Test is a C++ framework -> use extern "C" to include C header files
extern "C" {
#include "../src/hysteresis.h"
}

TEST(hysteresisTest, Init) {
    unsigned int level = hysteresis(0);
    EXPECT_EQ(level, 0);
}

TEST(hysteresisTest, Up) {
    unsigned int level;
    level = hysteresis(14);
    EXPECT_EQ(level, 0);

    level = hysteresis(16);
    EXPECT_EQ(level, 1);

    level = hysteresis(41);
    EXPECT_EQ(level, 2);

    level = hysteresis(66);
    EXPECT_EQ(level, 3);

    level = hysteresis(91);
    EXPECT_EQ(level, 4);
}

TEST(hysteresisTest, Down) {
    unsigned int level;
    level = hysteresis(86);
    EXPECT_EQ(level, 4);

    level = hysteresis(84);
    EXPECT_EQ(level, 3);

    level = hysteresis(59);
    EXPECT_EQ(level, 2);

    level = hysteresis(34);
    EXPECT_EQ(level, 1);

    level = hysteresis(9);
    EXPECT_EQ(level, 0);
}

TEST(hysteresisTest, Thresholds) {
    unsigned int level;
    level = hysteresis(15);
    EXPECT_EQ(level, 1);

    level = hysteresis(40);
    EXPECT_EQ(level, 2);

    level = hysteresis(65);
    EXPECT_EQ(level, 3);

    level = hysteresis(90);
    EXPECT_EQ(level, 4);

    level = hysteresis(85);
    EXPECT_EQ(level, 3);

    level = hysteresis(60);
    EXPECT_EQ(level, 2);

    level = hysteresis(35);
    EXPECT_EQ(level, 1);

    level = hysteresis(10);
    EXPECT_EQ(level, 0);
}

TEST(hysteresisTest, SameLevel) {
    unsigned int level;
    level = hysteresis(0);
    EXPECT_EQ(level, 0);
    level = hysteresis(14);
    EXPECT_EQ(level, 0);

    level = hysteresis(16);
    EXPECT_EQ(level, 1);
    level = hysteresis(39);
    EXPECT_EQ(level, 1);

    level = hysteresis(41);
    EXPECT_EQ(level, 2);
    level = hysteresis(64);
    EXPECT_EQ(level, 2);

    level = hysteresis(66);
    EXPECT_EQ(level, 3);
    level = hysteresis(89);
    EXPECT_EQ(level, 3);

    level = hysteresis(91);
    EXPECT_EQ(level, 4);
    level = hysteresis(100);
    EXPECT_EQ(level, 4);
}

TEST(hysteresisTest, Jumps) {
    unsigned int level;
    level = hysteresis(16);
    EXPECT_EQ(level, 1);

    level = hysteresis(75);
    EXPECT_EQ(level, 3);

    level = hysteresis(5);
    EXPECT_EQ(level, 0);

    level = hysteresis(100);
    EXPECT_EQ(level, 4);

    level = hysteresis(50);
    EXPECT_EQ(level, 2);

    level = hysteresis(91);
    EXPECT_EQ(level, 4);

    level = hysteresis(25);
    EXPECT_EQ(level, 1);
}