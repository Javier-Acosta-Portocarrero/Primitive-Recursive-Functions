// University of La Laguna
// School of Engineering and Technology
// Bachelor's Degree in Computer Engineering
// Course: Computational Complexity
// Year: 4th
// Assignment 3: Primitive Recursive Functions
// Author: Javier Acosta Portocarrero
// Date: 24/10/2026
// File zero.cc: implementation of the initial Zero function.

#include "../include/zero.h"

/**
 * @brief Evaluates the initial zero function Z(x) = 0.
 */
unsigned Zero::Evaluate(const std::vector<unsigned>& arguments) {
  ValidateArity(arguments, 1, "Zero");
  RegisterCall();
  return 0;
}

void Zero::CollectCallStatistics(std::map<std::string, unsigned long long>& statistics) const {
  RegisterStatistics(statistics, "Zero");
}
