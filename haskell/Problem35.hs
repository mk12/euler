-- Copyright 2015 Mitchell Kember. Subject to the MIT License.
-- Project Euler: Problem 35
-- Circular primes

module Problem35 where

import Common (isPrime, primes, rotate, digits, undigits)

solve :: Int
solve = length . filter works . takeWhile (< 1000000) $ primes
  where
    works = all (isPrime . undigits) . rotations . reverse . digits
    rotations xs = map (flip rotate xs) [1 .. length xs - 1]
