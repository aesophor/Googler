#!/usr/bin/env bash
# Bash trap command
trap bashtrap INT
# bash clear screen command.
clear

# bashtrap function is executed when CTRL-C is pressed.
# bash prints message => Executing bash trap subroutine!
function bashtrap()
{
    echo "CTRL-C detected!... Executing bash trap subroutine!"
    exit 0
}

# For loop from 1/10 to 10/10
for i in {1..5}; do
    echo "$i/5 to Exit"
    sleep 1;
done
