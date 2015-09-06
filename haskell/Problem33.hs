-- Copyright 2015 Mitchell Kember. Subject to the MIT License.
-- Project Euler: Problem 33
-- Digit cancelling fractions

module Problem33 where

import Common (digits, undigits)

import Data.List (intersect, (\\))
import Data.Maybe (mapMaybe)
import Data.Ratio (Ratio, denominator, (%))

curious :: (Int, Int) -> Maybe (Ratio Int)
curious (a, b)
    | not trivial && not invalid && r == r' = Just r'
    | otherwise = Nothing
  where
    da = digits a
    db = digits b
    common = intersect da db
    trivial = null common || common == [0]
    a' = undigits $ da \\ common
    b' = undigits $ db \\ common
    invalid = a' == 0 || b' == 0
    r = a % b
    r' = a' % b'

solve :: Int
solve = denominator . product . mapMaybe curious $ pairs
  where
    pairs = [(a, b) | b <- [10..99], a <- [10..b-1]]
