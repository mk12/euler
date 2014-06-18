;;; Copyright 2014 Mitchell Kember. Subject to the MIT License.
;;; Project Euler: Problem 16
;;; Power digit sum

(ns euler.problem-16
  (:require [clojure.math.numeric-tower :as m]
            [euler.common :as c]))

(defn solve []
  (apply + (c/digits (m/expt 2 1000))))
