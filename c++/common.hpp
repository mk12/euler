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
	bool negative() const;

	class Iterator;
	Iterator begin() const;
	Iterator end() const;

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

	friend class Iterator;
	class Iterator :
		public std::iterator<std::forward_iterator_tag, const long> {
	public:
		Iterator(const Big& big, long index, long digit);
		Iterator(const Iterator& rhs);
		~Iterator();

		Iterator& operator++();
		Iterator operator++(int);
		long operator*() const;

		bool operator==(const Iterator& rhs) const;
		bool operator!=(const Iterator& rhs) const;

	private:
		Iterator& operator=(const Iterator&);

		const Big& _big;
		long _index;
		long _digit;
	};

private:
	bool _negative;
	std::vector<long> _digits;
	static const long DIGIT_MAX;
};

} // namespace common
