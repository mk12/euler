// Copyright 2016 Mitchell Kember. Subject to the MIT License.
// Project Euler: Problem 17
// Number letter counts

namespace problem_17 {

long solve() {
	constexpr long and_word = 3;
	constexpr long hundred = 7;
	constexpr long one_thousand = 3 + 8;
	constexpr long a = 0+3+3+5+4+4+3+5+5+4; //  0,  1, ...,  9
	constexpr long b = 3+6+6+8+8+7+7+9+8+8; // 10, 11, ..., 19
	constexpr long c = 6+6+5+5+5+7+6+6;     // 20, 30, ..., 90
	constexpr long s99 = 10*c + 9*a + b;
	constexpr long result =
		10*s99 + (100*a + 9*100*hundred) + 9*99*and_word + one_thousand;
	return result;
}

} // namespace problem_17
