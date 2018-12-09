#pragma once
#include <range/v3/algorithm/for_each.hpp>
#include <range/v3/view/cartesian_product.hpp>
#include <range/v3/view/filter.hpp>
#include <range/v3/view/take.hpp>
#include <range/v3/view/transform.hpp>
#include <range/v3/view/zip.hpp>
#include <array>

constexpr auto compare_box_ids = [](const auto box_id_a, const auto box_id_b) {
  std::string result{};
  ranges::v3::for_each(
    ranges::view::zip(box_id_a, box_id_b)
      | ranges::view::filter([](const auto pair) {return std::get<0>(pair)==std::get<1>(pair);})
      | ranges::view::transform([](const auto pair) {return std::get<0>(pair);}),
    [&](const auto x) { result += x; }
  );
  return result;
};

constexpr auto day2part2 = [](auto&& input) {
  std::vector<std::string> box_ids{};
  while (not input.eof()) {
    std::string line{};
    std::getline(input, line);
    box_ids.push_back(line);
  }

  std::string result{};
  ranges::v3::for_each(
    ranges::view::cartesian_product(box_ids, box_ids)
      | ranges::view::transform([](const auto pair) { return std::make_tuple(std::get<0>(pair), compare_box_ids(std::get<0>(pair), std::get<1>(pair))); })
      | ranges::view::filter([](const auto pair) { return std::get<1>(pair).length() == (std::get<0>(pair).length()-1); })
      | ranges::view::transform([](const auto pair) { return std::get<1>(pair); })
      | ranges::view::take(1),
    [&](const auto x) { result = x; });
  return result;
};
