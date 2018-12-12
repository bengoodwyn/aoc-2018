#pragma once
#include <string>
#include <vector>

constexpr auto lines = [](auto&& input) {
  std::vector<std::string> result{};
  while (not input.eof()) {
    std::string line;
    std::getline(input, line);
    result.push_back(line);
  }
  return result;
};
