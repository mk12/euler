// Copyright 2014 Mitchell Kember. Subject to the MIT License.
// Project Euler: Problem 1
// Multiples of 3 and 5

pub fn solve() -> int {
	let mut sum = 0;
	for n in range(0, 1000) {
		if n % 3 == 0 || n % 5 == 0 {
			sum += n;
		}
	}
	sum
}
