// University of La Laguna
// School of Engineering and Technology
// Bachelor's Degree in Computer Engineering
// Course: Computational Complexity
// Year: 4th
// Assignment 3: Primitive Recursive Functions
// Author: Javier Acosta Portocarrero
// Date: 24/10/2026
// File power.cc: implementation of Power by primitive recursion.

#include "../include/power.h"

/**
 * @brief Evaluates exponentiation using only the composed primitive recursive functions.
 *
 * Limit equation: P(x, 0) = g(x) = (S o Z)(x).
 * Recursion equation: P(x, S(y)) = h(x, y, P(x, y))
 *                    = (M o (P_1^3 x P_3^3))(x, y, P(x, y)).
 */
unsigned Power::Evaluate(const std::vector<unsigned>& arguments) {
  ValidateArity(arguments, 2, "Power");
  RegisterCall();

  const unsigned x = arguments[0];
  const unsigned y = arguments[1];
  if (y == 0) {
    return successor_.Evaluate({zero_.Evaluate({x})});
  }
  return multiplication_.Evaluate({x, Evaluate({x, y - 1})});
}

/**
 * @brief Resets this instance and all its composed primitive functions.
 */
void Power::ResetCounters() {
  FPR::ResetCounters();
  zero_.ResetCounters();
  successor_.ResetCounters();
  multiplication_.ResetCounters();
}

/**
 * @brief 
 */
void Power::CollectCallStatistics(std::map<std::string, unsigned long long>& statistics) const {
  RegisterStatistics(statistics, "Power");
  RegisterDependencyStatistics(statistics, zero_);
  RegisterDependencyStatistics(statistics, successor_);
  RegisterDependencyStatistics(statistics, multiplication_);
}
