// Copyright 2016 Mitchell Kember. Subject to the MIT License.
// Project Euler: Problem 36
// Circular primes

#include "common.hpp"

namespace problem_36 {

long solve() {
	long total = 0;
	for (long i = 1; i < 1000000; ++i) {
		if (common::is_palindrome_binary(i) && common::is_palindrome(i)) {
			total += i;
		}
	}
	return total;
}

} // namespace problem_36
