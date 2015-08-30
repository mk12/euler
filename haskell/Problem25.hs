-- Copyright 2015 Mitchell Kember. Subject to the MIT License.
-- Project Euler: Problem 25
-- 1000-digit Fibonacci number

module Problem25 where

solve :: Int
solve = go 1 1 1 1 10
  where
    go _ _ index 1000 _ = index
    go a b index count next
        | a' >= next = go a' b' index' (count + 1) (next * 10)
        | otherwise = go a' b' index' count next
      where
        a' = b
        b' = a + b
        index' = index + 1
