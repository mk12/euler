// Copyright 2016 Mitchell Kember. Subject to the MIT License.
// Project Euler: Problem 5
// Smallest multiple

namespace problem_05 {

long solve() {
	long n = 20;
	bool good = false;

	while (!good) {
		n += 20;
		good = true;
		for (long i = 11; i < 20; ++i) {
			if (n % i != 0) {
				good = false;
				break;
			}
		}
	}
	return n;
}

} // namespace problem_05
