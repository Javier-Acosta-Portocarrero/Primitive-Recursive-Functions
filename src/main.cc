// University of La Laguna
// School of Engineering and Technology
// Bachelor's Degree in Computer Engineering
// Course: Computational Complexity
// Year: 4th
// Assignment 3: Primitive Recursive Functions
// Author: Javier Acosta Portocarrero
// Date: 24/10/2026
// File main.cc: main function of the primitive recursive functions program.

#include "../include/main_functions.h"
#include "../include/power.h"

#include <exception>
#include <iostream>

/**
 * @brief Main program to evaluate exponentiation as a primitive recursive function.
 */
int main(int argc, char* argv[]) {
  bool parameter_error = false;

  try {
    unsigned base = 0;
    unsigned exponent = 0;
    ReadProgramArguments(argc, argv, base, exponent, parameter_error);

    Power power;
    FPR& function = power;
    const unsigned result = function.Evaluate({base, exponent});
    std::cout << "Result: " << result << '\n';
    PrintCallStatistics(function);
    return 0;

  } catch (const std::exception& exception) {
    std::cerr << "Error: " << exception.what() << std::endl;
    if (parameter_error) {
      std::cerr << "\nUsage:\n";
      std::cerr << "  " << argv[0] << " -x <n> -y <n>\n";
    }
    return 1;
  }
}
