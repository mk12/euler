// Copyright 2016 Mitchell Kember. Subject to the MIT License.
// Project Euler: Problem 16
// Power digit sum

#include <gmpxx.h>

namespace problem_16 {

long solve() {
	mpz_class n;
	mpz_ui_pow_ui(n.get_mpz_t(), 2, 1000);
	std::string str = n.get_str();

	long sum = 0;
	for (char c : str) {
		sum += c - '0';
	}
	return sum;
}

} // namespace problem_16
