-- Copyright 2015 Mitchell Kember. Subject to the MIT License.
-- Project Euler: Problem 17
-- Number letter counts

module Problem17 where

letters :: Int -> Int
letters n
    | n >= 0 && n <= 19 = upTo19 n
    | n <= 99 = tens (n `div` 10) + letters (n `mod` 10)
    | n <= 999 && n `mod` 100 == 0 = letters (n `div` 100) + hundred
    | n <= 999 = letters (n `div` 100) + hundred + and + letters (n `mod` 100)
    | n == 1000 = letters 1 + thousand
    | otherwise = 0
  where
    upTo19 = ([0, 3, 3, 5, 4, 4, 3, 5, 5, 4, 3, 6, 6, 8, 8, 7, 7, 9, 8, 8] !!)
    tens = ([0, 3, 6, 6, 5, 5, 5, 7, 6, 6] !!)
    and = 3
    hundred = 7
    thousand = 8

solve :: Int
solve = sum . map letters $ [1..1000]
