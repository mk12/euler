-- Copyright 2015 Mitchell Kember. Subject to the MIT License.
-- Project Euler: Problem 26
-- Reciprocal cycles

module Problem26 where

import Common (maximumOn)

import Data.List (elemIndex)

cycleLen :: Int -> Int
cycleLen n = go 1 []
  where
    go 0 _ = 0
    go x seen = case elemIndex x seen of
        Just index -> index + 1
        Nothing -> go x' $ x:seen
      where
        x' = (x * 10) `rem` n

solve :: Int
solve = maximumOn cycleLen [1..999]
