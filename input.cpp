#include "input.h"

#include <cmath>
#include <iostream>
#include <limits>

namespace {

void ClearInput() {
  std::cin.clear();
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

}  // namespace

double ReadDouble(const std::string& prompt) {
  double value = 0.0;

  while (true) {
    std::cout << prompt;
    if (std::cin >> value && std::isfinite(value)) {
      return value;
    }

    std::cout << "Ошибка: введите конечное число.\n";
    ClearInput();
  }
}

int ReadInt(const std::string& prompt) {
  int value = 0;

  while (true) {
    std::cout << prompt;
    if (std::cin >> value) {
      return value;
    }

    std::cout << "Ошибка: введите целое число.\n";
    ClearInput();
  }
}
