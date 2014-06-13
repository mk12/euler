# Copyright 2014 Mitchell Kember. Subject to the MIT License.
# Project Euler: Problem 15
# Lattice paths

module problem_15

function combinations(n, k)
	div(reduce(*, n-k+1:n), factorial(k))
end

function solve()
	const side = big(20)
	combinations(2side, side)
end

end # module
