// University of La Laguna
// School of Engineering and Technology
// Bachelor's Degree in Computer Engineering
// Course: Computational Complexity
// Year: 4th
// Assignment 3: Primitive Recursive Functions
// Author: Javier Acosta Portocarrero
// Date: 24/10/2026
// File main_functions.cc: implementation of program arguments and output functions.

#include "../include/main_functions.h"
#include "../include/exceptions/input_exception.h"

#include <charconv>
#include <iostream>
#include <string>

/**
 * @brief Converts a command line argument to a natural number.
 *
 * @throws InputException If the argument is not an unsigned decimal integer.
 */
unsigned ParseNaturalNumber(const std::string& value, const std::string& option) {
  unsigned result = 0;
  const auto [end, error] = std::from_chars(value.data(), value.data() + value.size(), result);
  if (value.empty() || error != std::errc{} || end != value.data() + value.size()) {
    throw InputException("Invalid natural number '" + value + "' for " + option + ".");
  }
  return result;
}

/**
 * @brief Reads the mandatory -x (base) and -y (exponent) command line options.
 *
 * @throws InputException If an option is missing, repeated or incorrectly formatted.
 */
void ReadProgramArguments(int argc, char* argv[], unsigned& base, unsigned& exponent, bool& parameter_error) {
  bool base_found = false;
  bool exponent_found = false;

  for (int i = 1; i < argc; ++i) {
    const std::string argument = argv[i];
    if (argument == "-x" || argument == "-y") {
      if (i + 1 >= argc) {
        parameter_error = true;
        throw InputException("Missing value after " + argument + ".");
      }
      if ((argument == "-x" && base_found) || (argument == "-y" && exponent_found)) {
        parameter_error = true;
        throw InputException("Repeated option '" + argument + "'.");
      }
      const std::string value = argv[++i];
      parameter_error = true;
      const unsigned parsed_value = ParseNaturalNumber(value, argument);
      if (argument == "-x") {
        base = parsed_value;
        base_found = true;
      } else {
        exponent = parsed_value;
        exponent_found = true;
      }
      parameter_error = false;
    } else {
      parameter_error = true;
      throw InputException("Unknown option '" + argument + "'.");
    }
  }

  if (!base_found || !exponent_found) {
    parameter_error = true;
    throw InputException("Both -x and -y options are required.");
  }
}

/**
 * @brief Shows the calls made to each FPR and their total.
 */
void PrintCallStatistics(const FPR& function) {
  std::cout << "Function calls: " << function.GetTotalCallCount() << '\n';
  std::cout << "Calls by function:\n";
  for (const auto& [function_name, calls] : function.GetCallStatistics()) {
    std::cout << "  " << function_name << ": " << calls << '\n';
  }
}
