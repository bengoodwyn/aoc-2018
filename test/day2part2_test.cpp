#include <gtest/gtest.h>
#include <array>
#include <string_view>
#include "day2part2.hpp"

constexpr std::array<const std::string_view,7> example_box_ids{
  "abcde",
  "fghij",
  "klmno",
  "pqrst",
  "fguij",
  "axcye",
  "wvxyz"
};

TEST(Day2Part2, abcde_axcye) {
  // The IDs abcde and axcye are close, but they differ by two characters (the second and fourth).
  ASSERT_EQ(std::string{"ace"}, compare_box_ids(example_box_ids[0], example_box_ids[5]));
}

TEST(Day2Part2, fghij_fguij) {
  // However, the IDs fghij and fguij differ by exactly one character, the third (h and u).
  ASSERT_EQ(std::string{"fgij"}, compare_box_ids(example_box_ids[1], example_box_ids[4]));
}

TEST(Day2Part2, no_match) {
  ASSERT_FALSE(day2part2(std::array<const std::string_view,0>{}).has_value());
}

TEST(Day2Part2, day2part2) {
  ASSERT_EQ(std::string{"fgij"}, day2part2(example_box_ids));
}
