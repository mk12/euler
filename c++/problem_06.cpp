// Copyright 2016 Mitchell Kember. Subject to the MIT License.
// Project Euler: Problem 6
// Sum square difference

namespace problem_06 {

int solve() {
	int sum = 0;
	int sq_sum = 0;
	for (int i = 1; i <= 100; ++i) {
		sum += i;
		sq_sum += i * i;
	}
	return sum * sum - sq_sum;
}

} // namespace problem_06
