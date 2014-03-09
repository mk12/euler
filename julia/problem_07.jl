# Copyright 2014 Mitchell Kember. Subject to the MIT License.
# Project Euler: Problem 7
# 10001st prime

module problem_07

function isprime(n)
	if iseven(n) || n % 3 == 0
		return false
	end
	for i = 5:6:isqrt(n)
		if n % i == 0 || n % (i+2) == 0
			return false
		end
	end
	true
end

function main()
	n = 1
	count = 2
	while true
		for x in [4, 2]
			n += x
			if isprime(n)
				count += 1
				if count == 10001
					return n
				end
			end
		end
	end
end

end # module
