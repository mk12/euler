# Copyright 2014 Mitchell Kember. Subject to the MIT License.
# Project Euler: Problem 6
# Sum square difference

module problem_06

function solve()
	sum, sqsum = 0, 0
	for n = 1:100
		sum += n
		sqsum += n^2
	end
	sum^2 - sqsum
end

end # module
