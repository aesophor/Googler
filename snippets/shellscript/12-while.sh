#!/usr/bin/env bash
# Declare an integer
count=5

# bash while loop
while [ $count -ge 0 ]; do
    echo "$count"
    let count-- 
done
