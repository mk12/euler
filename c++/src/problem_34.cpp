// Copyright 2016 Mitchell Kember. Subject to the MIT License.
// Project Euler: Problem 34
// Digit factorials

namespace problem_34 {

constexpr long factorial_table[10] = {
	1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880
};

bool is_curious(const long n) {
	long m = n;
	long sum = 0;
	while (m != 0 && sum < n) {
		sum += factorial_table[m % 10];
		m /= 10;
	}
	return m == 0 && sum == n;
}

long solve() {
	long total = 0;
	for (long i = 10; i <= 99999; ++i) {
		if (is_curious(i)) {
			total += i;
		}
	}
	return total;
}

} // namespace problem_34
