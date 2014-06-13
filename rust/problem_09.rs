// Copyright 2014 Mitchell Kember. Subject to the MIT License.
// Project Euler: Problem 9
// Special Pythagorean triplet

fn attempt() -> Option<int> {
	for a in range(1, 500) {
		for b in range(a + 1, (1000 - a)/2) {
			let c = 1000 - a - b;
			if a * a + b * b == c * c {
				return Some(a * b * c);
			}
		}
	}
	None
}

pub fn solve() -> int {
	attempt().unwrap()
}
