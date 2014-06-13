# Copyright 2014 Mitchell Kember. Subject to the MIT License.
# Project Euler: Problem 14
# Longest Collatz sequence

module problem_14

function collatzlen(n)
	len = 1
	while n != 1
		d, r = divrem(n, 2)
		n = (r == 0) ? d : 3n + 1
		len += 1
	end
	len
end

function solve()
	best, bestlen = 1, 1
	for i = 2:1_000_000
		len = collatzlen(i)
		if len > bestlen
			best = i
			bestlen = len
		end
	end
	best
end

end # module
