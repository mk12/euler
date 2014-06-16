;;; Copyright 2014 Mitchell Kember. Subject to the MIT License.
;;; Project Euler: Problem 2
;;; Even Fibonacci numbers

(ns euler.problem-02)

(defn fibonacci
  "Returns a lazy sequence of Fibonacci numbers."
  [a b]
  (cons a (lazy-seq (fibonacci b (+ a b)))))

(defn solve []
  (->> (fibonacci 0 1)
       (take-while #(< % 4000000))
       (filter even?)
       (reduce +)))
