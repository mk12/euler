-- Copyright 2015 Mitchell Kember. Subject to the MIT License.
-- Project Euler: Problem 7
-- 10001st prime

module Problem07 where

import Common (primes)

solve :: Int
solve = primes !! 10000
