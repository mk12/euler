// Copyright 2016 Mitchell Kember. Subject to the MIT License.
// Project Euler: Problem 7
// 10001st prime

#include "common.hpp"

namespace problem_07 {

long solve() {
	long n = 1;
	long count = 0;
	while (count < 10001) {
		++n;
		if (common::is_prime(n)) {
			++count;
		}
	}
	return n;
}

} // namespace problem_07
