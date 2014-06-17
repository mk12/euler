;;; Copyright 2014 Mitchell Kember. Subject to the MIT License.
;;; Project Euler: Problem 10
;;; Summation of primes

(ns euler.problem-10
  (:require [clojure.core.reducers :as r]
            [euler.problem-07 :refer [potential-primes prime?]]))

(defn solve []
  (->> (potential-primes)
       (r/filter prime?)
       (r/take-while #(< % 2000000))
       (r/fold +)
       (+ 2 3)))
