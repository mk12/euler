-- Copyright 2015 Mitchell Kember. Subject to the MIT License.
-- Project Euler: Problem 38
-- Pandigital multiples

module Problem38 where

import Common (catDigits, numDigits, pandigital)

import Data.Maybe (mapMaybe)

takeTotalDigits :: Int -> [Int] -> Maybe [Int]
takeTotalDigits 0 _ = Just []
takeTotalDigits _ [] = Nothing
takeTotalDigits n _ | n < 0 = Nothing
takeTotalDigits n (x:xs) = (x :) <$> takeTotalDigits (n - numDigits x) xs

solve :: Int
solve = maximum . map catDigits . filter pandigital . products $ [1..9876]
  where
    products = mapMaybe (takeTotalDigits 9 . multiples)
    multiples n = map (* n) [1..]
