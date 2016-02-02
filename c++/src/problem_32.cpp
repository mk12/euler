// Copyright 2016 Mitchell Kember. Subject to the MIT License.
// Project Euler: Problem 32
// Pandigital products

#include <array>
#include <vector>

namespace problem_32 {

bool is_pandigital(const long a, const long b, const long c) {
	typedef std::array<bool, 9>::size_type sz_t;

	// Record the occurrences of the digits 1 through 9.
	std::array<bool, 9> digits = {};
	std::array<long, 3> numbers = {{a, b, c}};
	for (long n : numbers) {
		while (n != 0) {
			const long d = n % 10;
			const sz_t index = static_cast<sz_t>(d - 1);
			if (d == 0 || digits[index]) {
				return false;
			}
			digits[index] = true;
			n /= 10;
		}
	}
	// Make sure each digit 1 through 9 occurred exactly once.
	for (const bool present : digits) {
		if (!present) {
			return false;
		}
	}
	return true;
}

long solve() {
	constexpr long max = 9876;
	std::vector<long> prods;
	for (long i = 1; i <= max; ++i) {
		const long max_j = max / i;
		for (long j = 1; j < max_j; ++j) {
			const long p = i * j;
			if (p <= max && is_pandigital(i, j, p)) {
				// Add the product if we haven't already seen it.
				if (std::find(prods.begin(), prods.end(), p) == prods.end()) {
					prods.push_back(p);
				}
			}
		}
	}

	long total = 0;
	for (const long n : prods) {
		total += n;
	}
	return total;
}

} // namespace problem_32
