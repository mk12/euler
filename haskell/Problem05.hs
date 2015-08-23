-- Copyright 2015 Mitchell Kember. Subject to the MIT License.
-- Project Euler: Problem 5
-- Smallest multiple

module Problem05 where

import Common (divides)

import Data.List (find)
import Data.Maybe (fromJust)

divisibleTo19 :: Int -> Bool
divisibleTo19 n = all (flip divides n) [11..19]

solve :: Int
solve = fromJust . find divisibleTo19 $ [20, 40..]
