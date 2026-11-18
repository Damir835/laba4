#include "quadratic_equation.h"

#include <cmath>
#include <ostream>
#include <stdexcept>

namespace {

void ValidateCoefficient(double value) {
  if (!std::isfinite(value)) {
    throw std::invalid_argument("Коэффициент должен быть конечным числом.");
  }
}

}

QuadraticEquation::QuadraticEquation() : a_(1.0), b_(0.0), c_(0.0) {}

QuadraticEquation::QuadraticEquation(double a, double b, double c)
    : a_(a), b_(b), c_(c) {
  ValidateCoefficient(a_);
  ValidateCoefficient(b_);
  ValidateCoefficient(c_);
}

QuadraticEquation::QuadraticEquation(const QuadraticEquation& other)
    : a_(other.a_), b_(other.b_), c_(other.c_) {}

double QuadraticEquation::GetA() const { return a_; }

double QuadraticEquation::GetB() const { return b_; }

double QuadraticEquation::GetC() const { return c_; }

void QuadraticEquation::SetA(double value) {
  ValidateCoefficient(value);
  a_ = value;
}

void QuadraticEquation::SetB(double value) {
  ValidateCoefficient(value);
  b_ = value;
}

void QuadraticEquation::SetC(double value) {
  ValidateCoefficient(value);
  c_ = value;
}

std::vector<double> QuadraticEquation::FindRoots() const {
  std::vector<double> roots;

  if (a_ == 0.0) {
    if (b_ != 0.0) {
      roots.push_back(-c_ / b_);
    }
    return roots;
  }

  const double discriminant = b_ * b_ - 4.0 * a_ * c_;
  if (discriminant < 0.0) {
    return roots;
  }

  if (discriminant == 0.0) {
    roots.push_back(-b_ / (2.0 * a_));
    return roots;
  }

  const double square_root = std::sqrt(discriminant);
  roots.push_back((-b_ - square_root) / (2.0 * a_));
  roots.push_back((-b_ + square_root) / (2.0 * a_));
  return roots;
}

QuadraticEquation& QuadraticEquation::operator++() {
  ++a_;
  ++b_;
  ++c_;
  return *this;
}

QuadraticEquation QuadraticEquation::operator++(int) {
  QuadraticEquation previous(*this);
  ++(*this);
  return previous;
}

QuadraticEquation& QuadraticEquation::operator--() {
  --a_;
  --b_;
  --c_;
  return *this;
}

QuadraticEquation QuadraticEquation::operator--(int) {
  QuadraticEquation previous(*this);
  --(*this);
  return previous;
}

QuadraticEquation::operator double() const {
  return b_ * b_ - 4.0 * a_ * c_;
}

QuadraticEquation::operator bool() const {
  if (a_ == 0.0 && b_ == 0.0 && c_ == 0.0) {
    return true;
  }
  return !FindRoots().empty();
}

bool QuadraticEquation::operator==(const QuadraticEquation& other) const {
  return a_ == other.a_ && b_ == other.b_ && c_ == other.c_;
}

bool QuadraticEquation::operator!=(const QuadraticEquation& other) const {
  return !(*this == other);
}

std::ostream& operator<<(std::ostream& output,
                         const QuadraticEquation& equation) {
  output << equation.a_ << "x^2 ";
  if (equation.b_ >= 0.0) {
    output << "+ ";
  } else {
    output << "- ";
  }
  output << std::abs(equation.b_) << "x ";
  if (equation.c_ >= 0.0) {
    output << "+ ";
  } else {
    output << "- ";
  }
  output << std::abs(equation.c_) << " = 0";
  return output;
}
