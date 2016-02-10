// Copyright 2016 Mitchell Kember. Subject to the MIT License.
// Project Euler: Problem 22
// Names scores

#include "common.hpp"

#include <algorithm>
#include <vector>

namespace problem_22 {

long solve() {
	common::word_file wf("p022_names.txt");
	std::vector<std::string> words = wf.read();
	std::sort(words.begin(), words.end());

	long total = 0;
	long index = 1;
	for (const std::string& w : words) {
		total += index * common::word_value(w);
		++index;
	}
	return total;
}

} // namespace problem_22
