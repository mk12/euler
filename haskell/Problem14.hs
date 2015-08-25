-- Copyright 2015 Mitchell Kember. Subject to the MIT License.
-- Project Euler: Problem 14
-- Longest Collatz sequence

module Problem14 where

import Data.Array (array, (!))
import Data.List (maximumBy)
import Data.Ord (comparing)

collatzLen :: Int -> Int
collatzLen = (memo !)
  where
    limit = 1000000
    memo = array (1, limit) [(n, go n 1) | n <- [1..limit]]
    go 1 count = count
    go n count
        | next <= limit = count + collatzLen next
        | otherwise = go next (count + 1)
      where
        next = if even n then n `div` 2 else 3 * n + 1

solve :: Int
solve = maximumBy (comparing collatzLen) [1..999999]
