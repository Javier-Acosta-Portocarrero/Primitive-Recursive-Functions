// University of La Laguna
// School of Engineering and Technology
// Bachelor's Degree in Computer Engineering
// Course: Computational Complexity
// Year: 4th
// Assignment 3: Primitive Recursive Functions
// Author: Javier Acosta Portocarrero
// Date: 24/10/2026
// File addition.h: declaration of the Addition class.

#ifndef ADDITION_H
#define ADDITION_H

#include "fpr.h"
#include "projection.h"
#include "successor.h"

// Limit equation: A(x, 0) = g(x) = P_1^1(x).
// Recursion equation: A(x, S(y)) = h(x, y, A(x, y))
//                    = (S o P_3^3)(x, y, A(x, y)).
class Addition : public FPR {
 public:
  unsigned Evaluate(const std::vector<unsigned>& arguments) override;
  void ResetCounters() override;

 protected:
  void CollectCallStatistics(std::map<std::string, unsigned long long>& statistics) const override;

 private:
  Projection first_projection_{1, 1};
  Projection result_projection_{3, 3};
  Successor successor_;
};

#endif
