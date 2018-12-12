#include <iostream>
#include "day1part1.hpp"
#include "day1part2.hpp"
#include "day2part1.hpp"
#include "day2part2.hpp"
#include "day3part1.hpp"
#include "day3part2.hpp"
#include "day1.hpp"
#include "day2.hpp"
#include "day3.hpp"

int main(int argc, char** argv) {
  std::cout << "Day 1 Part 1: " << day1part1(day1()) << std::endl;
  std::cout << "Day 1 Part 2: " << day1part2(day1()) << std::endl;
  std::cout << "Day 2 Part 1: " << day2part1(day2()) << std::endl;
  std::cout << "Day 2 Part 2: " << day2part2(day2()) << std::endl;
  std::cout << "Day 3 Part 1: " << day3part1(day3()) << std::endl;
  std::cout << "Day 3 Part 2: " << day3part2(day3()) << std::endl;
  return 0;
}
