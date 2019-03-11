#!/usr/bin/env bash
# Declare Array
declare -a arr

# Link file descriptor 10 with stdin.
exec 10<&0

# stdin replaced with a file supplied as a first argument.
exec <$1

let count=0

while read LINE; do
    echo $count
    arr[$count]=$LINE
    let count++
done
