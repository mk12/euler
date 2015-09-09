-- Copyright 2015 Mitchell Kember. Subject to the MIT License.

module Common
( square, divides, factorial, combinations, isPythagorean
, primes, isPrime
, fibonacci, triangulars, properDivisors, divisors
, digits, undigits, numDigits, takeDigits, pandigital
, rotate, interleave, isPalindrome, maximumOn
, memoize
) where

import Data.Array (array, (!))
import Data.List (delete, foldl', foldl1', sort)

-- Algebra

square :: Int -> Int
square x = x * x

divides :: Int -> Int -> Bool
divides a b = b `mod` a == 0

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
isPrime n
    | n == 2 || n == 3 = True
    | n <= 1 || even n || divides 3 n = False
    | otherwise = not . any (`divides` n) $ divisors
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

-- Digits

digits :: Integral a => a -> [Int]
digits 0 = []
digits n = fromIntegral r : digits q where (q, r) = divMod n 10

undigits :: [Int] -> Int
undigits = foldr addDigit 0 where addDigit d total = d + total * 10

numDigits :: Integral a => a -> Int
numDigits = length . takeWhile (/= 0) . iterate (`div` 10)

takeDigits :: Integral a => Int -> a -> Int
takeDigits n x = fromIntegral $ x `div` 10^(numDigits x - n)

pandigital :: [Int] -> Bool
pandigital = (== [1..9]) . sort . concatMap digits

-- Lists

rotate :: Int -> [a] -> [a]
rotate n xs = take (length xs) . drop n . cycle $ xs

interleave :: [a] -> [a] -> [a]
interleave [] ys = ys
interleave (x:xs) ys = x : interleave ys xs

isPalindrome :: Eq a => [a] -> Bool
isPalindrome xs = take h xs == take h (reverse xs) where h = length xs `div` 2

maximumOn :: (a -> Int) -> [a] -> a
maximumOn _ [] = error "Common.maximumOn: empty list"
maximumOn f (x:xs) = fst . foldl' go (x, f x) $ xs
  where
    go pair x
        | fx > snd pair = (x, fx)
        | otherwise = pair
      where
        fx = f x

-- Performance

memoize :: (Int, Int) -> (Int -> a) -> Int -> a
memoize bounds@(lo, hi) f = dispatch
  where
    memo = array bounds [(n, f n) | n <- [lo..hi]]
    dispatch n
        | n >= lo && n <= hi = memo ! n
        | otherwise = f n
