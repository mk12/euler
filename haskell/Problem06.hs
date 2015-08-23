-- Copyright 2015 Mitchell Kember. Subject to the MIT License.
-- Project Euler: Problem 6
-- Sum square difference

module Problem06 where

import Common (square)

solve :: Int
solve = square (sum xs) - sum (map square xs) where xs = [1..100]
