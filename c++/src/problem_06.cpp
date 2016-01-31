// Copyright 2016 Mitchell Kember. Subject to the MIT License.
// Project Euler: Problem 6
// Sum square difference

namespace problem_06 {

long sum_square_diff(const long n) {
	long sum = 0;
	long sq_sum = 0;
	for (long i = 1; i <= n; ++i) {
		sum += i;
		sq_sum += i * i;
	}
	return sum * sum - sq_sum;
}

long solve() {
	return sum_square_diff(100);
}

} // namespace problem_06
