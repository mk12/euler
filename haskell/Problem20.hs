-- Copyright 2015 Mitchell Kember. Subject to the MIT License.
-- Project Euler: Problem 20
-- Factorial digit sum

module Problem20 where

import Common (factorial, digits)

solve :: Int
solve = sum . digits . factorial $ 100
