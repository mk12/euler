// Copyright 2016 Mitchell Kember. Subject to the MIT License.
// Project Euler: Problem 26
// Reciprocal cycles

#include <vector>

namespace problem_26 {

long recurring_cycle_len(const long n) {
	long dividend = 10;
	std::vector<long> remainders;
	while (dividend > 0) {
		// Check if the next remainder has ocurred before.
		const long rem = dividend % n;
		const auto end = remainders.end();
		const auto it = std::find(remainders.begin(), end, rem);
		if (it != end) {
			return std::distance(it, end);
		}

		remainders.push_back(rem);
		dividend = rem * 10;
	}
	return 0;
}

long solve() {
	long result = 1;
	long max_len = 0;
	for (long i = 1; i < 1000; ++i) {
		const long len = recurring_cycle_len(i);
		if (len > max_len) {
			result = i;
			max_len = len;
		}
	}
	return result;
}

} // namespace problem_26
