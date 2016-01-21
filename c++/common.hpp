// Copyright 2016 Mitchell Kember. Subject to the MIT License.

#pragma once

#include <string>
#include <vector>

namespace common {

long n_digits(long n);
bool is_palindrome(long n);
bool is_prime(long n);
bool is_prime_fast(long n);
long n_divisors(long n);

class Big {
public:
	explicit Big(long n);
	explicit Big(const std::string& str);

	long truncate() const;
	long first18digits() const;
	bool negative() const;

	Big& operator+=(const Big& rhs);
	Big& operator+=(long rhs);
	Big& operator-=(const Big& rhs);
	Big& operator-=(long rhs);
	Big& operator*=(const Big& rhs);
	Big& operator*=(long rhs);
	Big& operator/=(const Big& rhs);
	Big& operator/=(long rhs);

	friend Big operator+(const Big& lhs, const Big& rhs);
	friend Big operator+(const Big& lhs, long rhs);
	friend Big operator+(long lhs, const Big& rhs);
	friend Big operator-(const Big& lhs, const Big& rhs);
	friend Big operator-(const Big& lhs, long rhs);
	friend Big operator-(long lhs, const Big& rhs);
	friend Big operator*(const Big& lhs, const Big& rhs);
	friend Big operator*(const Big& lhs, const Big& rhs);
	friend Big operator*(const Big& lhs, long rhs);
	friend Big operator/(long lhs, const Big& rhs);
	friend Big operator/(const Big& lhs, long rhs);
	friend Big operator/(long lhs, const Big& rhs);

private:
	bool _negative;
	std::vector<long> _big_digits;
	static const long BIG_DIGIT_MAX;
};

} // namespace common
