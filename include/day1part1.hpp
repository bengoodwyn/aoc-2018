#include <range/v3/numeric/accumulate.hpp>

//then starting from a frequency of zero,
constexpr auto initial_frequency = 0;

constexpr auto resulting_frequency = [](auto current_frequency, auto frequency_change) {
  return current_frequency + frequency_change;
};

//Starting with a frequency of zero, what is the resulting frequency after all of the changes in frequency have been applied?
constexpr auto day1part1 = [](auto frequency_changes) {
  return ranges::v3::accumulate(frequency_changes, initial_frequency, resulting_frequency);
};
