// University of La Laguna
// School of Engineering and Technology
// Bachelor's Degree in Computer Engineering
// Course: Computational Complexity
// Year: 4th
// Assignment 3: Primitive Recursive Functions
// Author: Javier Acosta Portocarrero
// Date: 24/10/2026
// File fpr.h: declaration of the abstract FPR class.

#ifndef FPR_H
#define FPR_H

#include <cstddef>
#include <map>
#include <string>
#include <vector>

// Common interface for primitive recursive functions over natural numbers.
class FPR {
 public:
  virtual ~FPR() = default;

  virtual unsigned Evaluate(const std::vector<unsigned>& arguments) = 0;
  unsigned long long GetCallCount() const;
  unsigned long long GetTotalCallCount() const;
  std::map<std::string, unsigned long long> GetCallStatistics() const;
  virtual void ResetCounters();

 protected:
  void RegisterCall();
  static void ValidateArity(const std::vector<unsigned>& arguments, std::size_t expected_arity, const std::string& function_name);
  void RegisterStatistics(std::map<std::string, unsigned long long>& statistics, const std::string& function_name) const;
  void RegisterDependencyStatistics(std::map<std::string, unsigned long long>& statistics, const FPR& dependency) const;
  virtual void CollectCallStatistics(std::map<std::string, unsigned long long>& statistics) const = 0;

 private:
  unsigned long long call_count_ = 0;
};

#endif
