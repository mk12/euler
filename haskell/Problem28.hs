-- Copyright 2015 Mitchell Kember. Subject to the MIT License.
-- Project Euler: Problem 28
-- Number spiral diagonals

module Problem28 where

diagonals :: [Int]
diagonals = scanl (+) 1 . concatMap (replicate 4) $ [2, 4..]

diagonalSum :: Int -> Int
diagonalSum side = sum . take n $ diagonals where n = 1 + 2 * (side - 1)

solve :: Int
solve = diagonalSum 1001
