-- Copyright 2015 Mitchell Kember. Subject to the MIT License.
-- Project Euler: Problem 22
-- Names scores

module Problem22 where

import Common (loadList, wordValue)

import Data.List (sort)

solve :: Int
solve = sum . zipWith (*) [1..] . map wordValue . sort . loadList $ "p022_names"
