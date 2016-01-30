// Copyright 2016 Mitchell Kember. Subject to the MIT License.
// Project Euler: Problem 12
// Highly divisible triangular number

#include "common.hpp"

namespace problem_12 {

long solve() {
	long tri = 1;
	long inc = 2;
	while (common::n_divisors(tri) <= 500) {
		tri += inc;
		++inc;
	}
	return tri;
}

} // namespace problem_12
