// Copyright 2014 Mitchell Kember. Subject to the MIT License.
// Project Euler: Problem 20
// Factorial digit sum

use problem_13::big;
use problem_13::num::bigint::BigInt;
use problem_16::sum_of_digits;

fn factorial(n: int) -> BigInt {
	let mut fac = big(n);
	for i in range(1, n) {
		fac = fac * big(i);
	}
	fac
}

pub fn solve() -> int {
	sum_of_digits(factorial(100))
}
