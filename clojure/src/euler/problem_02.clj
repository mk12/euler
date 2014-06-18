;;; Copyright 2014 Mitchell Kember. Subject to the MIT License.
;;; Project Euler: Problem 2
;;; Even Fibonacci numbers

(ns euler.problem-02
  (:require [euler.common :as c]))

(defn solve []
  (->> (c/fibonacci)
       (take-while #(< % 4000000))
       (filter even?)
       (reduce +)))
