#pragma once
#include <range/v3/algorithm/for_each.hpp>
#include <range/v3/view/transform.hpp>
#include <string>
#include "input.hpp"

//then starting from a frequency of zero,
constexpr auto initial_frequency = 0;

constexpr auto resulting_frequency = [](const auto current_frequency, const auto frequency_change) {
  return current_frequency + frequency_change;
};

//Starting with a frequency of zero, what is the resulting frequency after all of the changes in frequency have been applied?
constexpr auto day1part1 = [](auto&& input) {
  auto result = initial_frequency;
  const auto frequency_changes = lines(input);
  ranges::v3::for_each(
      frequency_changes
        | ranges::view::transform([](const auto& line) { return std::stoi(line); }),
      [&result](const auto frequency_change) {
        result += frequency_change;
      }
  );
  return result;
};
