-- Copyright 2015 Mitchell Kember. Subject to the MIT License.
-- Project Euler: Problem 34
-- Digit factorials

module Problem34 where

import Common (digits, factorial, memoize)

solve :: Int
solve = sum . filter works $ [3..99999]
  where
    works n = fsum n == n
    fsum = sum . map (memoize (0, 9) factorial) . digits
