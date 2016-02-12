// Copyright 2016 Mitchell Kember. Subject to the MIT License.
// Project Euler: Problem 44
// Coded triangle numbers

namespace problem_44 {

long nth_pentagonal_number(const long n) {
	return n * (3 * n - 1) / 2;
}

bool is_pentagonal(const long n) {
	const long limit = n / 2 + 1;
	const long two_n = n * 2;
	for (long i = 0; i <= limit; ++i) {
		if (i * (3 * i - 1) == two_n) {
			return true;
		}
	}
	return false;
}

long solve() {
	return 1;
}

} // namespace problem_44
