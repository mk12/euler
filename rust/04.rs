// Copyright 2014 Mitchell Kember. Subject to the MIT License.
// Project Euler: Problem 4
// Largest palindrome product

fn is_palindrome(n: int) -> bool {
	let size = (n as f64).log10().ceil() as int;
	let mut num = n;
	let mut digits = ~[];
	let mut i = 0;
	while i < size/2 {
		digits.push(num % 10);
		num /= 10;
		i += 1;
	}
	i -= 1;
	if size % 2 != 0 {
		num /= 10;
	}
	while i >= 0 {
		let d = num % 10;
		if d != digits[i] {
			return false;
		}
		num /= 10;
		i -= 1;
	}
	true
}

fn main() {
	let mut largest = 0;
	for a in range(100, 1000) {
		for b in range (100, 1000) {
			let c = a * b;
			if c > largest && is_palindrome(c) {
				largest = c;
			}
		}
	}
	println!("{}", largest);
	assert!(largest == 906609);
}
