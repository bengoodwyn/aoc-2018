#pragma once
#include <range/v3/algorithm/for_each.hpp>
#include <range/v3/algorithm/any_of.hpp>
#include <range/v3/view/transform.hpp>
#include <array>
#include <vector>
#include <string>
#include <tuple>

constexpr auto parse_box_id = [](const auto box_id) {
  std::array<size_t, 'z'+1> count_by_char{};

  ranges::v3::for_each(box_id, [&](const auto x) { ++count_by_char[x]; });

  return std::make_tuple(
      ranges::v3::any_of(count_by_char, [](const auto x) {return x==2;}),
      ranges::v3::any_of(count_by_char, [](const auto x) {return x==3;})
    );
};

constexpr auto count_twos_and_threes = [](const auto& box_ids) {
  auto twos = 0;
  auto threes = 0;

  ranges::v3::for_each(
        box_ids | ranges::view::transform(parse_box_id),
        [&](const auto parsed_box_id) {
          const auto [any_twos, any_threes] = parsed_box_id;
          if (any_twos) ++twos;
          if (any_threes) ++threes;
      });

  return std::make_tuple(twos, threes);;
};

constexpr auto day2part1 = [](auto&& input) {
  std::vector<std::string> box_ids{};
  while (not input.eof()) {
    std::string line{};
    std::getline(input, line);
    box_ids.push_back(line);
  }

  const auto [twos, threes] = count_twos_and_threes(box_ids);
  return twos * threes;
};
