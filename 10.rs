// Copyright 2014 Mitchell Kember. Subject to the MIT License.
// Project Euler: Problem 10
// Summation of primes

fn is_prime(n: int) -> bool {
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
	let max = 2000000;
	let mut sum = 2 + 3;
	let mut n = 1;
	loop {
		n += 4;
		if n >= max { break; }
		if is_prime(n) { sum += n; }
		n += 2;
		if n >= max { break; }
		if is_prime(n) { sum += n; }
	}
	println!("{}", sum);
	assert!(sum == 142913828922);
}
