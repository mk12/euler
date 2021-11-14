NB. Copyright 2020 Mitchell Kember. Subject to the MIT License.
NB. Project Euler: Problem 12
NB. Highly divisible triangular number

d =: ([: */ 1 + _ q: ])"0
(] {~ (500 < d) i. 1:) +/\ >: i. 12400

NB. Get the prime exponents of a number.
NB.
NB.     _ q: ]
NB.
NB. Calculate the number of divisors: the product of incremented exponents.
NB.
NB.     */ 1 +
NB.
NB. Let (d) return the number of divisors a number has, with rank zero.
NB.
NB.     d =: ([: ...)"0
NB.
NB. Calculate the first 12400 triangular numbers by taking partial sums.
NB.
NB.     +/\ >: i. 12400
NB.
NB. Find the index of the number with more than 500 divisors.
NB.
NB.     (500 < d) i. 1:
NB.
NB. Get that number.
NB.
NB.     (] {~ ...)
NB.
