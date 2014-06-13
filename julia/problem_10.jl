# Copyright 2014 Mitchell Kember. Subject to the MIT License.
# Project Euler: Problem 10
# Summation of primes

module problem_10

import problem_07: isprime

function solve()
	const max = 2_000_000
	total = 2 + 3
	n = 1
	while true
		for x in [4, 2]
			n += x
			if n >= max
				return total
			end
			if isprime(n)
				total += n
			end
		end
	end
end

end # module
