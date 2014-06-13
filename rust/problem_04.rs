// Copyright 2014 Mitchell Kember. Subject to the MIT License.
// Project Euler: Problem 4
// Largest palindrome product

fn is_palindrome(n: int) -> bool {
	let size = (n as f64).log10().ceil() as int;
	let mut num = n;
	let mut digits = Vec::with_capacity((size/2) as uint);
	let mut i = 0;
	// Push the first half of the digits into the vector.
	while i < size/2 {
		digits.push(num % 10);
		num /= 10;
		i += 1;
	}
	i -= 1;
	// Skip the middle digit when there are an odd number of digits.
	if size % 2 != 0 {
		num /= 10;
	}
	// Verify that the second half of the digits matches the first.
	while i >= 0 {
		let d = num % 10;
		if d != *digits.get(i as uint) {
			return false;
		}
		num /= 10;
		i -= 1;
	}
	true
}

pub fn solve() -> int {
	let mut largest = 0;
	for a in range(100, 1000) {
		for b in range(100, 1000) {
			let c = a * b;
			if c > largest && is_palindrome(c) {
				largest = c;
			}
		}
	}
	largest
}
