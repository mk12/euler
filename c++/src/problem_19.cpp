// Copyright 2016 Mitchell Kember. Subject to the MIT License.
// Project Euler: Problem 19
// Counting Sundays

namespace problem_19 {

constexpr long n_months = 12;
constexpr long month_lens[n_months] = {
//  Jan Feb Mar Apr May Jun Jul Aug Sep Oct Nov Dec
	31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
};

bool days_in_month(long month, bool leap) {
	return leap && month == 1 ? 29 : month_lens[month];
}

bool is_leap_year(long year) {
	return year % 400 == 0 || (year % 100 != 0 && year % 4 == 0);
}

long solve() {
	// 1 January 1901 was a Tuesday, so we start at 2:
	// S M T W T F S
	// 0 1 2 3 4 5 6
	long day = 2;
	long count = 0;

	for (long year = 1901; year <= 2000; ++year) {
		bool leap = is_leap_year(year);
		for (long month = 0; month < n_months; ++month) {
			if (day % 7 == 0) {
				++count;
			}
			day += days_in_month(month, leap);
		}
	}
	return count;
}

} // namespace problem_19
