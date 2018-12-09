#include <gtest/gtest.h>
#include "day1part2.hpp"
#include "input.hpp"

TEST(Day1Part2, InThisExampleTheResultingFrequencyIs2) {
  // For example, using the same list of changes above,
  // the first frequency reached twice is 2.
  ASSERT_EQ(2, day1part2(input("+1\n-2\n+3\n+1")));
}

TEST(Day1Part2, FirstReaches0Twice) {
  // +1, -1 first reaches 0 twice.
  ASSERT_EQ(0, day1part2(input("+1\n-1")));
}

TEST(Day1Part2, FirstReaches10Twice) {
  // +3, +3, +4, -2, -4 first reaches 10 twice.
  ASSERT_EQ(10, day1part2(input("+3\n+3\n+4\n-2\n-4")));
}

TEST(Day1Part2, FirstReaches5Twice) {
  // -6, +3, +8, +5, -6 first reaches 5 twice.
  ASSERT_EQ(5, day1part2(input("-6\n+3\n+8\n+5\n-6")));
}

TEST(Day1Part2, FirstReaches14Twice) {
  // +7, +7, -2, -7, -4 first reaches 14 twice.
  ASSERT_EQ(14, day1part2(input("+7\n+7\n-2\n-7\n-4")));
}
