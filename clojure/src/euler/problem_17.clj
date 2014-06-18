;;; Copyright 2014 Mitchell Kember. Subject to the MIT License.
;;; Project Euler: Problem 17
;;; Number letter count

(ns euler.problem-17
  (:require [euler.common :as c]))

(def words
  {:and "and"
   :hundred "hundred"
   :one-thousand "one thousand"
   :ones "one two three four five six seven eight nine"
   :teens (str "ten eleven twelve thirteen fourteen fifteen"
               "sixteen seventeen eighteen nineteen")
   :tens "twenty thirty forty fifty sixty seventy eighty ninety"})

(defn n-chars
  "Returns the number of characters in the string, not including spaces."
  [s]
  (count (remove #{\space} s)))

(defn solve []
  (let [ls (c/map-values n-chars words)
        first-99 (+ (* 10 (:tens ls))
                    (* 9 (:ones ls))
                    (:teens ls))]
    (+ (* 10 first-99)
       (* 100 (:ones ls))
       (* 9 100 (:hundred ls))
       (* 9 99 (:and ls))
       (:one-thousand ls))))
