;;; Copyright 2014 Mitchell Kember. Subject to the MIT License.
;;; Project Euler: Problem 6
;;; Sum square difference

(ns euler.problem-06
  (:require [euler.common :as c]))

(defn solve []
  (let [xs (c/rangei 1 100)]
    (- (c/square (apply + xs))
       (apply + (map c/square xs)))))
