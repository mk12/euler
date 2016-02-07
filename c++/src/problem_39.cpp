// Copyright 2016 Mitchell Kember. Subject to the MIT License.
// Project Euler: Problem 39
// Integer right triangles

#include "common.hpp"

namespace problem_39 {

long n_solutions(const long n) {
	long count = 0;
	const long limit_i = n / 3;
	for (long i = 1; i < limit_i; ++i) {
		const long limit_j = (n - i) / 2;
		for (long j = i + 1; j < limit_j; ++j) {
			const long k = n - i - j;
			if (i*i + j*j == k*k) {
				++count;
			}
		}
	}
	return count;
}

long solve() {
	long perimeter = 0;
	long max_solns = 0;
	for (long i = 1; i <= 1000; ++i) {
		const long n = n_solutions(i);
		if (n > max_solns) {
			perimeter = i;
			max_solns = n;
		}
	}
	return perimeter;
}

} // namespace problem_39
