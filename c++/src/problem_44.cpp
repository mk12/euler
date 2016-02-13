// Copyright 2016 Mitchell Kember. Subject to the MIT License.
// Project Euler: Problem 44
// Coded triangle numbers

#include <cstdio>
#include <cmath>

namespace problem_44 {

long nth_pentagonal_number(const long n) {
	return n * (3 * n - 1) / 2;
}

bool is_pentagonal(const long n) {
	const long limit = n / 2 + 1;
	const long two_n = n * 2;
	for (long i = 0; i <= limit; ++i) {
		if (i * (3 * i - 1) == two_n) {
			return true;
		}
	}
	return false;
}

long solve() {
	for (long i = 1; true; ++i) {
		const long n = nth_pentagonal_number(i);
		printf("trying %ld\n", n);

		const long limit_j = (n-1)/3;
		for (long j = 1; j <= limit_j; ++j) {
			const long first = nth_pentagonal_number(j);
			for (long k = (long)(1 + sqrt(1+24*(n+first)))/6+1; true; ++k) {
				const long second = nth_pentagonal_number(k);
				const long diff = second - first;
				// printf("%ld - %ld = %ld\n", second, first, diff);
				if (diff == n) {
					if (is_pentagonal(first + second)) {
						return n;
					}
					break;
				}
				if (diff > n) {
					break;
				}
			}
		}
	}
}

} // namespace problem_44
