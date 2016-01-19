// Copyright 2016 Mitchell Kember. Subject to the MIT License.

#include "common.hpp"

#include <cmath>
#include <vector>

namespace common {

int n_digits(int n) {
	int count = 0;
	while (n > 0) {
		n /= 10;
		++count;
	}
	return count;
}

bool is_palindrome(int n) {
	typedef std::vector<int>::size_type sz_t;
	sz_t count = static_cast<sz_t>(n_digits(n));
	sz_t half = count / 2;
	std::vector<int> digits(half);
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

bool is_prime(int n) {
	if (n <= 1) {
		return false;
	}
	if (n <= 3) {
		return true;
	}
	if (n % 2 == 0 || n % 3 == 0) {
		return false;
	}

	int max = static_cast<int>(sqrt(n));
	int div = 5;
	while (div <= max) {
		if (n % div == 0 || n % (div + 2) == 0) {
			return false;
		}
		div += 6;
	}
	return true;
}

} // namespace common
