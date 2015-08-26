-- Copyright 2015 Mitchell Kember. Subject to the MIT License.
-- Project Euler: Problem 21
-- Amicable numbers

module Problem21 where

import Common (properDivisors)

import Data.Tuple (swap)

amicablePairs :: Int -> [(Int, Int)]
amicablePairs limit = filter amicable pairs
  where
    pairs = map withSum [1..limit]
    withSum n = (n, sum (properDivisors n))
    amicable p = uncurry (<) p && swap p `elem` pairs

solve :: Int
solve = sum . map add . amicablePairs $ 9999 where add = uncurry (+)
