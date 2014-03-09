# Copyright 2014 Mitchell Kember. Subject to the MIT License.
# Project Euler: Problem 9
# Special Pythagorean triplet

module problem_09

function main()
	for a = 1:332, b=a+2:div(1000-a-1, 2)
		c = 1000 - a - b
		if a^2 + b^2 == c^2
			return a * b * c
		end
	end
end

end # module
