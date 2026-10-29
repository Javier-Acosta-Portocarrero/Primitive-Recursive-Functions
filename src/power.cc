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
  const unsigned previous_result = Evaluate({x, y - 1});
  const std::vector<unsigned> step_arguments = {x, y - 1, previous_result};

  const unsigned first = base_projection_.Evaluate(step_arguments);
  const unsigned second = result_projection_.Evaluate(step_arguments);

  return multiplication_.Evaluate({first, second});
}

/**
 * @brief Resets this instance and all its composed primitive functions.
 */
void Power::ResetCounters() {
  FPR::ResetCounters();
  zero_.ResetCounters();
  successor_.ResetCounters();
  base_projection_.ResetCounters();
  result_projection_.ResetCounters(); 
  multiplication_.ResetCounters();
}

/**
 * @brief 
 */
void Power::CollectCallStatistics(std::map<std::string, unsigned long long>& statistics) const {
  RegisterStatistics(statistics, "Power");
  RegisterDependencyStatistics(statistics, zero_);
  RegisterDependencyStatistics(statistics, successor_);
  RegisterDependencyStatistics(statistics, base_projection_);
  RegisterDependencyStatistics(statistics, result_projection_);
  RegisterDependencyStatistics(statistics, multiplication_);
}
