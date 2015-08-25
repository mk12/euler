-- Copyright 2015 Mitchell Kember. Subject to the MIT License.

module Common
( square, divides, factorial, isPythagorean
, primes, isPrime
, fibonacci, triangulars, divisors
, digits
) where

import Data.List (delete)

-- Algebra

square :: Num a => a -> a
square x = x * x

divides :: Integral a => a -> a -> Bool
divides a b = b `rem` a == 0

factorial :: (Enum a, Num a) => a -> a
factorial n = product [1..n]

isPythagorean :: (Eq a, Num a) => (a, a, a) -> Bool
isPythagorean (a, b, c) = square a + square b == square c

-- Primes

primes :: Integral a => [a]
primes = 2 : 3 : filter isPrime potentialPrimes

isPrime :: Integral a => a -> Bool
isPrime n | n <= 1 = False
isPrime n | even n = False
isPrime n | divides 3 n = False
isPrime n = not . any (flip divides n) $ divisors
  where
    divisors = takeWhile (<= limit) potentialPrimes
    limit = truncate . sqrt . fromIntegral $ n

potentialPrimes :: Integral a => [a]
potentialPrimes = 5 : 7 : map (+ 6) potentialPrimes

-- Sequences

fibonacci :: Integral a => [a]
fibonacci = 0 : 1 : zipWith (+) fibonacci (tail fibonacci)

triangulars :: Integral a => [a]
triangulars = scanl1 (+) [1..]

divisors :: Integral a => a -> [a]
divisors n = 1 : n : othersUniq
  where
    limit = truncate . sqrt . fromIntegral $ n
    lower = filter (flip divides n) [2..limit]
    higher = map (div n) lower
    others = lower ++ higher
    othersUniq = if square limit == n then delete limit others else others

-- Other

digits :: Integral a => a -> [a]
digits = map (`mod` 10) . takeWhile (> 0) . iterate (`div` 10)
