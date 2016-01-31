// Copyright 2016 Mitchell Kember. Subject to the MIT License.

#include "common.hpp"

#include <vector>

#include <cassert>
#include <cmath>
#include <cstdio>

namespace common {

long min(const long a, const long b) {
	return a < b ? a : b;
}

long max(const long a, const long b) {
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

bool is_prime(const long n) {
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

bool is_prime_fast(const long n) {
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

long nth_prime(const long n) {
	assert(n >= 4);

	long p = 5;
	long count = 3;
	for (;;) {
		p += 2;
		if (is_prime_fast(p)) {
			++count;
			if (count == n) {
				break;
			}
		}
		p += 4;
		if (is_prime_fast(p)) {
			++count;
			if (count == 10001) {
				break;
			}
		}
	}
	return p;
}

long sum_primes_below(const long n) {
	long p = 5;
	long sum = 2 + 3 + 5;

	for (;;) {
		p += 2;
		if (p >= n) {
			break;
		}
		if (is_prime_fast(p)) {
			sum += p;
		}

		p += 4;
		if (p >= n) {
			break;
		}
		if (is_prime_fast(p)) {
			sum += p;
		}
	}
	return sum;
}

long n_divisors(const long n) {
	assert(n >= 1);

	if (n == 1) {
		return 1;
	}
	long max = static_cast<long>(sqrt(n));
	long count = 2;
	long div = 2;
	while (div <= max) {
		if (n % div == 0) {
			count += 2;
		}
		++div;
	}
	if (max * max == n) {
		--count;
	}
	return count;
}

long largest_prime_divisor(long n) {
	assert(n >= 3);

	long div = 1;
	while (n != 1) {
		div += 2;
		while (n % div == 0) {
			n /= div;
		}
	}
	return div;
}


long sum_proper_divisors(const long n) {
	assert(n >= 1);

	if (n == 1) {
		return 0;
	}
	long max = static_cast<long>(sqrt(n));
	long sum = 1;
	long div = 2;
	while (div <= max) {
		if (n % div == 0) {
			sum += div;
			sum += n / div;
		}
		++div;
	}
	if (max * max == n) {
		sum -= max;
	}
	return sum;
}


long combinations(const long n, const long k) {
	const long m = min(k, n - k);
	long result = 1;
	for (long i = 0; i < m; ++i) {
		result *= n - i;
		result /= i + 1;
	}
	return result;
}

long sum_of_digits(const mpz_class& n) {
	std::string str = n.get_str();
	long sum = 0;
	for (const char c : str) {
		sum += c - '0';
	}
	return sum;
}

std::vector<std::string> parse_words(const std::string& filename) {
	const std::string path = "../data/" + filename;
	std::ifstream fs(path);
	std::string token;
	std::vector<std::string> words;
	while (std::getline(fs, token, ',')) {
		words.push_back(token.substr(1, token.length() - 2));
	}
	return words;
}

} // namespace common
