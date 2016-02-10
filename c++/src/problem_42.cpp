// Copyright 2016 Mitchell Kember. Subject to the MIT License.
// Project Euler: Problem 42
// Coded triangle numbers

#include "common.hpp"

namespace problem_42 {

long solve() {
	common::word_file wf("p042_words.txt");
	long count = 0;
	for (const std::string word : wf) {
		const long value = common::word_value(word);
		if (common::is_triangular(value)) {
			++count;
		}
	}
	return count;
}

} // namespace problem_42
