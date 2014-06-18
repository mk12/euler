;;; Copyright 2014 Mitchell Kember. Subject to the MIT License.
;;; Project Euler: Problem 15
;;; Lattice paths

(ns euler.problem-15
  (:require [euler.common :as c]))

(defn n-combinations
  "Calculates the number of ways of choosing k items from a collection of n
  items (order does not matter)."
  [n k]
  (/ (apply * (c/rangei (inc (- n k)) n))
     (apply * (c/rangei 1 k))))

(defn solve []
  (let [side 20N]
    (c/small-int (n-combinations (* 2 side) side))))
