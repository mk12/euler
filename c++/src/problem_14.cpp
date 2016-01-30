// Copyright 2016 Mitchell Kember. Subject to the MIT License.
// Project Euler: Problem 14
// Longest Collatz sequence

namespace problem_14 {

long collatz_len(long n) {
	long len = 0;
	while (n != 1) {
		if (n % 2 == 0) {
			n /= 2;
		} else {
			n = 3 * n + 1;
		}
		++len;
	}
	return len;
}

long solve() {
	long n = 0;
	long max_len = 0;
	for (long i = 1; i < 1000000; ++i) {
		const long len = collatz_len(i);
		if (len > max_len) {
			n = i;
			max_len = len;
		}
	}
	return n;
}

} // namespace problem_14
