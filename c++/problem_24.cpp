// Copyright 2016 Mitchell Kember. Subject to the MIT License.
// Project Euler: Problem 24
// Lexicographic permutations

#include <algorithm>
#include <array>

namespace problem_24 {

long solve() {
	constexpr long n_digits = 10;
	std::array<long, n_digits> digits = {{0, 1, 2, 3, 4, 5, 6, 7, 8, 9}};
	for (long i = 0; i < 999999; ++i) {
		std::next_permutation(digits.begin(), digits.end());
	}

	long n = 0;
	for (const long d : digits) {
		n *= 10;
		n += d;
	}
	return n;
}

} // namespace problem_24
