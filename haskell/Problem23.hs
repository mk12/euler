-- Copyright 2015 Mitchell Kember. Subject to the MIT License.
-- Project Euler: Problem 23
-- Non-abundant sums

module Problem23 where

import Common (memoize, properDivisors)

limit :: Int
limit = 28123

isAbundant :: Int -> Bool
isAbundant = memoize (1, limit) go where go n = sum (properDivisors n) > n

isAbundantSum :: Int -> Bool
isAbundantSum n = any works [1..half]
  where
    half = n `div` 2
    works m = isAbundant m && isAbundant (n - m)

solve :: Int
solve = sum . filter (not . isAbundantSum) $ [1..limit]
