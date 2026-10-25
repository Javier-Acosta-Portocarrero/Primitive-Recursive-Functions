// University of La Laguna
// School of Engineering and Technology
// Bachelor's Degree in Computer Engineering
// Course: Computational Complexity
// Year: 4th
// Assignment 3: Primitive Recursive Functions
// Author: Javier Acosta Portocarrero
// Date: 24/10/2026
// File addition.cc: implementation of Addition by primitive recursion.

#include "../include/addition.h"

/**
 * @brief Evaluates addition by primitive recursion over the second argument.
 *
 * Limit equation: A(x, 0) = g(x) = P_1^1(x).
 * Recursion equation: A(x, S(y)) = h(x, y, A(x, y))
 *                    = (S o P_3^3)(x, y, A(x, y)).
 *
 */
unsigned Addition::Evaluate(const std::vector<unsigned>& arguments) {
  ValidateArity(arguments, 2, "Addition");
  RegisterCall();

  const unsigned x = arguments[0];
  const unsigned y = arguments[1];
  if (y == 0) {
    return first_projection_.Evaluate({x, y});
  }
  return successor_.Evaluate({Evaluate({x, y - 1})});
}

/**
 * @brief Resets this instance and the primitive functions it uses.
 */
void Addition::ResetCounters() {
  FPR::ResetCounters();
  first_projection_.ResetCounters();
  successor_.ResetCounters();
}

void Addition::CollectCallStatistics(std::map<std::string, unsigned long long>& statistics) const {
  RegisterStatistics(statistics, "Addition");
  RegisterDependencyStatistics(statistics, first_projection_);
  RegisterDependencyStatistics(statistics, successor_);
}
