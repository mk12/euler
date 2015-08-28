;;; Copyright 2014 Mitchell Kember. Subject to the MIT License.
;;; Project Euler: Problem 21
;;; Amicable numbers

(ns euler.problem-21
  (:require [euler.common :as c]))

(defn proper-divisor-sum
  "Returns the sum of the proper divisors of n."
  [n]
  nil)

(defn amicable-pairs
  ""
  []
  nil)

(defn solve []
  (->> (c/factorial 100N)
       c/digits
       (apply +)))
