-- Copyright 2015 Mitchell Kember. Subject to the MIT License.
-- Project Euler: Problem 15
-- Lattice paths

module Problem15 where

import Common (combinations)

routes :: Int -> Int -> Int
routes w h = fromIntegral result
  where
    ww = toInteger w
    hh = toInteger h
    result = combinations ww (ww + hh)

solve :: Int
solve = routes 20 20
