-- Copyright 2015 Mitchell Kember. Subject to the MIT License.
-- Project Euler: Problem 30
-- Digit fifth poweres

module Problem30 where

import Common (digits)

solve :: Int
solve = sum . filter works $ [2..limit]
  where
    limit = 9^5 * 6
    works n = fifthSum n == n
    fifthSum = sum . map (^ 5) . digits
