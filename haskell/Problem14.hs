-- Copyright 2015 Mitchell Kember. Subject to the MIT License.
-- Project Euler: Problem 14
-- Longest Collatz sequence

module Problem14 where

import Common (memoize)

import Data.List (maximumBy)
import Data.Ord (comparing)

limit :: Int
limit = 999999

collatzLen :: Int -> Int
collatzLen = memoize (1, limit) $ go 1
  where
    go count 1 = count
    go count n = count + collatzLen next
      where
        next = if even n then n `div` 2 else 3 * n + 1

solve :: Int
solve = maximumBy (comparing collatzLen) [1..limit]
