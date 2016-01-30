// Copyright 2016 Mitchell Kember. Subject to the MIT License.
// Project Euler: Problem 20
// Factorial digit sum

#include "common.hpp"

#include <gmpxx.h>

namespace problem_20 {

long solve() {
	mpz_class n(1);
	for (long i = 2; i <= 100; ++i) {
		n *= i;
	}
	return common::sum_of_digits(n);
}

} // namespace problem_20
