#pragma once
#include "day3part1.hpp"

constexpr auto is_uncontested_claim = [](const auto& claim_counts, const auto claim) {
  const auto left = claim[1];
  const auto top = claim[2];
  const auto width = claim[3];
  const auto height = claim[4];

  for (auto row = top; row < top+height; ++row) {
    for (auto col = left; col < left+width; ++col) {
      if (claim_counts[row][col] > 1) {
        return false;
      }
    }
  }

  return true;
};

constexpr auto day3part2 = [](auto&& input) {
  std::vector<std::string> claims;
  while (!input.eof()) {
    std::string line;
    std::getline(input, line);
    claims.push_back(line);
  }

  constexpr auto SIZE = 1000;
  int claim_counts[SIZE][SIZE] = {0};
  apply_claims(claim_counts, claims);

  for (const auto& claim_text: claims) {
    const auto claim = parse_claim(claim_text);
    if (5 != claim.size()) continue;
    if (is_uncontested_claim(claim_counts, claim)) {
      return claim[0];
    }
  }
  return -1;
};
