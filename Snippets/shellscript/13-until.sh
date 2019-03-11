#!/usr/bin/env bash
# Declare an integer.
count=5

# bash until loop
until [ $count -lt -1 ]; do
    echo $count
    let count--
done
