-- Copyright 2015 Mitchell Kember. Subject to the MIT License.
-- Project Euler: Problem 29
-- Distinct powers

module Problem29 where

import Data.List (nub)

solve :: Int
solve = length . nub $ [a ^ b | a <- range, b <- range] where range = [2..100]
