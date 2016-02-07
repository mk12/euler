// Copyright 2016 Mitchell Kember. Subject to the MIT License.
// Project Euler: Problem 30
// Digit fifth powers

namespace problem_30 {

bool is_sum_of_fifth_powers(long n) {
	long m = n;
	while (m > 0 && n > 0) {
		const long d = m % 10;
		n -= d * d * d * d * d;
		m /= 10;
	}
	return m == 0 && n == 0;
}

long solve() {
	constexpr long limit = 9*9*9*9*9*6;
	long total = 0;
	for (long i = 2; i <= limit; ++i) {
		if (is_sum_of_fifth_powers(i)) {
			total += i;
		}
	}
	return total;
}

} // namespace problem_30
