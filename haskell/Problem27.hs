-- Copyright 2015 Mitchell Kember. Subject to the MIT License.
-- Project Euler: Problem 27
-- Quadratic primes

module Problem27 where

import Common (isPrime, maximumOn)

numQuadPrimes :: (Int, Int) -> Int
numQuadPrimes (a, b) = length . takeWhile works $ [0..]
  where
    works n = isPrime $ n^2 + a * n + b

solve :: Int
solve = mult . maximumOn numQuadPrimes $ pairs
  where
    pairs = [(a, b) | a <- range, b <- range]
    range = [-999..999]
    mult = uncurry (*)
