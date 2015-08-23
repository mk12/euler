-- Copyright 2015 Mitchell Kember. Subject to the MIT License.
-- Project Euler: Problem 12
-- Highly divisible triangular number

module Problem12 where

import Common (divisors, triangulars)

import Data.List (find)
import Data.Maybe (fromJust)

solve :: Int
solve = fromJust . find ((> 500) . length . divisors) $ triangulars
