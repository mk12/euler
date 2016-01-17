// Copyright 2016 Mitchell Kember. Subject to the MIT License.

#include <chrono>
#include <cstdio>
#include <cstdlib>
#include <cstring>

const int n_solved = 4;
const int answers[n_solved] = {
	233168, 4613732, 6857, 906609
};

typedef int (*Solver)();

namespace problem_01 { int solve(); }
namespace problem_02 { int solve(); }
namespace problem_03 { int solve(); }
namespace problem_04 { int solve(); }

const Solver solvers[n_solved] = {
	problem_01::solve,
	problem_02::solve,
	problem_03::solve,
	problem_04::solve
};

bool has_solution(int n) {
	return n >= 1 && n <= n_solved;
}

void print_usage(bool error) {
	static const char *usage = "usage: test [ -h | problem_number]\n";
	if (error) {
		fputs(usage, stderr);
	} else {
		fputs(usage, stdout);
	}
}

void print_error(const char *context, const char *msg) {
	fprintf(stderr, "error: %s: %s\n", context, msg);
}

const char* status_str(bool success) {
	return success ? "ok" : "FAIL";
}

bool test(int n) {
	int index = n - 1;
	auto start_t = std::chrono::high_resolution_clock::now();
	int result = solvers[index]();
	auto end_t = std::chrono::high_resolution_clock::now();
	double elapsed_s = std::chrono::duration<double>(end_t - start_t).count();
	bool success = result == answers[index];
	const char* msg = status_str(success);
	printf("%02d: %12d ... %4s (%g s)\n", n, result, msg, elapsed_s);
	return success;
}

bool test_all() {
	int passes = 0;
	for (int i = 1; i <= n_solved; ++i) {
		bool success = test(i);
		passes += success ? 1 : 0;
	}
	int fails = n_solved - passes;
	bool success = fails == 0;
	const char* msg = status_str(success);
	printf("%s. %d passed; %d failed\n", msg, passes, fails);
	return success;
}

int main(int argc, char **argv) {
	switch (argc) {
	case 1:
		return test_all() ? 0 : 1;
	case 2: {
		if (strcmp(argv[1], "-h") == 0) {
			print_usage(false);
			return 0;
		}
		char *temp;
		int n = static_cast<int>(strtol(argv[1], &temp, 10));
		if (temp == argv[1] || *temp != '\0') {
			print_error(argv[1], "not an integer");
			return 1;
		}
		if (!has_solution(n)) {
			print_error(argv[1], "out of bounds");
			return 1;
		}
		return test(n) ? 0 : 1;
	}
	default:
		print_usage(true);
		return 1;
	}
}
