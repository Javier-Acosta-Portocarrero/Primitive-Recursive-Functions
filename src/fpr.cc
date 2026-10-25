// University of La Laguna
// School of Engineering and Technology
// Bachelor's Degree in Computer Engineering
// Course: Computational Complexity
// Year: 4th
// Assignment 3: Primitive Recursive Functions
// Author: Javier Acosta Portocarrero
// Date: 24/10/2026
// File fpr.cc: implementation of the abstract FPR class.

#include "../include/fpr.h"
#include "../include/exceptions/fpr_exception.h"

/**
 * @brief Returns the number of calls made to this FPR instance.
 */
unsigned long long FPR::GetCallCount() const {
  return call_count_;
}

/**
 * @brief Returns the number of calls made to this FPR and all its dependencies.
 */
unsigned long long FPR::GetTotalCallCount() const {
  unsigned long long total_calls = 0;
  for (const auto& [function_name, calls] : GetCallStatistics()) {
    total_calls += calls;
  }
  return total_calls;
}

/**
 * @brief Collects the call counts of all FPR objects owned by this instance.
 */
std::map<std::string, unsigned long long> FPR::GetCallStatistics() const {
  std::map<std::string, unsigned long long> statistics;
  CollectCallStatistics(statistics);
  return statistics;
}

/**
 * @brief Resets this instance's counter without affecting unrelated objects.
 */
void FPR::ResetCounters() {
  call_count_ = 0;
}

/**
 * @brief Registers a call to the current primitive recursive function.
 */
void FPR::RegisterCall() {
  ++call_count_;
}

/**
 * @brief Checks that a function received the expected number of arguments.
 *
 * @throws FPRException If the function's arity does not match.
 */
void FPR::ValidateArity(const std::vector<unsigned>& arguments, std::size_t expected_arity, const std::string& function_name) {
  if (arguments.size() != expected_arity) {
    throw FPRException(function_name + " expects " + std::to_string(expected_arity) + " arguments.");
  }
}

/**
 * @brief Adds this instance's calls to a statistics collection.
 */
void FPR::RegisterStatistics(std::map<std::string, unsigned long long>& statistics, const std::string& function_name) const {
  statistics[function_name] += call_count_;
}

/**
 * @brief Merges the statistics of a privately owned FPR object.
 */
void FPR::RegisterDependencyStatistics(std::map<std::string, unsigned long long>& statistics, const FPR& dependency) const {
  for (const auto& [function_name, calls] : dependency.GetCallStatistics()) {
    statistics[function_name] += calls;
  }
}
