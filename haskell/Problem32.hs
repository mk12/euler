-- Copyright 2015 Mitchell Kember. Subject to the MIT License.
-- Project Euler: Problem 32
-- Pandigital products

module Problem32 where

import Common (digits)

import Control.Monad (guard)
import Data.List (nub, sort)

pandigital :: [Int] -> Bool
pandigital = (== [1..9]) . sort

solve :: Int
solve = sum . nub $ do
    a <- [1..9876543]
    b <- [1..(ceiling (31622.776601683792 / fromIntegral a))]
    let c = a * b
    guard $ c < 9876543
    guard $ pandigital $ concatMap digits [a, b, c]
    return c
