// Copyright 2014 Mitchell Kember. Subject to the MIT License.
// Project Euler: Problem 2
// Even Fibonacci numbers

struct Fibonacci {
	a: int,
	b: int
}

impl Iterator<int> for Fibonacci {
	fn next(&mut self) -> Option<int> {
		let a = self.a;
		self.a = self.b;
		self.b += a;
		Some(a)
	}
}

fn main() {
	let mut seq = Fibonacci { a: 0, b: 1 };
	let mut sum = 0;
	for n in seq {
		if n > 4000000 {
			break;
		}
		if n % 2 == 0 {
			sum += n;
		}
	}
	println!("{}", sum);
	assert!(sum == 4613732);
}
