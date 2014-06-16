// Copyright 2014 Mitchell Kember. Subject to the MIT License.

extern crate time;

use std::io::stdio;
use std::iter::range_inclusive;
use time::precise_time_ns;

mod problem_01; mod problem_02; mod problem_03; mod problem_04; mod problem_05;
mod problem_06; mod problem_07; mod problem_08; mod problem_09; mod problem_10;
mod problem_11; mod problem_12; mod problem_13; mod problem_14; mod problem_15;
mod problem_16; mod problem_17; mod problem_18; mod problem_19; mod problem_20;

static n_solved: uint = 20;
static answers: [int, ..n_solved] = [
	233168, 4613732, 6857, 906609, 232792560, 25164150, 104743, 23514624000,
	31875000, 142913828922, 70600674, 76576500, 5537376230, 837799, 137846528820,
	1366, 21124, 1074, 171, 648
];

static solvers: [fn() -> int, ..n_solved] = [
	problem_01::solve, problem_02::solve, problem_03::solve, problem_04::solve, 
	problem_05::solve, problem_06::solve, problem_07::solve, problem_08::solve, 
	problem_09::solve, problem_10::solve, problem_11::solve, problem_12::solve, 
	problem_13::solve, problem_14::solve, problem_15::solve, problem_16::solve,
	problem_17::solve, problem_18::solve, problem_19::solve, problem_20::solve
];

// Returns true if there is a solution to the nth problem.
fn has_solution(n: uint) -> bool {
	n >= 1 && n <= n_solved
}

// Indicates the that the program has failed by setting the exit status to 1.
fn failure() {
	std::os::set_exit_status(1);
}

// Prints the usage message to stdout, or to stderr if err is true.
fn print_usage(err: bool) {
	let mut stream = if err { stdio::stderr() } else { stdio::stdout() };
	let _ = stream.write_str("usage: test [ -h | problem_number]\n");
	if err { failure(); }
}

// Prints an error message to stderr with context.
fn print_error(context: &str, msg: &str) {
	let _ = write!(stdio::stderr(), "error: {}: {}\n", context, msg);
	failure();
}

// Returns a string to indicate the given success status.
fn status_str(success: bool) -> &'static str {
	if success { "ok" } else { "FAIL" }
}

// Tests the solution to the nth Euler problem. Prints the number n, the result
// the program produces, the success status, and the time elapsed. Returns true
// if the answer was correct.
fn test(n: uint) -> bool {
	let idx = n - 1;
	let start_ns = precise_time_ns();
	let result = (solvers[idx])();
	let end_ns = precise_time_ns();
	let elapsed_s = (end_ns - start_ns) as f64 / 1e9;
	let success = result == answers[idx];
	let msg = status_str(success);
	println!("{:02}: {:12} ... {:4} ({:.6e} s)", n, result, msg, elapsed_s);
	success
}

// Tests the solutions to all the Euler problems. At the end, prints a summary
// of how many passed and how many failed.
fn test_all() {
	let passes = range_inclusive(1, n_solved).filter(|&i| test(i)).count();
	let fails = n_solved - passes;
	let success = fails == 0;
	let msg = status_str(success);
	println!("{}. {} passed; {} failed", msg, passes, fails);
	if !success { failure(); }
}

// Handles the case where a single command-line argument is supplied.
fn one_argument(arg: &str) {
	if arg == "-h" {
		print_usage(false);
	} else {
		match from_str(arg) {
			Some(n) if has_solution(n) => { test(n); }
			Some(_) => print_error(arg, "out of bounds"),
			None => print_error(arg, "not a uint")
		}
	}
}

fn main() {
	let args = ::std::os::args();
	match args.len() {
		1 => test_all(),
		2 => one_argument(args.get(1).as_slice()),
		_ => print_usage(true)
	}
}
