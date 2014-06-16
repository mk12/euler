;;; Copyright 2014 Mitchell Kember. Subject to the MIT License.
;;; Project Euler: Problem 6
;;; Sum square difference

(ns euler.problem-06)

(defn square [x] (* x x))

(defn solve []
  (let [xs (range 1 101)]
    (- (square (apply + xs))
       (apply + (map square xs)))))
