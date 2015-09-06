-- Copyright 2015 Mitchell Kember. Subject to the MIT License.
-- Project Euler: Problem 33
-- Digit cancelling fractions

module Problem33 where

import Common (digits, undigits)

import Data.List (intersect, (\\))
import Data.Ratio (denominator, (%))

isCurious :: (Int, Int) -> Bool
isCurious (a, b) = not trivial && not invalid && a % b == a' % b'
  where
    da = digits a
    db = digits b
    common = intersect da db
    trivial = null common || common == [0]
    da' = da \\ common
    db' = db \\ common
    invalid = null da' || null db' || db' == [0]
    a' = undigits da'
    b' = undigits db'

solve :: Int
solve = denominator . product . map ratio . filter isCurious $ pairs
  where
    pairs = [(a, b) | a <- range, b <- range, a < b]
    range = [10..99]
    ratio = uncurry (%)
