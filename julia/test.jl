# Copyright 2014 Mitchell Kember. Subject to the MIT License.

const answers = [
	233168, 4613732, 6857, 906609, 232792560, 25164150, 104743, 23514624000,
	31875000, 142913828922, 70600674, 76576500, 5537376230, 837799,
	137846528820, 1366, 21124, 1074, 171, 648
]

const usage = "usage: test [ -h | problem_number ]"

# Prints msg to stderr and exits with exit status 1 to indicate failure.
function fail(msg)
	write(STDERR, msg, '\n')
	exit(1)
end

# Creates a contextualized error message in a consistent format.
function context_err(context, msg)
	"error: " * context * ": " * msg
end

failc(c, m) = fail(context_err(c, m))

# Returns a string to indicate the given success status.
message(success) = success? "ok" : "FAIL"

# Returns the solve function for the nth problem. The returned function takes no
# arguments and returns an integer.
function getsolve(n)
	name = "problem_" * dec(n, 2)
	require(name)
	eval(symbol(name)).solve
end

# Tests the solution to the nth Euler problem. Prints the number n, the result
# the program produces, the success status, and time time elapsed. Returns true
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
# how many passed and how many failed. Exits with the appropriate exit status.
function testall()
	passes = count(test, 1:length(answers))
	fails = length(answers) - passes
	success = fails == 0
	msg = message(success)
	println("$msg. $passes passed; $fails failed")
	exit(success? 0 : 1)
end

# Handles the case where a single command-line argument is supplied.
function one_argument(arg)
	if arg == "-h"
		println(usage)
	else
		try
			n = int(arg)
			if 1 <= n <= length(answers)
				test(int(ARGS[1]))
			else
				failc(arg, "out of bounds")
			end
		catch
			failc(arg, "not an int")
		end
	end
end

function main()
	if length(ARGS) == 0
		testall()
	elseif length(ARGS) == 1
		one_argument(ARGS[1])
	else
		fail(usage)
	end
end

main()
