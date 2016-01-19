// Copyright 2016 Mitchell Kember. Subject to the MIT License.
// Project Euler: Problem 2
// Even Fibonacci numbers

namespace problem_02 {

long solve() {
	long a = 0;
	long b = 1;
	long sum = 0;
	while (a <= 4000000) {
		sum += a;
		a += b;
		b += a;
		long old_a = a;
		a = b;
		b += old_a;
	}
	return sum;
}

} // namespace problem_02
