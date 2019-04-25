#!/usr/bin/env bash
# Declare string s1
s1=""
s2="fuxsocya"


if [ "$s1" \< "$s2" ]; then
    echo "s1 is shorter then s2!"
fi


if [ -n $s1 ]; then
    echo "The string is not empty!"
else
    echo "The string is empty!"
fi

if [ -n "$s1" ]; then
    echo "The string is not empty!"
else
    echo "The string is empty!"
fi
