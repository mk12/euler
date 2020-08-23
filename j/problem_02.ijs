NB. Copyright 2020 Mitchell Kember. Subject to the MIT License.
NB. Project Euler: Problem 2
NB. Even Fibonacci numbers

a =: {:"1 +/\ @ |. ^: (i. 33) 0 1x
b =: a #~ a <: 4e6
+/ b #~ 0 = 2 | b

NB. Given (x y), reverse (y x) and make partial sums (y x+y).
NB.
NB.     +/\ @ |.
NB.
NB. Make a (33 2) table iterating the above function starting from (0 1), and
NB. use arbitrary precision integers (1x).
NB.
NB.     ^: (i. 33) 0 1x
NB.
NB. Let (a) be the second column, i.e. the first 33 Fibonacci numbers.
NB.
NB.     a =: {:1"
NB.
NB. Let (b) be the numbers in (a) that do not exceed four million.
NB.
NB.     b =: a #~ a <: 4e6
NB.
NB. Sum the even numbers from (b).
NB.
NB.     +/ b #~ 0 = 2 | b
NB.
