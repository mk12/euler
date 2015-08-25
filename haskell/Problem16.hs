-- Copyright 2015 Mitchell Kember. Subject to the MIT License.
-- Project Euler: Problem 16
-- Power digit sum

module Problem16 where

import Common (digits)

solve :: Int
solve = sum . digits $ 2 ^ 1000
