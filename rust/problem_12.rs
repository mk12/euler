// Copyright 2014 Mitchell Kember. Subject to the MIT License.
// Project Euler: Problem 12
// Highly divisible triangular number

// off by one for perfect squares
fn divisors(n: int) -> int {
	let mut count = 2;
	for i in range(2, (n as f32).sqrt() as int + 1) {
		if n % i == 0 {
			count += 1;
		}
	}
	count * 2
}

pub fn solve() -> int {
	let mut tri = 1;
	let mut i = 1;
	loop {
		if divisors(tri) > 500 {
			return tri;
		}
		i += 1;
		tri += i;
	}
}
