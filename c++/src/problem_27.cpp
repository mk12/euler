// Copyright 2016 Mitchell Kember. Subject to the MIT License.
// Project Euler: Problem 27
// Quadratic primes

#include "common.hpp"

namespace problem_27 {

long num_consec_primes(const long a, const long b) {
	long n = 0;
	while (common::is_prime(n*n + a*n + b)) {
		++n;
	}
	return n;
}

long solve() {
	long best_i = 0;
	long best_j = 0;
	long n_primes = 0;
	for (long i = -999; i <= 999; ++i) {
		for (long j = -999; j <= 999; ++j) {
			const long n = num_consec_primes(j, i);
			if (n > n_primes) {
				best_i = i;
				best_j = j;
				n_primes = n;
			}
		}
	}
	return best_i * best_j;
}

} // namespace problem_27
