// Copyright 2016 Mitchell Kember. Subject to the MIT License.
// Project Euler: Problem 15
// Lattice paths

#include "common.hpp"

namespace problem_15 {

long lattice_paths(const long w, const long h) {
	return common::combinations(w + h, w);
}

long solve() {
	return lattice_paths(20, 20);
}

} // namespace problem_15
