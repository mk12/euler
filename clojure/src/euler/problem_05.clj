;;; Copyright 2014 Mitchell Kember. Subject to the MIT License.
;;; Project Euler: Problem 5
;;; Smallest multiple

(ns euler.problem-05
  (:require [euler.common :as c]))

(defn divisible-19?
  "Returns true if n is divisible by all the numbers from 1 to 19."
  [n]
  (loop [d 11]
    (or (== d 20)
        (and (c/divisible? n d)
             (recur (inc d))))))

(defn solve []
  (->> (c/inf-range 20 20)
       (filter divisible-19?)
       first))
