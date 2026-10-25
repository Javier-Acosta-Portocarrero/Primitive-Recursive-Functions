// University of La Laguna
// School of Engineering and Technology
// Bachelor's Degree in Computer Engineering
// Course: Computational Complexity
// Year: 4th
// Assignment 3: Primitive Recursive Functions
// Author: Javier Acosta Portocarrero
// Date: 24/10/2026
// File zero.h: declaration of the Zero class.

#ifndef ZERO_H
#define ZERO_H

#include "fpr.h"

// Initial zero function: Z(x) = 0.
class Zero : public FPR {
 public:
  unsigned Evaluate(const std::vector<unsigned>& arguments) override;

 protected:
  void CollectCallStatistics(std::map<std::string, unsigned long long>& statistics) const override;
};

#endif
