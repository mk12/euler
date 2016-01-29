// Copyright 2016 Mitchell Kember. Subject to the MIT License.
// Project Euler: Problem 22
// Names scores

#include "common.hpp"

#include <algorithm>
#include <vector>

namespace problem_22 {

long solve() {
	std::vector<std::string> words = common::parse_words("p022_names.txt");
	std::sort(words.begin(), words.end());

	long total = 0;
	long index = 1;
	for (const std::string& w : words) {
		long sum = 0;
		for (const char c : w) {
			sum += c - 'A' + 1;
		}
		total += sum * index;
		++index;
	}
	return total;
}

} // namespace problem_22
