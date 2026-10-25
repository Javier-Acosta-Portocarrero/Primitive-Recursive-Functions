// University of La Laguna
// School of Engineering and Technology
// Bachelor's Degree in Computer Engineering
// Course: Computational Complexity
// Year: 4th
// Assignment 3: Primitive Recursive Functions
// Author: Javier Acosta Portocarrero
// Date: 24/10/2026
// File projection.cc: implementation of the initial Projection function.

#include "../include/projection.h"
#include "../include/exceptions/fpr_exception.h"

/**
 * @brief Constructs a projection P_i^n using one-based mathematical indexing.
 *
 * @throws FPRException If n is zero or the chosen index is outside [1, n].
 */
Projection::Projection(unsigned arity, unsigned index) : arity_{arity}, index_{index} {
  if (arity_ == 0 || index_ == 0 || index_ > arity_) {
    throw FPRException("Invalid projection arity or index.");
  }
}

/**
 * @brief Evaluates P_i^n(x1, ..., xn) = xi.
 */
unsigned Projection::Evaluate(const std::vector<unsigned>& arguments) {
  ValidateArity(arguments, arity_, "Projection");
  RegisterCall();
  return arguments[index_ - 1];
}

void Projection::CollectCallStatistics(std::map<std::string, unsigned long long>& statistics) const {
  RegisterStatistics(statistics, "Projection");
}
