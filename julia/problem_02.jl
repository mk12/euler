# Copyright 2014 Mitchell Kember. Subject to the MIT License.
# Project Euler: Problem 2
# Even Fibonacci numbers

module problem_02

function solve()
	a, b = 0, 1
	total = 0
	while a < 4_000_000
		total += a
		a, b = b, a + b
		a, b = b, a + b
		a, b = b, a + b
	end
	total
end

end # module
