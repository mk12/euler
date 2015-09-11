-- Copyright 2015 Mitchell Kember. Subject to the MIT License.
-- Project Euler: Problem 40
-- Champernowne's constant

module Problem40 where

import Common (digits, numDigits, takeDigits)

champDigit :: Int -> Int
champDigit = go 1
  where
    go n i
        | i <= d = takeDigits i n `mod` 10
        | otherwise = go (n + 1) (i - d)
      where
        d = numDigits n

solve :: Int
solve = product . map champDigit . takeWhile (<= 1000000) . iterate (* 10) $ 1
