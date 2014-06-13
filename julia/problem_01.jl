# Copyright 2014 Mitchell Kember. Subject to the MIT License.
# Project Euler: Problem 1
# Multiples of 3 and 5

module problem_01

# arithmetic series with t[1] = 0 and t[n] <= 999
function asum(d)
	n = div(999, d)
	div(d * n * (n+1), 2)
end

function solve()
	asum(3) + asum(5) - asum(15)
end

end # module
