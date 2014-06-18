;;; Copyright 2014 Mitchell Kember. Subject to the MIT License.
;;; Project Euler: Problem 3
;;; Largest prime factor

(ns euler.problem-03)

(defn divide-out
  "Divides n by d until it can no longer divide."
  [n d]
  (->> (iterate #(/ % d) n)
       (take-while integer?)
       last))

(defn largest-prime-factor
  "Finds the largest prime factor of an odd integer n."
  [n]
  {:pre [(odd? n)]}
  (loop [n n, factor 1]
    (if (== n 1)
      factor
      (let [f+2 (+ factor 2)]
        (recur (divide-out n f+2) f+2)))))

(defn solve []
  (largest-prime-factor 600851475143))
