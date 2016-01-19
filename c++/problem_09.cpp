// Copyright 2016 Mitchell Kember. Subject to the MIT License.
// Project Euler: Problem 9
// Special Pythagorean triplet

namespace problem_09 {

long solve() {
	long i = 0, j = 0, k = 0;
	for (i = 1; i < 333; ++i) {
		for (j = i + 1; j < (1000 - i)/2; ++j) {
			k = 1000 - i - j;
			if (i*i + j*j == k*k) {
				goto end;
			}
		}
	}
end:
	return i * j * k;
}

} // namespace problem_09
