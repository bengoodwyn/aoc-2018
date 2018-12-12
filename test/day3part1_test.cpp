#include <gtest/gtest.h>
#include "day3part1.hpp"
#include "input.hpp"

TEST(Day3Part1, TestParseClaim) {
  const std::string input{"#123 @ 3,2: 5x4"};

  const auto parsed = parse_claim(input);
  ASSERT_EQ(5, parsed.size());
  ASSERT_EQ(123, parsed[0]);
  ASSERT_EQ(3, parsed[1]);
  ASSERT_EQ(2, parsed[2]);
  ASSERT_EQ(5, parsed[3]);
  ASSERT_EQ(4, parsed[4]);
}

TEST(Day3Part1, TestApplyClaim) {
  const std::vector<int> claim = {123, 3, 2, 5, 4};
  int claim_counts[9][11] = { 0 };

  apply_claim(claim_counts, claim);

  std::string result;
  for (auto row=0; row<9; ++row) {
    for (auto col=0; col<11; ++col) {
      result += std::to_string(claim_counts[row][col]);
    }
    result += "\n";
  }

  ASSERT_EQ(
    "00000000000\n"
    "00000000000\n"
    "00011111000\n"
    "00011111000\n"
    "00011111000\n"
    "00011111000\n"
    "00000000000\n"
    "00000000000\n"
    "00000000000\n",
    result);
}

TEST(Day3Part1, ExampleClaims) {
  const auto claim1 = parse_claim("#1 @ 1,3: 4x4");
  const auto claim2 = parse_claim("#2 @ 3,1: 4x4");
  const auto claim3 = parse_claim("#3 @ 5,5: 2x2");

  int claim_counts[8][8] = { 0 };

  apply_claim(claim_counts, claim1);
  apply_claim(claim_counts, claim2);
  apply_claim(claim_counts, claim3);

  std::string result;
  for (auto row=0; row<8; ++row) {
    for (auto col=0; col<8; ++col) {
      result += std::to_string(claim_counts[row][col]);
    }
    result += "\n";
  }

  ASSERT_EQ(
    "00000000\n"
    "00011110\n"
    "00011110\n"
    "01122110\n"
    "01122110\n"
    "01111110\n"
    "01111110\n"
    "00000000\n",
    result);
}

const std::string example{
R"(#1 @ 1,3: 4x4
#2 @ 3,1: 4x4
#3 @ 5,5: 2x2)"
};

TEST(Day3Part1, Example) {
  ASSERT_EQ(4, day3part1(input(example)));
}
