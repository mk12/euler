// Copyright 2016 Mitchell Kember. Subject to the MIT License.
// Project Euler: Problem 38
// Pandigital multiples

#include "common.hpp"

#include <array>

namespace problem_38 {

long find_pandigital(const long n) {
	typedef std::array<bool, 9>::size_type sz_t;

	long total_digits = 0;
	std::array<bool, 9> digits = {};
	for (long i = 1; i <= 9; ++i) {
		// Get the next multiple.
		long m = n * i;

		// Record the occurrences of digits 1 through 9.
		while (m != 0) {
			++total_digits;
			if (total_digits > 9) {
				return -1;
			}

			const long d = m % 10;
			const sz_t index = static_cast<sz_t>(d - 1);
			if (d == 0 || digits[index]) {
				return -1;
			}
			digits[index] = true;
			m /= 10;
		}

		// Check if each digit 1 through 9 occurred exactly once so far.
		bool pandigital = true;
		for (const bool present : digits) {
			if (!present) {
				pandigital = false;
				break;
			}
		}

		// If it's pandigital, create the concatenated product.
		if (pandigital) {
			long concat = 0;
			for (long j = 1; j <= i; ++j) {
				const long multiple = n * j;
				concat *= common::powers_of_ten[common::n_digits(multiple)];
				concat += multiple;
			}
			return concat;
		}
	}
	return -1;
}

long solve() {
	constexpr long limit = 9876;
	long max = 0;
	for (long i = 1; i <= limit; ++i) {
		const long n = find_pandigital(i);
		if (n > max) {
			max = n;
		}
	}
	return max;
}

} // namespace problem_38
