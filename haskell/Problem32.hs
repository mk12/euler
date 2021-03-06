-- Copyright 2015 Mitchell Kember. Subject to the MIT License.
-- Project Euler: Problem 32
-- Pandigital products

module Problem32 where

import Common (pandigital)

import Control.Monad (guard)
import Data.List (nub, sort)

limit :: Int
limit = 9876

solve :: Int
solve = sum . nub $ do
    a <- [1..limit]
    let bLimit = ceiling $ 31622.77 / fromIntegral a
    b <- [1..bLimit]
    let c = a * b
    guard $ c <= limit
    guard $ pandigital [a, b, c]
    return c
