;;; Copyright 2014 Mitchell Kember. Subject to the MIT License.
;;; Project Euler: Problem 5
;;; Smallest multiple

(ns euler.problem-05)

(defn divisible?
  "Returns true if n is divisible by all the numbers from 1 to 19."
  [n]
  (loop [d 11]
    (or (= d 20)
        (and (zero? (rem n d))
             (recur (inc d))))))

(defn solve []
  (loop [n 20]
    (if (divisible? n)
      n
      (recur (+ 20 n)))))
