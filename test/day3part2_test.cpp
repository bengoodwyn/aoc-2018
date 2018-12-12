#include <gtest/gtest.h>
#include "day3part2.hpp"
#include "input.hpp"

const std::string example{
R"(#1 @ 1,3: 4x4
#2 @ 3,1: 4x4
#3 @ 5,5: 2x2)"
};

TEST(Day3Part2, Example) {
  ASSERT_EQ(3, day3part2(input(example)));
}
