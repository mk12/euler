;;; Copyright 2014 Mitchell Kember. Subject to the MIT License.
;;; Project Euler: Problem 9
;;; Special Pythagorean triplet

(ns euler.problem-09)

(defn square [x] (* x x))

(defn pythagorean?
  "Returns true if the triplet satisfies a^2+b^2=c^2, false otherwise."
  [a b c]
  (= (+ (square a) (square b))
     (square c)))

(defn solve []
  (first
    (for [a (range 1 333)
          b (range (+ a 2) (/ (- 1000 a) 2))
          :let [c (- 1000 a b)]
          :when (pythagorean? a b c)]
      (* a b c))))
