-- Copyright 2015 Mitchell Kember. Subject to the MIT License.
-- Project Euler: Problem 1
-- Multiples of 3 and 5

module Problem01 where

import Common (divides)

solve :: Int
solve = sum . filter divisibleBy3or5 $ [1..999]
  where
    divisibleBy3or5 x = divides 3 x || divides 5 x
