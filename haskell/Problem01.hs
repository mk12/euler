-- Copyright 2015 Mitchell Kember. Subject to the MIT License.
-- Project Euler: Problem 1
-- Multiples of 3 and 5

module Problem01 where

import Common (divides)

solve :: Int
solve = sum . takeWhile (< 1000) . filter divisible3or5 $ [1..]
  where divisible3or5 x = divides 3 x || divides 5 x
