// Copyright 2016 Mitchell Kember. Subject to the MIT License.
// Project Euler: Problem 10
// Summation of primes

#include "common.hpp"

namespace problem_10 {

long solve() {
	long sum = 2 + 3 + 5;
	long n = 5;
	const long max = 2000000;

	for (;;) {
		n += 2;
		if (n >= max) {
			break;
		}
		if (common::is_prime_fast(n)) {
			sum += n;
		}

		n += 4;
		if (n >= max) {
			break;
		}
		if (common::is_prime_fast(n)) {
			sum += n;
		}
	}
	return sum;
}

} // namespace problem_10
