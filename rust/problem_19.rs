// Copyright 2014 Mitchell Kember. Subject to the MIT License.
// Project Euler: Problem 19
// Counting Sundays

use std::iter::range_inclusive;

static month_lens: [uint, ..12] = [
	31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
];

fn is_leap(year: uint) -> bool {
	year % 400 == 0 || (year % 100 != 0 && year % 4 == 0)
}

fn n_days(year: uint, month: uint) -> uint {
	if month == 1 && is_leap(year) {
		29
	} else {
		month_lens[month]
	}
}

pub fn solve() -> int {
	let mut day = 2;
	let mut count = 0;
	for year in range_inclusive(1901u, 2000) {
		for month in range(0u, 12) {
			if day % 7 == 0 { count += 1; }
			day += n_days(year, month);
		}
	}
	count
}
