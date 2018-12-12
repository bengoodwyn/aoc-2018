#include <gtest/gtest.h>
#include <array>
#include <string>
#include "day2part1.hpp"
#include "input.hpp"
#include "lines.hpp"

TEST(Day2Part1, abcdef) {
  // abcdef contains no letters that appear exactly two or three times.
  const auto [has_two, has_three] = parse_box_id(std::string{"abcdef"});
  ASSERT_FALSE(has_two);
  ASSERT_FALSE(has_three);
}

TEST(Day2Part1, bababc) {
  // bababc contains two a and three b, so it counts for both.
  const auto [has_two, has_three] = parse_box_id(std::string{"bababc"});
  ASSERT_TRUE(has_two);
  ASSERT_TRUE(has_three);
}
TEST(Day2Part1, abbcde) {
  // abbcde contains two b, but no letter appears exactly three times.
  const auto [has_two, has_three] = parse_box_id(std::string{"abbcde"});
  ASSERT_TRUE(has_two);
  ASSERT_FALSE(has_three);
}
TEST(Day2Part1, abcccd) {
  // abcccd contains three c, but no letter appears exactly two times.
  const auto [has_two, has_three] = parse_box_id(std::string{"abcccd"});
  ASSERT_FALSE(has_two);
  ASSERT_TRUE(has_three);
}
TEST(Day2Part1, aabcdd) {
  // aabcdd contains two a and two d, but it only counts once.
  const auto [has_two, has_three] = parse_box_id(std::string{"aabcdd"});
  ASSERT_TRUE(has_two);
  ASSERT_FALSE(has_three);
}
TEST(Day2Part1, abcdee) {
  // abcdee contains two e.
  const auto [has_two, has_three] = parse_box_id(std::string{"abcdee"});
  ASSERT_TRUE(has_two);
  ASSERT_FALSE(has_three);
}

TEST(Day2Part1, ababab) {
  // ababab contains three a and three b, but it only counts once.
  const auto [has_two, has_three] = parse_box_id(std::string{"ababab"});
  ASSERT_FALSE(has_two);
  ASSERT_TRUE(has_three);
}

const std::string example_box_ids{
R"(abcdef
bababc
abbcde
abcccd
aabcdd
abcdee
ababab)"
};

TEST(Day2Part1, CountTwosAndThrees) {
  // Of these box IDs, four of them contain a letter which appears exactly twice, and three of them contain a letter which appears exactly three times.
  const auto [two_count, three_count] = count_twos_and_threes(lines(input(example_box_ids)));
  ASSERT_EQ(two_count, 4);
  ASSERT_EQ(three_count, 3);
}

TEST(Day2Part1, Nothing) {
  ASSERT_EQ(0, day2part1(std::stringstream{}));
}

TEST(Day2Part1, Example) {
  ASSERT_EQ(12, day2part1(input(example_box_ids)));
}

