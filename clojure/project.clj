(defproject mk12/euler "42"
  :description "Solutions to Project Euler"
  :url "http://github.com/mk12/euler"
  :license {:name "MIT License"
            :url "http://opensource.org/licenses/MIT"}
  :dependencies [[org.clojure/clojure "1.6.0"]]
  :plugins [[lein-bin "0.3.4"]]
  :main euler.test
  :bin {:name "test" :bootclasspath true}
  :profiles {:uberjar {:aot :all}})
