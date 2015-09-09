-- Copyright 2015 Mitchell Kember. Subject to the MIT License.
-- Project Euler: Problem 37
-- Truncatable primes

module Problem37 where

import Common (interleave, numDigits, isPrime, primes)

truncations :: Int -> [Int]
truncations n = interleave left right
  where
    left = order . map (n `mod`) . iterate (`div` 10) $ 10 ^ (numDigits n - 1)
    right = order . tail . iterate (`div` 10) $ n
    order = reverse . takeWhile (/= 0)

solve :: Int
solve = sum . take 11 . filter works . dropWhile (<= 10) $ primes
  where
    works = all isPrime . truncations
