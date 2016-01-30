// Copyright 2016 Mitchell Kember. Subject to the MIT License.
// Project Euler: Problem 3
// Largest prime factor

namespace problem_03 {

long solve() {
	long n = 600851475143;
	long factor = 1;
	while (n != 1) {
		factor += 2;
		while (n % factor == 0) {
			n /= factor;
		}
	}
	return static_cast<long>(factor);
}

} // namespace problem_03
