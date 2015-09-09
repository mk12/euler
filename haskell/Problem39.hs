-- Copyright 2015 Mitchell Kember. Subject to the MIT License.
-- Project Euler: Problem 39
-- Integer right triangles

module Problem39 where

import Common (isPythagorean, maximumOn)

import Control.Monad (guard)

numSolutions :: Int -> Int
numSolutions p = length $ do
    a <- [1 .. p `div` 3 - 1]
    b <- [a + 1 .. (p - a) `div` 2 - 1]
    let c = p - a - b
    guard $ isPythagorean (a, b, c)

solve :: Int
solve = maximumOn numSolutions [1..1000]
