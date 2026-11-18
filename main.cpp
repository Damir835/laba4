#include <iomanip>
#include <iostream>
#include <vector>

#include "input.h"
#include "quadratic_equation.h"

namespace {

QuadraticEquation ReadEquation() {
  const double a = ReadDouble("Введите коэффициент a: ");
  const double b = ReadDouble("Введите коэффициент b: ");
  const double c = ReadDouble("Введите коэффициент c: ");
  return QuadraticEquation(a, b, c);
}

void PrintRoots(const QuadraticEquation& equation) {
  const std::vector<double> roots = equation.FindRoots();

  if (roots.empty()) {
    std::cout << "Действительных корней нет.\n";
    return;
  }

  std::cout << "Количество действительных корней: " << roots.size()
            << '\n';
  for (std::size_t i = 0; i < roots.size(); ++i) {
    std::cout << "x" << i + 1 << " = " << roots[i] << '\n';
  }
}

void ShowConstructors() {
  std::cout << "\n--- Проверка конструкторов ---\n";
  const QuadraticEquation default_equation;
  std::cout << "Конструктор по умолчанию: " << default_equation << '\n';

  std::cout << "\nСоздание объекта с параметрами:\n";
  const QuadraticEquation parameter_equation = ReadEquation();
  std::cout << "Получено уравнение: " << parameter_equation << '\n';

  const QuadraticEquation copied_equation(parameter_equation);
  std::cout << "Конструктор копирования: " << copied_equation << '\n';
}

void ShowSettersAndGetters() {
  std::cout << "\n--- Проверка свойств (геттеров и сеттеров) ---\n";
  QuadraticEquation equation = ReadEquation();
  std::cout << "Текущие коэффициенты: a = " << equation.GetA()
            << ", b = " << equation.GetB() << ", c = " << equation.GetC()
            << '\n';

  equation.SetA(ReadDouble("Новое значение a: "));
  equation.SetB(ReadDouble("Новое значение b: "));
  equation.SetC(ReadDouble("Новое значение c: "));
  std::cout << "После изменения: " << equation << '\n';
}

void ShowRoots() {
  std::cout << "\n--- Вычисление корней (задание 1) ---\n";
  const QuadraticEquation equation = ReadEquation();
  std::cout << "Уравнение: " << equation << '\n';
  PrintRoots(equation);
}

void ShowUnaryOperators() {
  std::cout << "\n--- Унарные операторы (задание 2) ---\n";
  QuadraticEquation equation = ReadEquation();

  std::cout << "Исходное уравнение: " << equation << '\n';
  std::cout << "Префиксный ++: " << ++equation << '\n';
  std::cout << "Префиксный --: " << --equation << '\n';

  const QuadraticEquation old_equation = equation++;
  std::cout << "Постфиксный ++ (старое значение): " << old_equation << '\n';
  std::cout << "После постфиксного ++: " << equation << '\n';

  const QuadraticEquation before_decrement = equation--;
  std::cout << "Постфиксный -- (старое значение): " << before_decrement
            << '\n';
  std::cout << "После постфиксного --: " << equation << '\n';
}

void ShowTypeConversions() {
  std::cout << "\n--- Преобразование типов (задание 2) ---\n";
  const QuadraticEquation equation = ReadEquation();
  const double discriminant = equation;
  const bool has_roots = static_cast<bool>(equation);

  std::cout << "Уравнение: " << equation << '\n';
  std::cout << "Дискриминант (неявное преобразование в double): "
            << discriminant << '\n';
  std::cout << "Есть действительные корни (явное преобразование в bool): "
            << (has_roots ? "да" : "нет") << '\n';
}

void ShowComparisons() {
  std::cout << "\n--- Сравнение уравнений (задание 2) ---\n";
  std::cout << "Первое уравнение:\n";
  const QuadraticEquation first = ReadEquation();
  std::cout << "Второе уравнение:\n";
  const QuadraticEquation second = ReadEquation();

  std::cout << "Первое: " << first << '\n';
  std::cout << "Второе: " << second << '\n';
  std::cout << "Оператор ==: " << (first == second ? "true" : "false")
            << '\n';
  std::cout << "Оператор !=: " << (first != second ? "true" : "false")
            << '\n';
}

}  // namespace

int main() {
  std::cout << std::fixed << std::setprecision(3);

  while (true) {
    std::cout << "\n========== ЛАБОРАТОРНАЯ РАБОТА №4 =========="
              << "\nВариант 6. Класс QuadraticEquation"
              << "\n1. Проверить конструкторы"
              << "\n2. Проверить геттеры и сеттеры"
              << "\n3. Вычислить корни уравнения"
              << "\n4. Проверить ++ и --"
              << "\n5. Проверить преобразования типов"
              << "\n6. Сравнить два уравнения"
              << "\n0. Выход\n";

    const int choice = ReadInt("Выберите пункт: ");
    switch (choice) {
      case 1:
        ShowConstructors();
        break;
      case 2:
        ShowSettersAndGetters();
        break;
      case 3:
        ShowRoots();
        break;
      case 4:
        ShowUnaryOperators();
        break;
      case 5:
        ShowTypeConversions();
        break;
      case 6:
        ShowComparisons();
        break;
      case 0:
        std::cout << "Работа программы завершена.\n";
        return 0;
      default:
        std::cout << "Нет такого пункта меню. Повторите ввод.\n";
        break;
    }
  }
}
