// Copyright 2016 Mitchell Kember. Subject to the MIT License.
// Project Euler: Problem 40
// Champernowne's constant

#include "common.hpp"

namespace problem_40 {

// https://oeis.org/A033714
constexpr long n_terms = 10;
constexpr long sequence[n_terms] = {
	1, 10, 190, 2890, 38890, 488890, 5888890, 68888890, 788888890, 8888888890
};

long nth_digit(const long n) {
	for (long i = 1; i < n_terms; ++i) {
		const long m = sequence[i];
		if (n < m) {
			const long diff = n - sequence[i - 1];
			const long div = diff / i;
			const long mod = diff % i;
			const long base = common::powers_of_ten[i - 1];
			const long number = base + div;
			const long index = i - mod - 1;
			const long shifted = number / common::powers_of_ten[index];
			return shifted % 10;
		}
	}
	return -1;
}

long solve() {
	long product = 1;
	for (long i = 0; i <= 6; ++i) {
		product *= nth_digit(common::powers_of_ten[i]);
	}
	return product;
}

} // namespace problem_40
