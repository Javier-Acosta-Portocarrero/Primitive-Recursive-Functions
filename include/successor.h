// University of La Laguna
// School of Engineering and Technology
// Bachelor's Degree in Computer Engineering
// Course: Computational Complexity
// Year: 4th
// Assignment 3: Primitive Recursive Functions
// Author: Javier Acosta Portocarrero
// Date: 24/10/2026
// File successor.h: declaration of the Successor class.

#ifndef SUCCESSOR_H
#define SUCCESSOR_H

#include "fpr.h"

// Initial successor function: S(x) = x + 1.
class Successor : public FPR {
 public:
  unsigned Evaluate(const std::vector<unsigned>& arguments) override;

 protected:
  void CollectCallStatistics(std::map<std::string, unsigned long long>& statistics) const override;
};

#endif
