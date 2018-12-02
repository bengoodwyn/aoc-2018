#pragma once
#include <range/v3/algorithm/for_each.hpp>
#include <range/v3/view/cycle.hpp>
#include <range/v3/view/take_while.hpp>
#include <boost/container/flat_set.hpp>
#include "day1part1.hpp"

constexpr auto day1part2 = [](const auto& frequency_changes) {
  auto current_frequency = initial_frequency;
  boost::container::flat_set<decltype(current_frequency)> previous_frequencies{};

  ranges::v3::for_each(
    ranges::view::cycle(frequency_changes)
      | ranges::view::take_while([&]([[maybe_unused]] const auto frequency_change) {
        auto [iter,inserted] = previous_frequencies.insert(current_frequency);
        return inserted;
      }),
    [&](const auto frequency_change) {
      current_frequency = resulting_frequency(current_frequency, frequency_change);
    }
  );

  return current_frequency;;
};
