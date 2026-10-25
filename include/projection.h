// University of La Laguna
// School of Engineering and Technology
// Bachelor's Degree in Computer Engineering
// Course: Computational Complexity
// Year: 4th
// Assignment 3: Primitive Recursive Functions
// Author: Javier Acosta Portocarrero
// Date: 24/10/2026
// File projection.h: declaration of the Projection class.

#ifndef PROJECTION_H
#define PROJECTION_H

#include "fpr.h"

// Initial projection function: P_i^n(x1, ..., xn) = xi (one-based index).
class Projection : public FPR {
 public:
  Projection(unsigned arity, unsigned index);

  unsigned Evaluate(const std::vector<unsigned>& arguments) override;

 protected:
  void CollectCallStatistics(std::map<std::string, unsigned long long>& statistics) const override;

 private:
  unsigned arity_;
  unsigned index_;
};

#endif
