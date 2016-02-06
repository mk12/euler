// Copyright 2016 Mitchell Kember. Subject to the MIT License.
// Project Euler: Problem 37
// Truncatable primes

#include "common.hpp"

namespace problem_37 {

bool is_truncatable_prime(const long n) {
	const long n_digits = common::n_digits(n);
	for (long i = n_digits - 1; i > 0; --i) {
		const long left_trunc = n % common::powers_of_ten[i];
		const long right_trunc = n / common::powers_of_ten[i];
		if (!common::is_prime(left_trunc) || !common::is_prime(right_trunc)) {
			return false;
		}
	}
	return common::is_prime_fast(n);
}

long solve() {
	long total = 0;
	long count = 0;
	long n = 11;
	while (count < 11) {
		n += 2;
		if (is_truncatable_prime(n)) {
			total += n;
			++count;
		}
		n += 4;
		if (is_truncatable_prime(n)) {
			total += n;
			++count;
		}
	}
	return total;
}

} // namespace problem_37
