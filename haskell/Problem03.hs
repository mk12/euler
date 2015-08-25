-- Copyright 2015 Mitchell Kember. Subject to the MIT License.
-- Project Euler: Problem 3
-- Largest prime factor

module Problem03 where

import Common (divides)

divideOut :: Int -> Int -> Int
divideOut x = until (not . divides x) (`div` x)

largestPrimeFactor :: Int -> Int
largestPrimeFactor n = go n 1
  where
    go 1 x = x
    go n x = go (divideOut y n) y where y = x + 2

solve :: Int
solve = largestPrimeFactor 600851475143
