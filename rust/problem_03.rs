// Copyright 2014 Mitchell Kember. Subject to the MIT License.
// Project Euler: Problem 3
// Largest prime factor

pub fn solve() -> int {
	let mut n = 600851475143;
	let mut factor = 1;
	while n != 1 {
		factor += 2;
		while n % factor == 0 {
			n /= factor;
		}
	}
	factor
}
