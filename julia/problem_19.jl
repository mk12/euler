# Copyright 2014 Mitchell Kember. Subject to the MIT License.
# Project Euler: Problem 19
# Counting Sundays

module problem_19

const monthlens = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]

function isleap(y)
	y % 400 == 0 || (y % 100 != 0 && y % 4 == 0)
end

function ndays(y, m)
	if m == 2 && isleap(y)
		return 29
	end
	monthlens[m]
end

function main()
	# 1 January 1901 was a Tuesday.
	# Given d % 7, weekday is 0:6 == Sun:Sat.
	d = 2
	count = 0
	for y = 1901:2000, m = 1:12
		if d % 7 == 0
			count += 1
		end
		d += ndays(y, m)
	end
	count
end

end # module
