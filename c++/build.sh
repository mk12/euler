#!/bin/bash

clang++ -std=c++14 \
	-Weverything -DNDEBUG -pedantic -Wno-c++98-compat -Wno-missing-prototypes \
	-o test -Ofast \
	test.cpp common.cpp problem_*.cpp
