// Copyright 2014 Mitchell Kember. Subject to the MIT License.
// Project Euler: Problem 5
// Smallest multiple

fn main() {
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
			println!("{}", n);
			assert!(n == 232792560);
			return;
		}
		n += 20;
	}
}
