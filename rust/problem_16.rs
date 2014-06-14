// Copyright 2014 Mitchell Kember. Subject to the MIT License.
// Project Euler: Problem 16
// Power digit sum

use problem_13::{big, small};
use problem_13::core::num::Zero;
use problem_13::num::bigint::BigInt;
use problem_13::num::integer::Integer;

pub fn sum_of_digits(n: BigInt) -> int {
	let ten = big(10);
	let mut m = n;
	let mut sum = big(0);
	while !m.is_zero() {
		let (quot, rem) = m.div_rem(&ten);
		m = quot;
		sum = sum + rem;
	}
	small(sum)
}

pub fn solve() -> int {
	sum_of_digits(big(2) << 999)
}
