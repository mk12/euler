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

const long big::DIGIT_MAX = 999999999999999999;

big::big(long n) : _negative(n < 0), _digits({n}) {
	assert(std::abs(n) <= BIG_DIGIT_MAX);
}

big::big(const std::string& str) : _digits(1) {
	for (char c : str) {
		*this *= 10;
		*this += static_cast<long>(c - '0');
	}
}

long big::truncate() const {
	return _digits[0];
}

bool big::negative() const {
	return _negative;
}

big::iterator big::begin() const {
	return iterator(*this, 0, _digits[0]);
}

big::iterator big::end() const {
	return iterator(*this, static_cast<long>(_digits.size()), 0);
}

big::reverse_iterator big::rbegin() const {
	const long index = static_cast<long>(_digits.size() - 1);
	return reverse_iterator(*this, index, _digits[index]);
}

big::reverse_iterator big::rend() const {
	return reverse_iterator(*this, -1, 0);
}

big& big::operator+=(const big& rhs) {
	return *this;
}

big& big::operator+=(long rhs) {
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

big& big::operator-=(const big& rhs) {
	return *this;
}

big& big::operator-=(long rhs) {
	return *this;
}

big& big::operator*=(const big& rhs) {
	return *this;
}

big& big::operator*=(long rhs) {
	return *this;
}

big& big::operator/=(const big& rhs) {
	return *this;
}

big& big::operator/=(long rhs) {
	return *this;
}

big operator+(const big& lhs, const big& rhs) {
	return big(0);
}

big operator+(const big& lhs, long rhs) {
	return big(0);
}

big operator+(long lhs, const big& rhs) {
	return big(0);
}

big operator-(const big& lhs, const big& rhs) {
	return big(0);
}

big operator-(const big& lhs, long rhs) {
	return big(0);
}

big operator-(long lhs, const big& rhs) {
	return big(0);
}

big operator*(const big& lhs, const big& rhs) {
	return big(0);
}

big operator*(const big& lhs, long rhs) {
	return big(0);
}

big operator*(long lhs, const big& rhs) {
	return big(0);
}

big operator/(const big& lhs, const big& rhs) {
	return big(0);
}

big operator/(const big& lhs, long rhs) {
	return big(0);
}

big operator/(long lhs, const big& rhs) {
	return big(0);
}

big::iterator::iterator(const big& n, long index, long digit)
	: _big(n), _index(index), _digit(digit) {}

big::iterator::iterator(const iterator& rhs)
	: _big(rhs._big), _index(rhs._index), _digit(rhs._digit) {}

big::iterator::~iterator() {}

big::iterator& big::iterator::operator++() {
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

big::iterator big::iterator::operator++(int) {
	iterator temp(*this);
	++*this;
	return temp;
}

bool big::iterator::operator==(const iterator& rhs) const {
	return &_big == &rhs._big && _index == rhs._index && _digit == rhs._digit;
}

bool big::iterator::operator!=(const iterator& rhs) const {
	return !(*this == rhs);
}

long big::iterator::operator*() const {
	assert(_index < _big._digits.size());
	return _digit % 10;
}

big::reverse_iterator::reverse_iterator(const big& n, long index, long digit)
	: _big(n), _index(0), _digit(digit), _divisor(initial_divisor(digit)) {}

big::reverse_iterator::reverse_iterator(const reverse_iterator& rhs)
	: _big(rhs._big), _index(rhs._index), _digit(rhs._digit),
	_divisor(rhs._divisor) {}

big::reverse_iterator::~reverse_iterator() {}

big::reverse_iterator& big::reverse_iterator::operator++() {
	assert(_index >= 0);

	if (_divisor == 1) {
		--_index;
		if (_index == -1) {
			_digit = 0;
		} else {
			_digit = _big._digits[_index];
			_divisor = initial_divisor(_digit);
		}
	} else {
		_divisor /= 10;
	}
}

big::reverse_iterator big::reverse_iterator::operator++(int) {
	reverse_iterator temp(*this);
	++*this;
	return temp;
}

bool big::reverse_iterator::operator==(const reverse_iterator& rhs) const {
	return &_big == &rhs._big && _index == rhs._index && _digit == rhs._digit
		&& _divisor == rhs._divisor;
}

bool big::reverse_iterator::operator!=(const reverse_iterator& rhs) const {
	return !(*this == rhs);
}

long big::reverse_iterator::operator*() const {
	assert(_index > 0);
	return _digit / _divisor;
}

long big::reverse_iterator::initial_divisor(long digit)
{
	long divisor = 1;
	while (digit > 10) {
		digit /= 10;
		divisor *= 10;
	}
	return divisor;
}

} // namespace common
