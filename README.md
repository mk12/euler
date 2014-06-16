# Project Euler

These are my solutions to the [Project Euler][1] problems, written in Rust, Julia, and Clojure.

[1]: http://projecteuler.net

## Compiling

### Rust

Compile [test.rs](rust/test.rs) to get the `test` binary.

### Julia

Julia is JIT-compiled, so you do not need to compile anything. Just invoke the test program with `julia test.jl args`. When testing solutions, [test.jl](julia/test.jl) will execute the `solve` function twice and timed the second time to avoid including JIT compilation time in the benchmark. Testing all the solutions will feel slower because of this, so make sure you pay attention to the numbers.

### Clojure

I use [lein-bin](https://github.com/Raynes/lein-bin) to produce the binary for the Clojure solutions. Just run `lein bin` in the  Clojure project folder, and then execute `target/test`. Or just run the `solve` functions in the REPL, if you prefer.

## Usage

Run the `test` binary with the `-h` option to see its usage message:

	$ ./test -h
	usage: test [ -h | problem_number]

Run it with no arguments to test all solutions.

	$ ./test
	01:       233168 ... ok   (4.270000e-7 s)
	02:      4613732 ... ok   (2.670000e-7 s)
	...
	(20 more test lines)
	...
	ok. 20 passed; 0 failed

Each line contains the problem number, the result the program produces, the success status, and the time the program took in seconds. The elapsed time is not meant to be an accurate benchmark (it executes the `solve` function only once), but it is useful for comparing the orders of magnitude of different implementations. At the end, the test program prints a summary of how many passed and how many failed.

Provide an integer argument to test a specific solution:

	$ ./test 1
	01:       233168 ... ok   (3.290000e-7 s)
	$ ./test 42000
	error: 42000: out of bounds
	$ ./test abc
	error: abc: not a uint

I've tried to make the testing programs consistent for all three languages, but there are a few minor variations.

## License

© 2014 Mitchell Kember

Euler is available under the MIT License; see [LICENSE](LICENSE.md) for details.
