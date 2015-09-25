-- Copyright 2015 Mitchell Kember. Subject to the MIT License.
-- Project Euler: Problem 41
-- Pandigital prime

module Problem41 where

import Common (digits, isPrime)

import Data.List (sort)

solve :: Int
solve = maximum . filter works . takeWhile (<= 7654321) $ potentials
  where
    potentials = 7000001 : 7000003 : map (+ 6) potentials
    works n = sort (digits n) == [1..7] && isPrime n
