;;; Copyright 2014 Mitchell Kember. Subject to the MIT License.
;;; Project Euler: Problem 4
;;; Largest palindrome product

(ns euler.problem-04)

(defn palindrome?
  "Returns true if n is a palindrome, false otherwise."
  [n]
  {:pre [(pos? n)]}
  (let [digits (seq (str n))]
    (= digits (reverse digits))))

(defn solve []
  (apply
    max
    (for [a (range 100 1000)
          b (range a 1000)
          :let [c (* a b)]
          :when (palindrome? c)]
      c)))
