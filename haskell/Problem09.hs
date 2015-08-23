-- Copyright 2015 Mitchell Kember. Subject to the MIT License.
-- Project Euler: Problem 9
-- Special Pythagorean triplet

module Problem09 where

import Common (isPythagorean)

import Data.List (find)
import Data.Maybe (fromJust)

solve :: Int
solve = mult . fromJust . find isPythagorean $ triplets
  where
    triplets = [(a, b, 1000-a-b) | a <- [1..332], b <- bSource a]
    bSource a = [a + 1 .. (1000 - a) `div` 2 - 1]
    mult (a, b, c) = a * b * c
