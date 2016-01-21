// Copyright 2016 Mitchell Kember. Subject to the MIT License.

#include "common.hpp"

#include <cassert>
#include <cmath>
#include <vector>

namespace common {

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

const long Big::BIG_DIGIT_MAX = 999999999999999999;

Big::Big(long n) : _negative(n < 0), _big_digits({n}) {
	assert(std::abs(n) <= BIG_DIGIT_MAX);
}

Big::Big(const std::string& str) : _big_digits() {
	long n = 0;
	for (char c : str) {
		*this *= 10;
		*this += static_cast<long>(c - '0');
	}
}

Big& Big::operator+=(const Big& rhs) {
	return *this;
}

Big& Big::operator+=(long rhs) {
	if (rhs < 0) {
		return *this -= -rhs;
	}

	long room = BIG_DIGIT_MAX - _big_digits[0];
	if (rhs > room) {
		if (_big_digits.size() > 1) {
			++_big_digits[1];
		} else {
			_big_digits.push_back(1);
		}
		_big_digits[0] -= BIG_DIGIT_MAX - rhs + 1;
	} else {
		_big_digits[0] += room;
	}
	return *this;
}

Big& Big::operator-=(const Big& rhs) {
	return *this;
}

Big& Big::operator-=(long rhs) {
	return *this;
}

Big& Big::operator*=(const Big& rhs) {
	return *this;
}

Big& Big::operator*=(long rhs) {
	return *this;
}

Big& Big::operator/=(const Big& rhs) {
	return *this;
}

Big& Big::operator/=(long rhs) {
	return *this;
}

Big operator+(const Big& lhs, const Big& rhs) {
	return Big(0);
}

Big operator+(const Big& lhs, long rhs) {
	return Big(0);
}

Big operator+(long lhs, const Big& rhs) {
	return Big(0);
}

Big operator-(const Big& lhs, const Big& rhs) {
	return Big(0);
}

Big operator-(const Big& lhs, long rhs) {
	return Big(0);
}

Big operator-(long lhs, const Big& rhs) {
	return Big(0);
}

Big operator*(const Big& lhs, const Big& rhs) {
	return Big(0);
}

Big operator*(const Big& lhs, long rhs) {
	return Big(0);
}

Big operator*(long lhs, const Big& rhs) {
	return Big(0);
}

Big operator/(const Big& lhs, const Big& rhs) {
	return Big(0);
}

Big operator/(const Big& lhs, long rhs) {
	return Big(0);
}

Big operator/(long lhs, const Big& rhs) {
	return Big(0);
}

} // namespace common
