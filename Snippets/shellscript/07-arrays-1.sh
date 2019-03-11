#!/usr/bin/env bash
# Declare an array with 4 elements.
arr=( 'Arch Linux' 'Debian Linux'  Gentoo Linux )

# Get the number of elements in arr.
elements=${#arr[@]}

# echo each element in the array.
echo "${arr[@]}"

# alternatively, using a for loop...
for (( i=0; i<elements; i++)); do
    echo $i
done
