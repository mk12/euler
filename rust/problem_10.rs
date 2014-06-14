// Copyright 2014 Mitchell Kember. Subject to the MIT License.
// Project Euler: Problem 10
// Summation of primes

use problem_07::is_prime;

pub fn solve() -> int {
	let max = 2000000;
	let mut sum = 2 + 3;
	let mut n = 1;
	loop {
		n += 4;
		if n >= max { break; }
		if is_prime(n) { sum += n; }
		n += 2;
		if n >= max { break; }
		if is_prime(n) { sum += n; }
	}
	sum
}
