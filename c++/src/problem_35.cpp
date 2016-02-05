// Copyright 2016 Mitchell Kember. Subject to the MIT License.
// Project Euler: Problem 35
// Circular primes

#include "common.hpp"

namespace problem_35 {

bool is_circular_prime(long n) {
	const long len = common::n_digits(n);
	const long pow = common::powers_of_ten[len - 1];
	for (long i = 0; i < len; ++i) {
		if (!common::is_prime(n)) {
			return false;
		}
		n = n / 10 + (n % 10) * pow;
	}
	return true;
}

long solve() {
	constexpr long max = 1000000;
	long n = 5;
	long count = 3;
	for (;;) {
		n += 2;
		if (n >= max) {
			break;
		}
		if (is_circular_prime(n)) {
			++count;
		}
		n += 4;
		if (n >= max) {
			break;
		}
		if (is_circular_prime(n)) {
			++count;
		}
	}
	return count;
}

} // namespace problem_35
