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

class big {
public:
	explicit big(long n);
	explicit big(const std::string& str);

	long truncate() const;
	bool negative() const;

	class iterator;
	class reverse_iterator;
	iterator begin() const;
	iterator end() const;
	reverse_iterator rbegin() const;
	reverse_iterator rend() const;

	big& operator+=(const big& rhs);
	big& operator+=(long rhs);
	big& operator-=(const big& rhs);
	big& operator-=(long rhs);
	big& operator*=(const big& rhs);
	big& operator*=(long rhs);
	big& operator/=(const big& rhs);
	big& operator/=(long rhs);

	friend big operator+(const big& lhs, const big& rhs);
	friend big operator+(const big& lhs, long rhs);
	friend big operator+(long lhs, const big& rhs);
	friend big operator-(const big& lhs, const big& rhs);
	friend big operator-(const big& lhs, long rhs);
	friend big operator-(long lhs, const big& rhs);
	friend big operator*(const big& lhs, const big& rhs);
	friend big operator*(const big& lhs, const big& rhs);
	friend big operator*(const big& lhs, long rhs);
	friend big operator/(long lhs, const big& rhs);
	friend big operator/(const big& lhs, long rhs);
	friend big operator/(long lhs, const big& rhs);

	friend class iterator;
	class iterator :
		public std::iterator<std::forward_iterator_tag, const long> {
	public:
		iterator(const big& n, long index, long digit);
		iterator(const iterator& rhs);
		~iterator();

		iterator& operator++();
		iterator operator++(int);
		long operator*() const;

		bool operator==(const iterator& rhs) const;
		bool operator!=(const iterator& rhs) const;

	private:
		iterator& operator=(const iterator&);

		const big& _big;
		long _index;
		long _digit;
	};

	friend class reverse_iterator;
	class reverse_iterator :
		public std::iterator<std::forward_iterator_tag, const long> {
	public:
		reverse_iterator(const big& n, long index, long digit);
		reverse_iterator(const reverse_iterator& rhs);
		~reverse_iterator();

		reverse_iterator& operator++();
		reverse_iterator operator++(int);
		long operator*() const;

		bool operator==(const reverse_iterator& rhs) const;
		bool operator!=(const reverse_iterator& rhs) const;

	private:
		reverse_iterator& operator=(const iterator&);

		static long initial_divisor(long digit);

		const big& _big;
		long _index;
		long _digit;
		long _divisor;
	};

private:
	bool _negative;
	std::vector<long> _digits;
	static const long DIGIT_MAX;
};

} // namespace common
