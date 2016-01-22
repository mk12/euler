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

const long Big::DIGIT_MAX = 999999999999999999;

Big::Big(long n) : _negative(n < 0), _digits({n}) {
	assert(std::abs(n) <= BIG_DIGIT_MAX);
}

Big::Big(const std::string& str) : _digits(1) {
	for (char c : str) {
		*this *= 10;
		*this += static_cast<long>(c - '0');
	}
}

long Big::truncate() const {
	return _digits[0];
}

bool Big::negative() const {
	return _negative;
}

Big::Iterator Big::begin() const {
	return Iterator(*this, 0, _digits[0]);
}

Big::Iterator Big::end() const {
	return Iterator(*this, static_cast<long>(_digits.size()), 0);
}

Big& Big::operator+=(const Big& rhs) {
	return *this;
}

Big& Big::operator+=(long rhs) {
	if (rhs < 0) {
		return *this -= -rhs;
	}

	long room = DIGIT_MAX - _digits[0];
	if (rhs > room) {
		if (_digits.size() > 1) {
			++_digits[1];
		} else {
			_digits.push_back(1);
		}
		_digits[0] -= DIGIT_MAX - rhs + 1;
	} else {
		_digits[0] += room;
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

Big::Iterator::Iterator(const Big& big, long index, long digit)
	: _big(big), _index(0), _digit(digit) {}

Big::Iterator::Iterator(const Iterator& rhs)
	: _big(rhs._big), _index(rhs._index), _digit(rhs._digit) {}

Big::Iterator::~Iterator() {}

Big::Iterator& Big::Iterator::operator++() {
	const long size = static_cast<long>(_big._digits.size());
	assert(_index < size);

	if (_digit == 0) {
		++_index;
		if (_index == size) {
			_digit = 0;
		} else {
			_digit = _big._digits[_index];
		}
	} else {
		_digit /= 10;
	}
}

Big::Iterator Big::Iterator::operator++(int) {
	Iterator temp(*this);
	++*this;
	return temp;
}

bool Big::Iterator::operator==(const Iterator& rhs) const {
	return &_big == &rhs._big && _index == rhs._index && _digit == rhs._digit;
}

bool Big::Iterator::operator!=(const Iterator& rhs) const {
	return !(*this == rhs);
}

long Big::Iterator::operator*() const {
	assert(_index < _big._digits.size());
	return _digit % 10;
}

} // namespace common
