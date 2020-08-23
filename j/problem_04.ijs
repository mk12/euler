NB. Copyright 2020 Mitchell Kember. Subject to the MIT License.
NB. Project Euler: Problem 4
NB. Largest palindrome product

palindrome =: (": -: [: |. ":)"0
>./ (palindrome # ]) ~. , */~ 100 + i. 900

NB. Make a multiplication table for the integers from 100 to 999.
NB.
NB.     */~ 100 + i. 900
NB.
NB. Convert to a flat list and remove duplicates.
NB.
NB.     ~. ,
NB.
NB. Select numbers that are palindromes.
NB.
NB.     (palindrome # ])
NB.
NB. A palindrome's string (":) is equal (-:) to its reversal (|. ":).
NB.
NB.     ": -: [: |. ":
NB.
NB. Take the largest palindrome.
NB.
NB.     >./
NB.
