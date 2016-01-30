// Copyright 2016 Mitchell Kember. Subject to the MIT License.
// Project Euler: Problem 25
// 1000-digit Fibonacci number

#include <gmpxx.h>

namespace problem_25 {

long solve() {
	mpz_class first(1);
	mpz_class second(1);
	mpz_class power_of_ten(10);
	mpz_class* a = &first;
	mpz_class* b = &second;

	long index = 1;
	long digits = 1;
	while (digits < 1000) {
		std::swap(a, b);
		*b += *a;
		++index;
		if (*a / power_of_ten >= 1) {
			++digits;
			power_of_ten *= 10;
		}
	}
	return index;
}

} // namespace problem_25
