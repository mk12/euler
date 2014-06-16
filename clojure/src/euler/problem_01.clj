;;; Copyright 2014 Mitchell Kember. Subject to the MIT License.
;;; Project Euler: Problem 1
;;; Multiples of 3 and 5

(ns euler.problem-01)

(defn arith-sum
  "Calculates the arithmetic series beginning at 1 and ending at 999 with a
  common difference of d."
  [d]
  (let [n (quot 999 d)]
    (quot (* d n (inc n)) 2)))

(defn solve []
  (let [[a b c] (map arith-sum [3 5 15])]
    (+ a b (- c))))
