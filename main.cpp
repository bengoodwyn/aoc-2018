#include <iostream>
#include "day1part1.hpp"
#include "day1part2.hpp"
#include "day2part1.hpp"
#include "day2part2.hpp"
#include "day1.hpp"
#include "day2.hpp"

static_assert(529 == day1part1(day1));

int main(int argc, char** argv) {
  std::cout << "Day 1 Part 1: " << day1part1(day1) << std::endl;
  std::cout << "Day 1 Part 2: " << day1part2(day1) << std::endl;
  std::cout << "Day 2 Part 1: " << day2part1(day2) << std::endl;
  std::cout << "Day 2 Part 2: " << day2part2(day2).value() << std::endl;
  return 0;
}
