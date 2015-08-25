-- Copyright 2015 Mitchell Kember. Subject to the MIT License.

module Common
( square, divides, factorial, isPythagorean
, primes, isPrime
, fibonacci, triangulars, divisors
, digits
) where

import Data.List (delete)

-- Algebra

square :: Int -> Int
square x = x * x

divides :: Int -> Int -> Bool
divides a b = b `rem` a == 0

factorial :: Int -> Int
factorial n = product [1..n]

isPythagorean :: (Int, Int, Int) -> Bool
isPythagorean (a, b, c) = square a + square b == square c

-- Primes

primes :: [Int]
primes = 2 : 3 : filter isPrime potentialPrimes

isPrime :: Int -> Bool
isPrime n | n <= 1 = False
isPrime n | even n = False
isPrime n | divides 3 n = False
isPrime n = not . any (flip divides n) $ divisors
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

divisors :: Int -> [Int]
divisors n = 1 : n : othersUniq
  where
    limit = truncate . sqrt . fromIntegral $ n
    lower = filter (flip divides n) [2..limit]
    higher = map (div n) lower
    others = lower ++ higher
    othersUniq = if square limit == n then delete limit others else others

-- Other

digits :: Int -> [Int]
digits = map (`mod` 10) . takeWhile (> 0) . iterate (`div` 10)
