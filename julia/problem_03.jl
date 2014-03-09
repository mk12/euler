# Copyright 2014 Mitchell Kember. Subject to the MIT License.
# Project Euler: Problem 3
# Largest prime factor

module problem_03

function main()
	n = 600851475143
	factor = 1
	while n != 1
		factor += 2
		while n % factor == 0
			n = div(n, factor)
		end
	end
	factor
end

end # module
