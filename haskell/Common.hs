-- Copyright 2015 Mitchell Kember. Subject to the MIT License.

module Common
( square, divides, factorial, combinations, isPythagorean
, primes, isPrime
, fibonacci, triangulars, properDivisors, divisors
, digits
) where

import Data.List (delete)

-- Algebra

square :: Int -> Int
square x = x * x

divides :: Int -> Int -> Bool
divides a b = b `rem` a == 0

factorial :: Integral a => a -> a
factorial n = product [1..n]

combinations :: Integral a => a -> a -> a
combinations n k = product [k-n+1..k] `div` factorial n

isPythagorean :: (Int, Int, Int) -> Bool
isPythagorean (a, b, c) = square a + square b == square c

-- Primes

primes :: [Int]
primes = 2 : 3 : filter isPrime potentialPrimes

isPrime :: Int -> Bool
isPrime n | n <= 1 = False
isPrime n | even n = False
isPrime n | divides 3 n = False
isPrime n = not . any (`divides` n) $ divisors
  where
    divisors = takeWhile (<= limit) potentialPrimes
    limit = truncate . sqrt . fromIntegral $ n

potentialPrimes :: [Int]
potentialPrimes = 5 : 7 : map (+ 6) potentialPrimes

-- Sequences

fibonacci :: [Int]
fibonacci = 0 : 1 : zipWith (+) fibonacci (tail fibonacci)

triangulars :: [Int]
triangulars = scanl1 (+) [1..]

properDivisors :: Int -> [Int]
properDivisors 1 = []
properDivisors n = 1 : unique
  where
    limit = truncate . sqrt . fromIntegral $ n
    lower = filter (`divides` n) [2..limit]
    higher = map (div n) lower
    both = lower ++ higher
    unique = if square limit == n then delete limit both else both

divisors :: Int -> [Int]
divisors n = n : properDivisors n

-- Other

digits :: Integral a => a -> [Int]
digits = map (fromIntegral . flip rem 10) . takeWhile (> 0) . iterate (`div` 10)
