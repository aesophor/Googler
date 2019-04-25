#!/usr/bin/env bash
directory="./Bashscripting"

# bash check if directory exists.
if [ -d $directory ]; then
    echo "directory exists."
else
    echo "directory not found."
fi
