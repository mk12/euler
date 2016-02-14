// Copyright 2016 Mitchell Kember. Subject to the MIT License.
// Project Euler: Problem 44
// Coded triangle numbers

#include <cmath>

namespace problem_44 {

long nth_pentagonal_number(const long n) {
	return n * (3 * n - 1) / 2;
}

bool is_pentagonal(const long n) {
	double index = (1 + sqrt(1 + 24 * n)) / 6;
	return floor(index) == index;
}

long solve() {
	for (long i = 0; true; ++i) {
		const long n = nth_pentagonal_number(i);
		for (long j = i - 1; j > 0; --j) {
			const long m = nth_pentagonal_number(j);
			if (is_pentagonal(n - m) && is_pentagonal(n + m)) {
				return n - m;
			}
		}
	}
}

} // namespace problem_44
