;;; Copyright 2014 Mitchell Kember. Subject to the MIT License.
;;; Project Euler: Problem 12
;;; Highly divisible triangular number

(ns euler.problem-12
  (:require [euler.common :as c]))

(defn n-divisors
  "Returns the number of divisors that n has. It will be off by one if n is a
  perfect square."
  [n]
  (->> (c/rangei 2 (c/isqrt n))
       (filter #(c/divisible? n %))
       count
       (* 2)))

(defn solve []
  (->> (c/triangulars)
       (filter #(> (n-divisors %) 500))
       first))
