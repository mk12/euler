# Project Euler

These are my solutions to the [Project Euler][1] problems, written in Haskell, Clojure, Julia, and Rust.

[1]: http://projecteuler.net

## Compiling

### Haskell

Compile with `ghc Test -O` and then run the `Test` binary.

### Clojure

I use [lein-bin](https://github.com/Raynes/lein-bin) to produce the binary for the Clojure solutions. Run `lein bin` in the  Clojure project folder, and then execute `target/test`. Or just run the `solve` functions in the REPL, if you prefer.

### Julia

Invoke the test program with `julia test.jl args`. When testing solutions, [test.jl](julia/test.jl) will execute the `solve` function twice and timed the second time to avoid including JIT compilation time in the benchmark. This will make testing feel slower, so make sure you pay attention to the numbers.

### Rust

Compile [test.rs](rust/test.rs) to get the `test` binary. Make sure to enable optimizations with `-O`. To keep the binaries small, enable dynamic linking with `-C prefer-dynamic`.

_(Note: the Rust solutions use outdated syntax and no longer compile with the latest compiler.)_

## Usage

Run the test program with the `-h` option to see its usage message:

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

I've tried to make the testing programs consistent for all three languages, but there are a few variations.

## License

© 2014 Mitchell Kember

Euler is available under the MIT License; see [LICENSE](LICENSE.md) for details.
