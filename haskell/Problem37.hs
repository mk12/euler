-- Copyright 2015 Mitchell Kember. Subject to the MIT License.
-- Project Euler: Problem 37
-- Truncatable primes

module Problem37 where

import Common (numDigits, isPrime, primes, memoize)

solve :: Int
solve = sum . take 11 . filter works . dropWhile (<= 10) $ primes
  where
    ip = memoize (0,1000) isPrime
    works n = all ip (leftTruncs n) && all ip (rightTruncs n)
    rightTruncs = reverse . takeWhile (/= 0) . tail . iterate (`div` 10)
    leftTruncs n = reverse . takeWhile (/= 0) . map (n `mod`) . iterate (`div` 10) $ m
      where
        m = 10 ^ (numDigits n - 1)
