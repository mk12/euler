;;; Copyright 2014 Mitchell Kember. Subject to the MIT License.
;;; Project Euler: Problem 7
;;; 10001st prime

(ns euler.problem-07
  (:require [euler.common :as c]))

(defn solve []
  (nth (c/primes) (dec 10001)))
