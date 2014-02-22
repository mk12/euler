// Copyright 2014 Mitchell Kember. Subject to the MIT License.
// Project Euler: Problem 6
// Sum square difference

fn main() {
	let mut sum = 0;
	let mut sq_sum = 0;
	for n in range(1, 101) {
		sum += n;
		sq_sum += n * n;
	}
	let diff = sum * sum - sq_sum;
	println!("{}", diff);
	assert!(diff == 25164150);
}
