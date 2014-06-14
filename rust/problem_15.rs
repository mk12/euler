// Copyright 2014 Mitchell Kember. Subject to the MIT License.
// Project Euler: Problem 15
// Lattice paths

use std::iter::range_inclusive;
use problem_13::{big, small};

fn combinations(n: int, k: int) -> int {
	let mut c = big(1);
	for x in range_inclusive(n-k+1, n) {
		c = c * big(x);
	}
	for x in range_inclusive(1, k) {
		c = c / big(x);
	}
	small(c)
}

pub fn solve() -> int {
	combinations(40, 20)
}
