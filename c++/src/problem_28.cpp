// Copyright 2016 Mitchell Kember. Subject to the MIT License.
// Project Euler: Problem 28
// Number spiral diagonals

#include <cassert>

namespace problem_28 {

long diagonal_spiral_sum(const long n) {
	assert(n % 2 == 1);

	long x = 1;
	long sum = 1;
	for (long i = 2; i < n; i += 2) {
		sum += 4 * x + 10 * i;
		x += 4 * i;
	}
	return sum;
}

long solve() {
	return diagonal_spiral_sum(1001);
}

} // namespace problem_28
