// Copyright 2014 Mitchell Kember. Subject to the MIT License.
// Project Euler: Problem 17
// Number letter count

pub fn solve() -> int {
	let and = 3;
	let hundred = 7;
	let one_thousand = 3 + 8;
	let a = 0+3+3+5+4+4+3+5+5+4; // 0,   1, ..., 9
	let b = 3+6+6+8+8+7+7+9+8+8; // 10, 11, ..., 19
	let c = 6+6+5+5+5+7+6+6;     // 20, 30, ..., 90
	let s99 = 10*c + 9*a + b;
	10*s99 + (100*a + 9*100*hundred) + 9*99*and + one_thousand
}
