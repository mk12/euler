// Copyright 2016 Mitchell Kember. Subject to the MIT License.
// Project Euler: Problem 41
// Pandigital prime

#include "common.hpp"

#include <array>

namespace problem_41 {

bool is_pandigital(long n) {
	typedef std::array<bool, 9>::size_type sz_t;

	// Record the occurrences of the digits.
	std::array<bool, 9> digits = {};
	sz_t n_digits = 0;
	while (n != 0) {
		const long d = n % 10;
		const sz_t index = static_cast<sz_t>(d - 1);
		if (d == 0 || digits[index]) {
			return false;
		}
		digits[index] = true;
		n /= 10;
		++n_digits;
	}
	// Make sure each digit 1 through n_digits occured exactly once.
	for (sz_t i = 0; i < n_digits; ++i) {
		if (!digits[i]) {
			return false;
		}
	}
	return true;
}

long solve() {
	long n = 5;
	long max = 7000001;
	while (n <= 7654321) {
		n += 2;
		if (is_pandigital(n) && common::is_prime_fast(n)) {
			max = n;
		}
		n += 4;
		if (is_pandigital(n) && common::is_prime_fast(n)) {
			max = n;
		}
	}
	return max;
}

} // namespace problem_41
