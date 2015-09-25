-- Copyright 2015 Mitchell Kember. Subject to the MIT License.
-- Project Euler: Problem 42
-- Coded triangle numbers

module Problem42 where

import Common (loadList, triangulars, wordValue)

isTriangle :: Int -> Bool
isTriangle n = elem n . takeWhile (<= n) $ triangulars

solve :: Int
solve = length . filter isTriangle . map wordValue . loadList $ "p042_words"
