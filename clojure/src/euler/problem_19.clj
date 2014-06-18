;;; Copyright 2014 Mitchell Kember. Subject to the MIT License.
;;; Project Euler: Problem 19
;;; Counting Sundays

(ns euler.problem-19
  (:require [euler.common :as c]))

(def month-lens [31 28 31 30 31 30 31 31 30 31 30 31]) 
(def feb-leap 29)

(defn leap?
  "Returns true if y is a leap year, false otherwise."
  [y]
  (or (c/divisible? y 400)
      (and (c/indivisible? y 100)
           (c/divisible? y 4))))

(defn n-days
  "Returns the number of days in the month m of the year y."
  [y m]
  (if (and (== m 1) (leap? y))
    feb-leap
    (month-lens m)))

(defn solve []
  (->> (for [y (c/rangei 1901 2000)
             m (range (count month-lens))]
         (n-days y m))
       (reductions + 2)
       (filter #(c/divisible? % 7))
       count))
