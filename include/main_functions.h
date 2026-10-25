// University of La Laguna
// School of Engineering and Technology
// Bachelor's Degree in Computer Engineering
// Course: Computational Complexity
// Year: 4th
// Assignment 3: Primitive Recursive Functions
// Author: Javier Acosta Portocarrero
// Date: 24/10/2026
// File main_functions.h: declaration of the primitive recursive functions program helpers.

#ifndef PRIMITIVE_RECURSIVE_FUNCTIONS_PROGRAM_H
#define PRIMITIVE_RECURSIVE_FUNCTIONS_PROGRAM_H

#include "fpr.h"

void ReadProgramArguments(int argc, char* argv[], unsigned& base, unsigned& exponent, bool& parameter_error);
void PrintCallStatistics(const FPR& function);

#endif
