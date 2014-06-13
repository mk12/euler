# Copyright 2014 Mitchell Kember. Subject to the MIT License.
# Project Euler: Problem 17
# Number letter count

module problem_17

function solve()
	const and = 3
	const hundred = 7
	const onethousand = 3 + 8
	const a = 0+3+3+5+4+4+3+5+5+4 # 0:9
	const b = 3+6+6+8+8+7+7+9+8+8 # 10:19
	const c = 6+6+5+5+5+7+6+6     # 20:10:90
	const s99 = 10c + 9a + b
	10s99 + (100a + (9*100)hundred) + (9*99)and + onethousand
end

end # module
