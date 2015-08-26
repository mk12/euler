-- Copyright 2015 Mitchell Kember. Subject to the MIT License.
-- Project Euler: Problem 19
-- Counting Sundays

module Problem19 where

import Common (divides)

isLeap :: Int -> Bool
isLeap y
    | divides 100 y = divides 400 y
    | otherwise = divides 4 y

daysInMonth :: (Int, Int) -> Int
daysInMonth (y, m)
    | isLeap y && m == 2 = 29
    | otherwise = monthLens !! (m - 1)
  where
    monthLens = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]

solve :: Int
solve = length . filter (divides 7) . scanl (+) 2 $ dayCounts
  where
    dayCounts = [daysInMonth (y, m) | y <- [1901..2000], m <- [1..12]]
