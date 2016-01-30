// Copyright 2016 Mitchell Kember. Subject to the MIT License.

#pragma once

#include <gmpxx.h>

#include <fstream>
#include <string>
#include <vector>

namespace common {

long max(long a, long b);
long n_digits(long n);
bool is_palindrome(long n);
bool is_prime(long n);
bool is_prime_fast(long n);
long n_divisors(long n);
long sum_proper_divisors(long n);
long combinations(long n, long k);

long sum_of_digits(const mpz_class& n);

std::vector<std::string> parse_words(const std::string& filename);

} // namespace common
