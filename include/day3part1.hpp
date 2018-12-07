#pragma once
#include <boost/algorithm/string/split.hpp>
#include <vector>
#include <string>
#include <sstream>

constexpr auto parse_claim = [](const auto input) {
  std::vector<std::string> nums;
  boost::algorithm::split(
      nums,
      input,
      [](const auto x) { return not std::isdigit(x); },
      boost::token_compress_on);
  std::vector<int> parsed;
  std::for_each(nums.begin(), nums.end(),
      [&parsed](const auto x) { if (x.length()>0) { parsed.push_back(std::stoi(x)); } });
  return parsed;
};

constexpr auto apply_claim = [](auto& claim_counts, const auto claim) {
  const auto left = claim[1];
  const auto top = claim[2];
  const auto width = claim[3];
  const auto height = claim[4];

  for (auto row = top; row < top+height; ++row) {
    for (auto col = left; col < left+width; ++col) {
      claim_counts[row][col]++;
    }
  }
};

constexpr auto apply_claims = [](auto& claim_counts, const auto input) {
  std::stringstream in{std::string{input}};
  std::string line;
  while (!in.eof()) {
    std::getline(in, line);
    const auto claim = parse_claim(line);
    if (5 != claim.size()) continue;
    apply_claim(claim_counts, claim);
  }
};

constexpr auto day3part1 = [](const auto input) {
  constexpr auto SIZE = 1000;
  int claim_counts[SIZE][SIZE] = {0};
  apply_claims(claim_counts, input);
  int overlap_squares = 0;
  for (auto row = 0; row < SIZE; ++row) {
    for (auto col = 0; col < SIZE; ++col) {
      if (claim_counts[row][col] > 1) ++overlap_squares;
    }
  }
  return overlap_squares;
};
