// University of La Laguna
// School of Engineering and Technology
// Bachelor's Degree in Computer Engineering
// Course: Computational Complexity
// Year: 4th
// Assignment 3: Primitive Recursive Functions
// Author: Javier Acosta Portocarrero
// Date: 24/10/2026
// File multiplication.h: declaration of the Multiplication class.

#ifndef MULTIPLICATION_H
#define MULTIPLICATION_H

#include "addition.h"
#include "fpr.h"
#include "zero.h"

// Limit equation: M(x, 0) = g(x) = Z(x).
// Recursion equation: M(x, S(y)) = h(x, y, M(x, y))
//                    = (A o (P_3^3 x P_1^3))(x, y, M(x, y)).
class Multiplication : public FPR {
 public:
  unsigned Evaluate(const std::vector<unsigned>& arguments) override;
  void ResetCounters() override;

 protected:
  void CollectCallStatistics(std::map<std::string, unsigned long long>& statistics) const override;

 private:
  Zero zero_;
  Addition addition_;
};

#endif
