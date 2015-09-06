-- Copyright 2015 Mitchell Kember. Subject to the MIT License.
-- Project Euler: Problem 24
-- Lexicographic permutations

module Problem24 where

import Common (undigits)

import Data.List (delete)

lexPermutations :: [Int] -> [[Int]]
lexPermutations [] = [[]]
lexPermutations xs = concatMap go xs
  where
    go x = map (x :) . lexPermutations . delete x $ xs

solve :: Int
solve = undigits . reverse $ lexPermutations [0..9] !! 999999
