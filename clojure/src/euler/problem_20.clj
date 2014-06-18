;;; Copyright 2014 Mitchell Kember. Subject to the MIT License.
;;; Project Euler: Problem 20
;;; Factorial digit sum

(ns euler.problem-20
  (:require [euler.common :as c]))

(defn solve []
  (->> (c/factorial 100N)
       c/digits
       (apply +)))
