// Copyright 2016 Mitchell Kember. Subject to the MIT License.
// Project Euler: Problem 29
// Distinct powers

#include <gmpxx.h>

#include <set>

namespace problem_29 {

long solve() {
	std::set<mpz_class> powers;
	for (long i = 2; i <= 100; ++i) {
		for (long j = 2; j <= 100; ++j) {
			mpz_class n;
			mpz_ui_pow_ui(n.get_mpz_t(), i, j);
			powers.insert(n);
		}
	}
	return static_cast<long>(powers.size());
}

} // namespace problem_29
