// Copyright 2016 Mitchell Kember. Subject to the MIT License.
// Project Euler: Problem 7
// 10001st prime

#include "common.hpp"

namespace problem_07 {

long solve() {
	long n = 5;
	long count = 3;
	for (;;) {
		n += 2;
		if (common::is_prime_fast(n)) {
			++count;
			if (count == 10001) {
				break;
			}
		}
		n += 4;
		if (common::is_prime_fast(n)) {
			++count;
			if (count == 10001) {
				break;
			}
		}
	}
	return n;
}

} // namespace problem_07
