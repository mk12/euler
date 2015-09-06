-- Copyright 2015 Mitchell Kember. Subject to the MIT License.
-- Project Euler: Problem 4
-- Largest palindrome product

module Problem04 where

import Common (isPalindrome, digits)

solve :: Int
solve = maximum . filter (isPalindrome . digits) $ products
  where
    products = [x * y | x <- [100..999], y <- [x..999]]
