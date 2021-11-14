NB. Copyright 2020 Mitchell Kember. Subject to the MIT License.
NB. Project Euler: Problem 9
NB. Special Pythagorean triplet

n =: >: i. 499
c =: 0 >. 1000 - +/~ n
sos =: (([: *: [) + ([: *: ]))"0
{: (, (sos/~ n) = *: c) # (, c * */~ n)

NB. Let (n) be the integers from 1 to 499. Since a < b < c, we have a < b < 500,
NB. otherwise with b = 500, a = 1 any choice of c brings the total above 1000.
NB.
NB.     n =: >: i. 499
NB.
NB. Calculate a (499 499) table of sums for all values of a and b.
NB.
NB.     +/~ n
NB.
NB. Let (c) be a table containing the values for c obtained by subtracting the
NB. previous table from 1000, and clamping negatives to zero (0 >.).
NB.
NB.     c =: 0 >. 1000 -
NB.
NB. Let (sos) return the sum of the squares of its arguments, with rank 0.
NB.
NB.     sos =: (([: *: [) + ([: *: ]))"0
NB.
NB. Calculate a table of products a * b * c.
NB.
NB.     c * */~ n
NB.
NB. Calculate a boolean table with 1 when a^2 + b^2 = c^2 (Pythagorean triplet).
NB.
NB.     (sos/~ n) = *: c
NB.
NB. Get the values of a * b * c where (a, b, c) is a Pythagorean triplet.
NB.
NB.     (, ...) # (, ...)
NB.
NB. Take the first such product.
NB.
NB.     {:
NB.
