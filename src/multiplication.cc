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
 *                     = (A o (P_1^3 x P_3^3))(x, y, M(x, y)).
 */
unsigned Multiplication::Evaluate(const std::vector<unsigned>& arguments) {
  ValidateArity(arguments, 2, "Multiplication");
  RegisterCall();

  const unsigned x = arguments[0];
  const unsigned y = arguments[1];
  if (y == 0) {
    return zero_.Evaluate({x});
  }
  const unsigned previous_result = Evaluate({x, y - 1});
  const std::vector<unsigned> step_arguments = {x, y - 1, previous_result};

  const unsigned first = base_projection_.Evaluate(step_arguments);
  const unsigned second = result_projection_.Evaluate(step_arguments);

  return addition_.Evaluate({first, second});
}

/**
 * @brief Resets this instance and all its composed primitive functions.
 */
void Multiplication::ResetCounters() {
  FPR::ResetCounters();
  zero_.ResetCounters();
  base_projection_.ResetCounters();
  result_projection_.ResetCounters();
  addition_.ResetCounters();
}

void Multiplication::CollectCallStatistics(std::map<std::string, unsigned long long>& statistics) const {
  RegisterStatistics(statistics, "Multiplication");
  RegisterDependencyStatistics(statistics, zero_);
  RegisterDependencyStatistics(statistics, base_projection_);
  RegisterDependencyStatistics(statistics, result_projection_);
  RegisterDependencyStatistics(statistics, addition_);
}
