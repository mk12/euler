-- Copyright 2015 Mitchell Kember. Subject to the MIT License.
-- Project Euler: Problem 10
-- Summation of primes

module Problem10 where

import Common (primes)

solve :: Int
solve = sum . takeWhile (< 2000000) $ primes
