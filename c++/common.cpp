// Copyright 2016 Mitchell Kember. Subject to the MIT License.

#include "common.hpp"

#include <gmpxx.h>

#include <vector>

#include <cassert>
#include <cmath>
#include <cstdio>

namespace common {

long max(long a, long b) {
	return a > b ? a : b;
}

long n_digits(long n) {
	long count = 0;
	while (n > 0) {
		n /= 10;
		++count;
	}
	return count;
}

bool is_palindrome(long n) {
	typedef std::vector<long>::size_type sz_t;
	sz_t count = static_cast<sz_t>(n_digits(n));
	sz_t half = count / 2;
	std::vector<long> digits(half);
	for (sz_t i = 0; i < half; ++i) {
		digits[i] = n % 10;
		n /= 10;
	}
	if (count % 2 != 0) {
		n /= 10;
	}
	for (sz_t i = 0; i < half; ++i) {
		if (n % 10 != digits[half-i-1]) {
			return false;
		}
		n /= 10;
	}
	return true;
}

bool is_prime(long n) {
	if (n <= 1) {
		return false;
	}
	if (n <= 3) {
		return true;
	}
	if (n % 2 == 0 || n % 3 == 0) {
		return false;
	}
	return is_prime_fast(n);
}

bool is_prime_fast(long n) {
	assert(n > 3);
	assert(n % 2 != 0 && n % 3 != 0);

	long max = static_cast<long>(sqrt(n));
	long div = 5;
	while (div <= max) {
		if (n % div == 0 || n % (div + 2) == 0) {
			return false;
		}
		div += 6;
	}
	return true;
}

long n_divisors(long n) {
	assert(n >= 1);

	if (n == 1) {
		return 1;
	}
	long max = static_cast<long>(sqrt(n));
	long count = max * max == n ? 1 : 2;
	long div = 2;
	while (div < max) {
		if (n % div == 0) {
			count += 2;
		}
		++div;
	}
	return count;
}

long combinations(long n, long k) {
	if (k > n - k) {
		k = n - k;
	}

	long result = 1;
	for (long i = 0; i < k; ++i) {
		result *= n - i;
		result /= i + 1;
	}
	return result;
}

} // namespace common
