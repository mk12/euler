#!/bin/bash

set -eufo pipefail

readonly n_solved=18
readonly solutions=(
    233168 4613732 6857 906609 232792560 25164150 104743 23514624000 31875000
    142913828922 70600674 76576500 5537376230 837799 137846528820 1366 21124
    1074
)

usage() {
    cat <<EOS
usage: $0 [-h | PROBLEM]

Runs J scripts that solve Project Euler problems.
EOS
}

die() {
    echo "$0: $*" >&2
    exit 1
}

out=$(mktemp)

trap 'rm -f "$out"' EXIT

run() {
    [[ "$1" -ge 1 && "$1" -le "$n_solved" ]] || die "$1: problem out of range"
    expected=${solutions[$(( $1 - 1 ))]}
    file=$(printf "problem_%02d.ijs" "$1")
    [[ -f "$file" ]] || die "$file: file not found"
    elapsed=$({ time jconsole -jprofile < "$file" > "$out"; } 2>&1 |
        grep real | awk '{print $2;}')
    result=$(cat "$out")
    msg=ok
    [[ "$result" != "$expected" ]] && msg=FAIL
    printf "%02d: %12s ... %4s (%s)\n" "$1" "$result" "$msg" "$elapsed"
    [[ "$msg" == ok ]]
}

run_all() {
    fails=0
    for i in $(seq "$n_solved"); do
        run "$i" || (( fails++ ))
    done
    msg=ok
    [[ "$fails" -gt 0 ]] && msg=FAIL
    passes=$(( n_solved - fails ))
    printf "%s. %d passed; %d failed\n" "$msg" "$passes" "$fails"
    [[ "$msg" == ok ]]
}

main() {
    cd "$(dirname "$0")"
    if [[ $# -gt 1 ]]; then
        usage >&2
        exit 1
    fi
    if [[ $# -lt 1 ]]; then
        run_all
    else
        case $1 in
            -h|--help) usage; exit 0;;
            *) if [[ "$1" =~ ^[0-9]+$ ]]; then
                run "$1"
            else
                die "$1: invalid problem"
            fi
            ;;
        esac
    fi
}

main "$@"
