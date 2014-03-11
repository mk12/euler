# Copyright 2014 Mitchell Kember. Subject to the MIT License.

const answers = [
	233168, 4613732, 6857, 906609, 232792560,
	25164150, 104743, 40824, 31875000, 142913828922,
	70600674, 76576500, 5537376230, 837799, 137846528820,
	1366, 21124, 1074, 171, 648
]

function getmain(n)
	name = "problem_" * dec(n, 2)
	require(name)
	eval(symbol(name)).main
end

function info(n, result)
	print(dec(n, 2), ": ", result, " ... ")
	if result == answers[n]
		println("ok")
	else
		println("FAILED")
	end
end

if length(ARGS) == 1
	n = int(ARGS[1])
	main = getmain(n)
	main() # don't time the jitting
	result = @time main()
	info(n, result)
else
	for i = 1:length(answers)
		main = getmain(i)
		info(i, main())
	end
end
