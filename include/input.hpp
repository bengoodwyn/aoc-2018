#pragma once
#include <sstream>

constexpr auto input = [](const auto& text) {
  return std::stringstream{text};
};
