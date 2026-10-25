// University of La Laguna
// School of Engineering and Technology
// Bachelor's Degree in Computer Engineering
// Course: Computational Complexity
// Year: 4th
// Assignment 3: Primitive Recursive Functions
// Author: Javier Acosta Portocarrero
// Date: 24/10/2026
// File multiplication.cc: implementation of Multiplication by primitive recursion.

#include "../include/multiplication.h"

/**
 * @brief Evaluates multiplication by primitive recursion and addition.
 *
 * Limit equation: M(x, 0) = g(x) = Z(x).
 * Recursion equation: M(x, S(y)) = h(x, y, M(x, y))
 *                    = (A o (P_3^3 x P_1^3))(x, y, M(x, y)).
 */
unsigned Multiplication::Evaluate(const std::vector<unsigned>& arguments) {
  ValidateArity(arguments, 2, "Multiplication");
  RegisterCall();

  const unsigned x = arguments[0];
  const unsigned y = arguments[1];
  if (y == 0) {
    return zero_.Evaluate({x});
  }
  return addition_.Evaluate({Evaluate({x, y - 1}), x});
}

/**
 * @brief Resets this instance and all its composed primitive functions.
 */
void Multiplication::ResetCounters() {
  FPR::ResetCounters();
  zero_.ResetCounters();
  addition_.ResetCounters();
}

void Multiplication::CollectCallStatistics(std::map<std::string, unsigned long long>& statistics) const {
  RegisterStatistics(statistics, "Multiplication");
  RegisterDependencyStatistics(statistics, zero_);
  RegisterDependencyStatistics(statistics, addition_);
}
