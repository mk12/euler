-- Copyright 2015 Mitchell Kember. Subject to the MIT License.
-- Project Euler: Problem 36
-- Double-base palindromes

module Problem36 where

import Common (isPalindrome, digits)

import Data.Bits (unsafeShiftL, unsafeShiftR, (.&.), (.|.))

isBinPalindrome :: Int -> Bool
isBinPalindrome n = odd n && binReverse n == n
  where
    binReverse = go 0
    go r 0 = r
    go r n = go r' n'
      where
        r' = (r `unsafeShiftL` 1) .|. (n .&. 1)
        n' = n `unsafeShiftR` 1

solve :: Int
solve = sum . filter works $ [1..999999]
  where
    works n = isBinPalindrome n && isPalindrome (digits n)
