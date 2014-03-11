# Copyright 2014 Mitchell Kember. Subject to the MIT License.
# Project Euler: Problem 12
# Highly divisible triangular number

module problem_12

# off by one for perfect squares
function divisors(n)
	count = 2
	for i = 2:isqrt(n)
		if n % i == 0
			count += 2
		end
	end
	count
end

function main()
	tri, i = 1, 1
	while true
		if divisors(tri) > 500
			return tri
		end
		i += 1
		tri += i
	end
end

end # module
