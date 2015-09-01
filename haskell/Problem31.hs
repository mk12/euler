-- Copyright 2015 Mitchell Kember. Subject to the MIT License.
-- Project Euler: Problem 31
-- Coin sums

module Problem31 where

changes :: [Int] -> Int -> Int
changes [] 0 = 1
changes [] _ = 0
changes denoms@(d:ds) x
    | x >= d = changes denoms (x - d) + changes ds x
    | otherwise = changes ds x

solve :: Int
solve = changes [1, 2, 5, 10, 20, 50, 100, 200] 200
