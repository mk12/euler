;;; Copyright 2014 Mitchell Kember. Subject to the MIT License.

(ns euler.common
  (:import java.lang.Math))

;;;;; General

(def small-int long)

(defn map-values
  "Applies f to all the values in the map m."
  [f m]
  (into {} (map (fn [[k v]] [k (f v)]) m)))

(defn rangei
  "Like range, but the end is inclusive."
  ([end] (range (inc end)))
  ([start end] (range start (inc end)))
  ([start end step] (range start (inc end) step)))

(defn inf-range
  "Returns an infinite lazy sequence beginning at start and increasing by step."
  [start step]
  (iterate (partial + step) start))

(defn maximum [coll] (apply max coll))

(defn maximum-by
  "Like max-key, but takes a collection instead of a variable number of
  arguments. This implementation is much more efficient."
  [f coll]
  (let [fst (first coll)]
    (loop [coll coll, most [fst (f fst)]]
      (if-not (seq coll)
        (most 0)
        (let [x (first coll)
              fx (f x)]
          (recur (rest coll)
                 (if (> fx (most 1))
                   [x fx]
                   most)))))))

;;;;; Arithmetic

(defn square [x] (* x x))

(defn isqrt
  "Returns the integer square root of the perfect square x."
  [x]
  (int (Math/sqrt x)))

(defn divisible?
  "Returns true if n is divisible by d, false otherwise."
  [n d]
  (zero? (rem n d)))

(def indivisible? (complement divisible?))

;;;;; Prime numbers

(defn prime?
  "Returns true if n is prime, false otherwise. Assumes n > 3."
  [n]
  {:pre [(> n 3)]}
  (and (odd? n)
       (indivisible? n 3)
       (let [root (isqrt n)]
         (loop [d 5]
           (or (> d root)
               (and (indivisible? n d)
                    (indivisible? n (+ d 2))
                    (recur (+ d 6))))))))

(defn potential-primes
  "Returns an infinite lazy sequence of numbers that could potentially be prime,
  beginning at 5 and ommiting multiples of 2 and 3."
  ([] (potential-primes 5))
  ([n] (cons n
             (cons (+ n 2)
                   (lazy-seq (potential-primes (+ n 6)))))))

;;;;; Sequences

(defn primes
  "Returns an infinite lazy sequence of the prime numbers."
  []
  (concat [2 3] (filter prime? (potential-primes))))

(defn fibonacci
  "Returns an infinite lazy sequence of Fibonacci numbers."
  ([] (fibonacci 0 1))
  ([a b] (cons a (lazy-seq (fibonacci b (+ a b))))))

(defn triangulars
  "Returns an infinite lazy sequence of the triangular numbers."
  []
  (reductions + (range)))

;;;;; Other

(defn factorial
  "Calculates the factorial of n."
  [n]
  (apply * (rangei 1N n)))

(defn digits
  "Returns a lazy sequence of the digits of n as individual integers. The digits
  are in little endian order (from least significant to most significant)."
  [n]
  (->> (iterate #(quot % 10) n)
       (take-while (complement zero?))
       (map #(small-int (rem % 10)))))
