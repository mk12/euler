// Copyright 2016 Mitchell Kember. Subject to the MIT License.
// Project Euler: Problem 33
// Digit cancelling fractions

#include "common.hpp"

namespace problem_33 {

bool is_curious(const long num, const long den) {
	const long num_d1 = num % 10;
	const long num_d2 = num / 10;
	const long den_d1 = den % 10;
	const long den_d2 = den / 10;

	if (num_d1 == 0 || den_d1 == 0) {
		return false;
	}
	if (num_d1 == den_d1) {
		return num * den_d2 == den * num_d2;
	}
	if (num_d1 == den_d2) {
		return num * den_d1 == den * num_d2;
	}
	if (num_d2 == den_d1) {
		return num * den_d2 == den * num_d1;
	}
	if (num_d2 == den_d2) {
		return num * den_d1 == den * num_d1;
	}
	return false;
}

long solve() {
	long num = 1;
	long den = 1;
	for (long d = 12; d <= 99; ++d) {
		for (long n = 11; n < d; ++n) {
			if (is_curious(n, d)) {
				num *= n;
				den *= d;
			}
		}
	}
	common::reduce_fraction(num, den);
	return den;
}

} // namespace problem_33
