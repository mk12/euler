// Copyright 2014 Mitchell Kember. Subject to the MIT License.
// Project Euler: Problem 5
// Smallest multiple

pub fn solve() -> int {
	let mut n = 20;
	loop {
		let mut good = true;
		for i in range(11, 20) {
			if n % i != 0 {
				good = false;
				break;
			}
		}
		if good {
			return n;
		}
		n += 20;
	}
}
