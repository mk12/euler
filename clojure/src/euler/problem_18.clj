;;; Copyright 2014 Mitchell Kember. Subject to the MIT License.
;;; Project Euler: Problem 18
;;; Maximum path sum I

(ns euler.problem-18)

(def side 15)
(def matrix
  [75 64 82 10 65 34 67 92 33 29 14 57 48 31 23
   95 47 87 47 03 63 70 70 94 51 17 29 40 04  0
   17 35 82 75 07 16 80 16 97 68 27 87 60  0  0
   18 04 23 73 06 40 37 52 39 50 69 53  0  0  0
   20 01 77 28 83 32 91 78 58 16 38  0  0  0  0
   19 02 04 56 47 43 17 43 73 93  0  0  0  0  0
   88 65 26 33 25 73 91 30 73  0  0  0  0  0  0
   99 41 72 65 77 14 67 98  0  0  0  0  0  0  0
   41 48 44 28 17 53 70  0  0  0  0  0  0  0  0
   41 71 33 38 89  9  0  0  0  0  0  0  0  0  0
   53 11 52 68 23  0  0  0  0  0  0  0  0  0  0
   70 71 04 27  0  0  0  0  0  0  0  0  0  0  0
   91 66 98  0  0  0  0  0  0  0  0  0  0  0  0
   63 62  0  0  0  0  0  0  0  0  0  0  0  0  0
   04  0  0  0  0  0  0  0  0  0  0  0  0  0  0])

(defn item
  "Returns the value at the coordinates (i,j) in the matrix."
  [i j]
  (matrix (+ (* i side) j)))

(defn max-sum
  "Calculates the maximum sum that can be obtained starting at (i,j) on the
  matrix and moving only right and down until a zero is reached."
  [i j]
  (let [x (item i j)]
    (if (== (+ i j) (dec side))
      x
      (+ x (max (max-sum (inc i) j)
                (max-sum i (inc j)))))))

(defn solve []
  (max-sum 0 0))
