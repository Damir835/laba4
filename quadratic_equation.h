#ifndef LAB4_VARIANT6_QUADRATIC_EQUATION_H_
#define LAB4_VARIANT6_QUADRATIC_EQUATION_H_

#include <iosfwd>
#include <vector>

class QuadraticEquation {
 public:
  QuadraticEquation();
  QuadraticEquation(double a, double b, double c);
  QuadraticEquation(const QuadraticEquation& other);

  QuadraticEquation& operator=(const QuadraticEquation& other) = default;

  double GetA() const;
  double GetB() const;
  double GetC() const;

  void SetA(double value);
  void SetB(double value);
  void SetC(double value);

  std::vector<double> FindRoots() const;

  QuadraticEquation& operator++();
  QuadraticEquation operator++(int);
  QuadraticEquation& operator--();
  QuadraticEquation operator--(int);

  operator double() const;
  explicit operator bool() const;

  bool operator==(const QuadraticEquation& other) const;
  bool operator!=(const QuadraticEquation& other) const;

  friend std::ostream& operator<<(std::ostream& output,
                                  const QuadraticEquation& equation);

 private:
  double a_;
  double b_;
  double c_;
};

#endif
