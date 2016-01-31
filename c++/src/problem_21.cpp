// Copyright 2016 Mitchell Kember. Subject to the MIT License.
// Project Euler: Problem 21
// Amicable numbers

#include "common.hpp"

#include <array>

namespace problem_21 {

long solve() {
	typedef std::vector<long>::size_type sz_t;

	// Make a table for the sums of proper divisors of each number.
	constexpr sz_t max = 10000;
	std::vector<long> sums(max);
	for (sz_t i = 1; i < max; ++i) {
		sums[i] = common::sum_proper_divisors(static_cast<long>(i));
	}

	// Identify amicable numbers in the table and add them up.
	long total = 0;
	for (sz_t i = 1; i < max; ++i) {
		const sz_t si = static_cast<sz_t>(sums[i]);
		if (i < si && si < max && static_cast<sz_t>(sums[si]) == i) {
			total += i;
			total += si;
		}
	}
	return total;
}

} // namespace problem_21
