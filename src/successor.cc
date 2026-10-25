// University of La Laguna
// School of Engineering and Technology
// Bachelor's Degree in Computer Engineering
// Course: Computational Complexity
// Year: 4th
// Assignment 3: Primitive Recursive Functions
// Author: Javier Acosta Portocarrero
// Date: 24/10/2026
// File successor.cc: implementation of the initial Successor function.

#include "../include/successor.h"
#include "../include/exceptions/fpr_exception.h"

#include <limits>

/**
 * @brief Evaluates the initial successor function S(x) = x + 1.
 *
 * @throws FPRException If the successor cannot be represented as unsigned.
 */
unsigned Successor::Evaluate(const std::vector<unsigned>& arguments) {
  ValidateArity(arguments, 1, "Successor");
  RegisterCall();
  if (arguments[0] == std::numeric_limits<unsigned>::max()) {
    throw FPRException("The result exceeds the range of unsigned.");
  }
  return arguments[0] + 1;
}

void Successor::CollectCallStatistics(std::map<std::string, unsigned long long>& statistics) const {
  RegisterStatistics(statistics, "Successor");
}
