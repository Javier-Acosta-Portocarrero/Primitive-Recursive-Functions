// University of La Laguna
// School of Engineering and Technology
// Bachelor's Degree in Computer Engineering
// Course: Computational Complexity
// Year: 4th
// Assignment 3: Primitive Recursive Functions
// Author: Javier Acosta Portocarrero
// Date: 24/10/2026
// File power.h: declaration of the Power class.

#ifndef POWER_H
#define POWER_H

#include "fpr.h"
#include "multiplication.h"
#include "successor.h"
#include "zero.h"
#include "projection.h"

// Limit equation: P(x, 0) = g(x) = (S o Z)(x).
// Recursion equation: P(x, S(y)) = h(x, y, P(x, y))
//                    = (M o (P_1^3 x P_3^3))(x, y, P(x, y)).
class Power : public FPR {
 public:
  unsigned Evaluate(const std::vector<unsigned>& arguments) override;
  void ResetCounters() override;

 protected:
  void CollectCallStatistics(std::map<std::string, unsigned long long>& statistics) const override;

 private:
  Zero zero_;
  Successor successor_;
  Projection base_projection_{3, 1};
  Projection result_projection_{3, 3};
  Multiplication multiplication_;
};

#endif
