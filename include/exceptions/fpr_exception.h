// University of La Laguna
// School of Engineering and Technology
// Bachelor's Degree in Computer Engineering
// Course: Computational Complexity
// Year: 4th
// Assignment 3: Primitive Recursive Functions
// Author: Javier Acosta Portocarrero
// Date: 24/10/2026
// File fpr_exception.h: declaration of the primitive recursive function exception.

#ifndef FPR_EXCEPTION_H
#define FPR_EXCEPTION_H

#include <stdexcept>
#include <string>

class FPRException : public std::runtime_error {
 public:
  explicit FPRException(const std::string& message) : std::runtime_error(message) {}
};

#endif
