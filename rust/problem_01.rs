// Copyright 2014 Mitchell Kember. Subject to the MIT License.
// Project Euler: Problem 1
// Multiples of 3 and 5

// Returns the sum of the arithmetic series that goes from 0 to 999 with a
// common difference of d.
fn arith_sum(d: int) -> int {
	let n = 999 / d;
	d * n * (n + 1) / 2
}

pub fn solve() -> int {
	arith_sum(3) + arith_sum(5) - arith_sum(15)
}
