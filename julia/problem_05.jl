# Copyright 2014 Mitchell Kember. Subject to the MIT License.
# Project Euler: Problem 5
# Smallest multiple

module problem_05

function divisible(n)
	for i = 11:19
		if n % i != 0
			return false
		end
	end
	true
end

function main()
	multiple = 20
	while !divisible(multiple)
		multiple += 20
	end
	multiple
end

end # module
