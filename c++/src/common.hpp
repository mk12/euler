// Copyright 2016 Mitchell Kember. Subject to the MIT License.

#pragma once

#include <gmpxx.h>

#include <fstream>
#include <string>
#include <vector>

namespace common {

constexpr long n_powers_of_ten = 10;
constexpr long powers_of_ten[n_powers_of_ten] = {
	1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000
};


long min(long a, long b);
long max(long a, long b);
long gcd(long a, long b);
void reduce_fraction(long& num, long& den);
long n_digits(long n);
bool is_palindrome(long n);
bool is_palindrome_binary(long n);
bool is_prime(long n);
bool is_prime_fast(long n);
long nth_prime(long n);
long sum_primes_below(long n);
long n_divisors(long n);
long largest_prime_divisor(long n);
long sum_proper_divisors(long n);
long combinations(long n, long k);

long sum_of_digits(const mpz_class& n);

std::vector<std::string> parse_words(const std::string& filename);

} // namespace common
