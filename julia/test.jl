# Copyright 2014 Mitchell Kember. Subject to the MIT License.

const answers = [
	233168, 4613732, 6857, 906609, 232792560,
	25164150, 104743, 40824, 31875000, 142913828922,
	70600674, 76576500, 5537376230, 837799, 137846528820,
	1366, 21124, 1074, 171, 648
]

# Returns the solve function for the nth problem. The returned function takes no
# arguments and returns an integer.
function getsolve(n)
	name = "problem_" * dec(n, 2)
	require(name)
	eval(symbol(name)).solve
end

# Prints the usage message to stdout, or to stderr is err is true.
function printusage(err)
	stream = err? STDERR : STDOUT
	write(stream, "usage: test [ -h | problem_number]\n")
end

# Prints an error message to stderr with context.
function printerror(context, msg)
	write(STDERR, "error: ", context, ": ", msg, "\n")
end

# Returns a string to indicate the given success status.
message(success) = success? "ok" : "FAIL"

# Tests the solution to the Euler nth problem. Prints the number n, the result
# the program produces, the sucess status, and time time elapsed. Returns true
# if the answer was correct.
function test(n)
	solve = getsolve(n)
	solve() # don't time the jitting
	(result, time, _) = @timed solve()
	success = result == answers[n]
	p_res = lpad(result, 12)
	time_e = @sprintf("%e", time)
	msg = rpad(message(success), 4)
	println(dec(n, 2), ": $p_res ... $msg ($time_e s)")
	success
end

# Tests the solutions to all the Euler problems. At the end, prints a summary of
# how many passed and how many failed.
function testall()
	passes = count(test, 1:length(answers))
	fails = length(answers) - passes
	msg = message(fails == 0)
	println("$msg. $passes passed; $fails failed")
end

# Handles the case where a single command-line argument is supplied.
function one_argument(arg)
	if arg == "-h"
		printusage(false)
	else
		try
			n = int(arg)
			if 1 <= n <= length(answers)
				test(int(ARGS[1]))
			else
				printerror(arg, "out of bounds")
			end
		catch
			printerror(arg, "not an int")
		end
	end
end

function main()
	if length(ARGS) == 0
		testall()
	elseif length(ARGS) == 1
		one_argument(ARGS[1])
	else
		printusage(true)
	end
end

main()
