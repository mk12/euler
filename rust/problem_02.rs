// Copyright 2014 Mitchell Kember. Subject to the MIT License.
// Project Euler: Problem 2
// Even Fibonacci numbers

pub fn solve() -> int {
	let mut a = 0;
	let mut b = 1;
	let mut sum = 0;
	while a <= 4_000_000 {
		sum += a;
		a += b;
		b += a;
		let old_a = a;
		a = b;
		b += old_a;
	}
	sum
}
