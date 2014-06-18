;;; Copyright 2014 Mitchell Kember. Subject to the MIT License.

(ns euler.test
  (:import [java.lang Integer System])
  (:gen-class))

(def answers
  [233168, 4613732, 6857, 906609, 232792560, 25164150, 104743, 23514624000,
   31875000, 142913828922, 70600674, 76576500, 5537376230, 837799, 137846528820,
   ;; 1366, 21124, 1074, 171, 648
   ])

(def usage "usage: test [ -h | problem_number]")

(defn printf-f
  "Like printf, but flushes the stream afterwards."
  [& more]
  (apply printf more)
  (flush))

(defn fail
  "Prints msg to stderr and exits with exit status 1 to indicate failure."
  [msg]
  (binding [*out* *err*]
    (println msg))
  (System/exit 1))

(defn context-err
  "Creates a contextualized error message in a consistent format."
  [context msg]
  (str "error: " context ": " msg))

(defn fail-c [c m] (fail (context-err c m)))

(defn status-msg
  "Returns a string to indicate the given success status."
  [success]
  (if success "ok" "FAIL"))

(defn get-solve
  "Retrieves the solve function for the nth Euler problem."
  [n]
  (let [ns-str (format "euler.problem-%02d" n)]
    (require (symbol ns-str))
    (resolve (symbol (str ns-str "/solve")))))

(defn bench-seconds
  "Benchmarks the function f, returning a vector [r t] where r is the result
  that f returned and t is the execution time in seconds."
  [f]
  (let [start (System/nanoTime)
        result (f)
        end (System/nanoTime)]
    [result (/ (- end start) 1e9)]))

(defn test-solution
  "Tests the solution to the nth Euler problem. Prints the number n, the result
  the program produces, the success status, and the time elapsed. Returns true
  if the answer was correct."
  [n]
  (let [solve (get-solve n)
        [result t] (bench-seconds solve)
        success (= result (answers (dec n)))
        msg (status-msg success)]
    (printf-f "%02d: %12d ... %s (%e s)\n" n result msg t)
    success))

(defn test-all
  "Tests the solutions to all the Euler problems. At the end, prints a summary
  of how many passed/failed, exiting with the appropriate exit status."
  []
  (let [problems (range 1 (inc (count answers)))
        passes (count (filter test-solution problems))
        fails (- (count answers) passes)
        success (zero? fails)
        msg (status-msg success)]
    (printf-f "%s. %d passed; %d failed\n" msg passes fails)
    (if-not success (System/exit 1))))

(defn one-argument
  "Handles the case where a single command-line argument is supplied."
  [arg]
  (if (= arg "-h")
    (println usage)
    (try (let [n (Integer/parseInt arg)]
           (if (<= 1 n (count answers))
             (test-solution n)
             (fail-c arg "out of bounds")))
         (catch NumberFormatException nfe
           (fail-c arg "not an int")))))

(defn -main [& args]
  (case (count args)
    0 (test-all)
    1 (one-argument (first args))
    (fail usage)))
