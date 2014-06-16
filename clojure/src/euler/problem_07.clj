;;; Copyright 2014 Mitchell Kember. Subject to the MIT License.
;;; Project Euler: Problem 7
;;; 10001st prime

(ns euler.problem-07
  (:import java.lang.Math))

(defn isqrt
  "Returns the integer square root of x."
  [x]
  (int (Math/sqrt x)))

(defn divisible?
  "Returns true if n is divisible by d, false otherwise."
  [n d]
  (zero? (rem n d)))

(defn prime?
  "Returns true if n is prime, false otherwise. Assumes n > 3."
  [n]
  {:pre [(> n 3)]}
  (not (or (even? n)
           (divisible? n 3)
           (some #(or (divisible? n %)
                      (divisible? n (+ 2 %)))
                 (range 5 (inc (isqrt n)) 6)))))

(defn potential-primes
  "Returns a lazy sequence of numbers that could potentially be prime, beginning
  at 5 and ommiting multiples of 2 and 3."
  ([] (potential-primes 5))
  ([n] (cons n
             (cons (+ n 2)
                   (lazy-seq (potential-primes (+ n 6)))))))

(defn solve []
  (nth (filter prime? (potential-primes))
       (dec (- 10001 2))))