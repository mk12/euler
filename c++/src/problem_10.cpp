// Copyright 2016 Mitchell Kember. Subject to the MIT License.
// Project Euler: Problem 10
// Summation of primes

#include "common.hpp"

namespace problem_10 {

long solve() {
	return common::sum_primes_below(2000000);
}

} // namespace problem_10
