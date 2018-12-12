#include <gtest/gtest.h>
#include <string>
#include "day2part2.hpp"
#include "input.hpp"

const std::string example_box_ids{
R"(abcde
fghij
klmno
pqrst
fguij
axcye
wvxyz)"
};

TEST(Day2Part2, abcde_axcye) {
  // The IDs abcde and axcye are close, but they differ by two characters (the second and fourth).
  ASSERT_EQ(std::string{"ace"}, compare_box_ids(std::string{"abcde"}, std::string{"axcye"}));
}

TEST(Day2Part2, fghij_fguij) {
  // However, the IDs fghij and fguij differ by exactly one character, the third (h and u).
  ASSERT_EQ(std::string{"fgij"}, compare_box_ids(std::string{"fghij"}, std::string{"fguij"}));
}

TEST(Day2Part2, day2part2) {
  ASSERT_EQ(std::string{"fgij"}, day2part2(input(example_box_ids)));
}
