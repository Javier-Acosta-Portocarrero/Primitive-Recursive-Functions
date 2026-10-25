// University of La Laguna
// School of Engineering and Technology
// Bachelor's Degree in Computer Engineering
// Course: Computational Complexity
// Year: 4th
// Assignment 3: Primitive Recursive Functions
// Author: Javier Acosta Portocarrero
// Date: 24/10/2026
// File input_exception.h: declaration of the command line input exception.

#ifndef INPUT_EXCEPTION_H
#define INPUT_EXCEPTION_H

#include <stdexcept>
#include <string>

class InputException : public std::runtime_error {
 public:
  explicit InputException(const std::string& message) : std::runtime_error(message) {}
};

#endif
