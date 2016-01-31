// Copyright 2016 Mitchell Kember. Subject to the MIT License.
// Project Euler: Problem 23
// Non-abundant sums

#include "common.hpp"

#include <vector>

namespace problem_23 {

long solve() {
	typedef std::vector<bool>::size_type sz_t;

	// Build a lookup table and a sequence of ascending abundant numbers. This
	// method is about ten times faster than using std::map.
	constexpr long max = 28124;
	std::vector<bool> table(static_cast<sz_t>(max), false);
	std::vector<long> abundant_numbers;
	for (long i = 1; i < max; ++i) {
		const bool abundant = common::sum_proper_divisors(i) > i;
		table[static_cast<sz_t>(i)] = abundant;
		if (abundant) {
			abundant_numbers.push_back(i);
		}
	}

	// Add up numbers that aren't the sum of any two abundant numbers.
	long total = 0;
	for (long i = 1; i < max; ++i) {
		// Find out if any two abundant numbers sum to i.
		bool is_sum = false;
		const long half = i / 2;
		for (const long n : abundant_numbers) {
			if (n > half) {
				break;
			}
			if (table[static_cast<sz_t>(i - n)]) {
				is_sum = true;
				break;
			}
		}
		if (!is_sum) {
			total += i;
		}
	}
	return total;
}

} // namespace problem_23
