#pragma once

//then starting from a frequency of zero,
constexpr auto initial_frequency = 0;

constexpr auto resulting_frequency = [](const auto current_frequency, const auto frequency_change) {
  return current_frequency + frequency_change;
};

//Starting with a frequency of zero, what is the resulting frequency after all of the changes in frequency have been applied?
constexpr auto day1part1 = [](const auto frequency_changes) {
  auto result = initial_frequency;
  for (const auto frequency_change: frequency_changes) {
    result += frequency_change;
  }
  return result;
};
