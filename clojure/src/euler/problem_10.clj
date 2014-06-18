;;; Copyright 2014 Mitchell Kember. Subject to the MIT License.
;;; Project Euler: Problem 10
;;; Summation of primes

(ns euler.problem-10
  (:require [euler.common :as c]))

(defn solve []
  (->> (c/primes)
       (take-while #(< % 2000000))
       (apply +)))
