// Copyright 2014 Mitchell Kember. Subject to the MIT License.
// Project Euler: Problem 7
// 10001st prime

fn is_prime(n: int) -> bool {
	if n % 2 == 0 || n % 3 == 0 {
		return false;
	}
	let max = (n as f32).sqrt() as int;
	let mut div = 5;
	while div <= max {
		if n % div == 0 || n % (div + 2) == 0 {
			return false;
		}
		div += 6;
	}
	true
}

fn main() {
	let mut n = 1;
	let mut count = 2;
	while count < 10001 {
		n += 4;
		if is_prime(n) {
			count += 1;
		}
		n += 2;
		if count < 10001 && is_prime(n) {
			count += 1;
		}
	}
	println!("{}", n);
	assert!(n == 104743);
}
