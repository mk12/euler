// Copyright 2016 Mitchell Kember. Subject to the MIT License.
// Project Euler: Problem 43
// Sub-string divisibility

#include <array>

namespace problem_43 {

long solve() {
	typedef std::array<bool, 10>::size_type sz_t;

	long total = 0;
	std::array<bool, 10> digits = {};
	for (sz_t n = 17 * 6; n <= 978; n += 17) {
		digits.fill(false);

		// Make sure there are no duplicates in the first 3 digits.
		const sz_t n1 = n % 10;
		const sz_t n2 = (n / 10) % 10;
		const sz_t n3 = (n / 100) % 10;
		if (n1 == n2 || n2 == n3 || n1 == n3) {
			continue;
		}
		digits[n1] = true;
		digits[n2] = true;
		digits[n3] = true;

		// Choose the other 7 digits.
		for (sz_t d1 = 0; d1 <= 9; ++d1) {
			if (digits[d1]) {
				continue;
			}
			const sz_t m1 = d1 * 100 + n / 10;
			if (m1 % 13 != 0) {
				continue;
			}
			digits[d1] = true;
			for (sz_t d2 = 0; d2 <= 9; ++d2) {
				if (digits[d2]) {
					continue;
				}
				const sz_t m2 = d2 * 100 + m1 / 10;
				if (m2 % 11 != 0) {
					continue;
				}
				digits[d2] = true;
				for (sz_t d3 = 0; d3 <= 9; ++d3) {
					if (digits[d3]) {
						continue;
					}
					const sz_t m3 = d3 * 100 + m2 / 10;
					if (m3 % 7 != 0) {
						continue;
					}
					digits[d3] = true;
					for (sz_t d4 = 0; d4 <= 9; ++d4) {
						if (digits[d4]) {
							continue;
						}
						const sz_t m4 = d4 * 100 + m3 / 10;
						if (m4 % 5 != 0) {
							continue;
						}
						digits[d4] = true;
						for (sz_t d5 = 0; d5 <= 9; ++d5) {
							if (digits[d5]) {
								continue;
							}
							const sz_t m5 = d5 * 100 + m4 / 10;
							if (m5 % 3 != 0) {
								continue;
							}
							digits[d5] = true;
							for (sz_t d6 = 0; d6 <= 9; ++d6) {
								if (digits[d6]) {
									continue;
								}
								const sz_t m6 = d6 * 100 + m5 / 10;
								if (m6 % 2 != 0) {
									continue;
								}
								digits[d6] = true;
								for (sz_t d7 = 1; d7 <= 9; ++d7) {
									if (digits[d7]) {
										continue;
									}
									total += static_cast<long>(
										d7 * 1000000000 +
										m6 * 1000000 +
										m3 * 1000 +
										n);
									break;
								}
								digits[d6] = false;
							}
							digits[d5] = false;
						}
						digits[d4] = false;
					}
					digits[d3] = false;
				}
				digits[d2] = false;
			}
			digits[d1] = false;
		}
	}
	return total;
}

} // namespace problem_43
