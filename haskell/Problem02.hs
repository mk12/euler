-- Copyright 2015 Mitchell Kember. Subject to the MIT License.
-- Project Euler: Problem 2
-- Even Fibonacci numbers

module Problem02 where

import Common (fibonacci)

solve :: Int
solve = sum . takeWhile (<= 4000000) . filter even $ fibonacci
