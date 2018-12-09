#include <gtest/gtest.h>
#include "day1part1.hpp"
#include "input.hpp"

TEST(Day1Part1, ZeroZeroZero) {
  ASSERT_EQ(0, resulting_frequency(0, 0));
}

TEST(Day1Part1, ZeroPlusOneIsOne) {
  // Current frequency  0, change of +1; resulting frequency  1.
  ASSERT_EQ(1, resulting_frequency(0, 1));
}

TEST(Day1Part1, OneMinusTwoIsMinusOne) {
  // Current frequency  1, change of -2; resulting frequency -1.
  ASSERT_EQ(-1, resulting_frequency(1, -2));
}

TEST(Day1Part1, MinusOnePlusThreeIsTwo) {
  // Current frequency -1, change of +3; resulting frequency  2.
  ASSERT_EQ(2, resulting_frequency(-1, 3));
}

TEST(Day1Part1, TwoPlusOneIsThree) {
  // Current frequency  2, change of +1; resulting frequency  3.
  ASSERT_EQ(3, resulting_frequency(2, 1));
}

TEST(Day1Part1, InThisExampleTheResultingFrequencyIs3) {
  // For example, if the device displays frequency changes of +1, -2, +3, +1,
  // In this example, the resulting frequency is 3.
  ASSERT_EQ(3, day1part1(input("+1\n-2\n+3\n+1")));
}

TEST(Day1Part1, ExampleResultsIn3) {
  // +1, +1, +1 results in  3
  ASSERT_EQ(3, day1part1(input("+1\n+1\n+1")));
}

TEST(Day1Part1, ExampleResultsIn0) {
  // +1, +1, -2 results in  0
  ASSERT_EQ(0, day1part1(input("+1\n+1\n-2")));
}

TEST(Day1Part1, ExampleResultsInMinus6) {
  // -1, -2, -3 results in -6
  ASSERT_EQ(-6, day1part1(input("-1\n-2\n-3")));
}
