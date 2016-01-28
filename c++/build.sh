#!/bin/bash

cd "$(dirname "$0")"

name=$(basename "$0")
usage="usage: $name [-h] [-d] [-o file]"
debug_opts="-DNDEBUG -O3"
output="test"
cxx=${CXX:-clang++}

while getopts ":do:h" opt; do
	case "${opt}" in
		d) debug_opts="-g";;
		o) output="$OPTARG";;
		h)
			echo "$usage"
			exit 0
			;;
		\?)
			echo "$name: $OPTARG: illegal option" >&2
			echo "$usage" >&2
			exit 1
			;;
	esac
done
shift $((OPTIND-1))

if (($# > 0)); then
	echo "$usage" >&2
	exit 1
fi

$cxx -o $output -std=c++14 $debug_opts \
	-Weverything -pedantic -Wno-c++98-compat -Wno-missing-prototypes \
	-isystem /usr/local/include -L /usr/local/lib \
	-lgmpxx -lgmp \
	test.cpp common.cpp problem_*.cpp
