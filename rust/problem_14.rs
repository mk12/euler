// Copyright 2014 Mitchell Kember. Subject to the MIT License.
// Project Euler: Problem 14
// Largest Collatz sequence

// Returns the length of the Collatz sequence beginning with n.
fn collatz_len(n: int) -> int {
	let mut len = 1;
	let mut m = n;
	while m != 1 {
		let even = m % 2 == 0;
		m = if even { m >> 1 } else { 3 * m + 1 };
		len += 1;
	}
	len
}

pub fn solve() -> int {
	let mut best = 1;
	let mut best_len = 1;
	for i in range(2, 1_000_000) {
		let len = collatz_len(i);
		if len > best_len {
			best = i;
			best_len = len;
		}
	}
	best
}
