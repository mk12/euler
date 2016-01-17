// Copyright 2016 Mitchell Kember. Subject to the MIT License.
// Project Euler: Problem 2
// Even Fibonacci numbers

namespace problem_02 {

int solve() {
	int a = 0;
	int b = 1;
	int sum = 0;
	while (a <= 4000000) {
		sum += a;
		a += b;
		b += a;
		int old_a = a;
		a = b;
		b += old_a;
	}
	return sum;
}

} // namespace problem_02
