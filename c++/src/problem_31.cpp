// Copyright 2016 Mitchell Kember. Subject to the MIT License.
// Project Euler: Problem 31
// Coin sums

namespace problem_31 {

constexpr long n_denoms = 8;
constexpr long denom_values[n_denoms] = {
	1, 2, 5, 10, 20, 50, 100, 200
};

long n_coin_sums(const long sum, const long index) {
	if (sum < 0 || index < 0) {
		return 0;
	}
	if (sum == 0) {
		return 1;
	}
	const long value = denom_values[index];
	const long with = n_coin_sums(sum - value, index);
	const long without = n_coin_sums(sum, index - 1);
	return with + without;
}

long solve() {
	return n_coin_sums(200, n_denoms);
}

} // namespace problem_31
