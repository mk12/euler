// Copyright 2014 Mitchell Kember. Subject to the MIT License.
// Project Euler: Problem 3
// Largest prime factor

fn is_prime(n: int) -> bool {
	if n < 2 { return false; }
	if n == 2 || n == 3 { return true; }
	if n % 2 == 0 || n % 3 == 0 { return false; }
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
	let n = 600851475143;
	for m in range(2, n/2) {
		if n % m == 0 {
			let factor = n / m;
			if is_prime(factor) {
				println!("{}", factor);
				assert!(factor == 6857);
				return;
			}
		}
	}
}
