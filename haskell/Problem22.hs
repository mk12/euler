-- Copyright 2015 Mitchell Kember. Subject to the MIT License.
-- Project Euler: Problem 22
-- Names scores

module Problem22 where

import Data.Char (ord)
import Data.List (sort)
import System.IO.Unsafe (unsafePerformIO)

totalScore :: [String] -> Int
totalScore = sum . map mult . zip [1..] . map nameValue . sort
  where
    nameValue = sum . map charValue
    charValue c = ord c - ord 'A' + 1
    mult = uncurry (*)

solve :: Int
solve = totalScore names
  where
    names = read . brackets . unsafePerformIO . readFile $ filename
    filename = "../data/p022_names.txt"
    brackets s = "[" ++ s ++ "]"
