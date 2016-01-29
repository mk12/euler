// Copyright 2016 Mitchell Kember. Subject to the MIT License.
// Project Euler: Problem 16
// Power digit sum

#include "common.hpp"

#include <gmpxx.h>

namespace problem_16 {

long solve() {
	mpz_class n;
	mpz_ui_pow_ui(n.get_mpz_t(), 2, 1000);
	return common::sum_of_digits(n);
}

} // namespace problem_16
