-- Copyright 2015 Mitchell Kember. Subject to the MIT License.

module Main where

import Problem01
import Problem02
import Problem03
import Problem04
import Problem05
import Problem06
import Problem07
import Problem08
import Problem09
import Problem10
import Problem11
import Problem12
import Problem13
import Problem14
import Problem15
import Problem16
import Problem17
import Problem18
import Problem19
import Problem20
import Problem21
import Problem22
import Problem23
import Problem24
import Problem25
import Problem26
import Problem27
import Problem28
import Problem29
import Problem30
import Problem31

import Control.Monad (filterM)
import System.Environment (getArgs)
import System.Exit (die, exitFailure)
import System.CPUTime (getCPUTime)
import Text.Printf (printf)
import Text.Read (readMaybe)

answers :: [Int]
answers =
    [ 233168, 4613732, 6857, 906609, 232792560, 25164150, 104743, 23514624000
    , 31875000, 142913828922, 70600674, 76576500, 5537376230, 837799
    , 137846528820, 1366, 21124, 1074, 171, 648, 31626, 871198282, 4179871
    , 2783915460, 4782, 983, -59231, 669171001, 9183, 443839, 73682
    ]

results :: [Int]
results =
    [ Problem01.solve, Problem02.solve, Problem03.solve, Problem04.solve
    , Problem05.solve, Problem06.solve, Problem07.solve, Problem08.solve
    , Problem09.solve, Problem10.solve, Problem11.solve, Problem12.solve
    , Problem13.solve, Problem14.solve, Problem15.solve, Problem16.solve
    , Problem17.solve, Problem18.solve, Problem19.solve, Problem20.solve
    , Problem21.solve, Problem22.solve, Problem23.solve, Problem24.solve
    , Problem25.solve, Problem26.solve, Problem27.solve, Problem28.solve
    , Problem29.solve, Problem30.solve, Problem31.solve
    ]

usage :: String
usage = "usage: test [ -h | problem_number ]"

status :: Bool -> String
status True = "ok"
status False = "FAIL"

problemSolved :: Int -> Bool
problemSolved n = n >= 1 && n <= length results

time :: Int -> IO Double
time x = do
    start <- getCPUTime
    end <- seq x getCPUTime
    return $ fromIntegral (end - start) / 1.0e12

test :: Int -> IO Bool
test n = do
    delta <- time res
    printf "%02d: %12d ... %4s (%e s)\n" n res (status correct) delta
    return correct
  where
    index = n - 1
    res = results !! index
    ans = answers !! index
    correct = res == ans

testAll :: IO ()
testAll = do
    good <- filterM test [1..total]
    let passes = length good
        fails = total - passes
        success = fails == 0
        printer = if success then putStrLn else die
    printer $ printf "%s. %d passed; %d failed" (status success) passes fails
  where
    total = length results

dieContext :: String -> String -> IO ()
dieContext ctx msg = die $ printf "error: %s: %s" ctx msg

oneArgument :: String -> IO ()
oneArgument "-h" = putStrLn usage
oneArgument str = case readMaybe str of
    Just n | problemSolved n -> do
        correct <- test n
        if correct
            then return ()
            else exitFailure
    Just _ -> dieContext str "out of bounds"
    Nothing -> dieContext str "not an int"

main :: IO ()
main = do
    args <- getArgs
    case length args of
        0 -> testAll
        1 -> oneArgument $ head args
        _ -> die usage
