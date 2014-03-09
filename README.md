# Project Euler

These are my solutions to the [Project Euler][1] problems, written in Rust and Julia.

[1]: http://projecteuler.net

## Usage

### Rust solutions

Compile an individual solution (ideally with `prefer-dynamic` and optimizations enabled), and then execute the resulting binary.

### Julia solutions

Use `julia test.jl` to check all the solutions, or run `julia test.jl N` to time the Nth solution (this will run the program twice and time the second invocation so that jitting time isn't included). Alternatively, fire up the REPL and type `import problem_N`.

## License

© 2014 Mitchell Kember

Euler is available under the MIT License; see [LICENSE](LICENSE.md) for details.
