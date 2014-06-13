// Copyright 2014 Mitchell Kember. Subject to the MIT License.
// Project Euler: Problem 6
// Sum square difference

pub fn solve() -> int {
	let mut sum = 0;
	let mut sq_sum = 0;
	for n in range(1, 101) {
		sum += n;
		sq_sum += n * n;
	}
	sum * sum - sq_sum
}
