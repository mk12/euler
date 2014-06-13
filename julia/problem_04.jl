# Copyright 2014 Mitchell Kember. Subject to the MIT License.
# Project Euler: Problem 4
# Largest palindrome product

module problem_04

function ispalindrome(n)
	str = string(n)
	for i = 1:div(length(str), 2)
		if str[i] != str[end+1-i]
			return false
		end
	end
	true
end

function solve()
	largest = 0
	for a = 100:999, b = 100:999
		c = a * b
		if c > largest && ispalindrome(c)
			largest = c
		end
	end
	largest
end

end # module
