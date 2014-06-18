;;; Copyright 2014 Mitchell Kember. Subject to the MIT License.
;;; Project Euler: Problem 14
;;; Largest Collatz sequence

(ns euler.problem-14
  (:require [euler.common :as c]))

(defn collatz-len
  "Returns the length of the Collatz sequence beginning with n."
  [n]
  (loop [n n, len 1]
    (if (== n 1)
      len
      (recur (if (even? n) (/ n 2) (inc (* 3 n)))
             (inc len)))))

(defn solve []
  (c/maximum-by collatz-len (range 2 1000000)))
