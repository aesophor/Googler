#!/usr/bin/env bash
# Declare an integer
index=0

# bash for loop
for file in `ls /home/decimate`; do
    echo [$index] $file
    (( index++ ))
done
