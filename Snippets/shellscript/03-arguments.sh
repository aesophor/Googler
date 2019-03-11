#!/usr/bin/env bash
# Use predefined variables to access passed arguments.
# echo arguments to the shell.
echo $1 $2 $3

# We can also store arguments from the bash command line in an special array.
args=("$@")
#args[0]="$1"
#args[1]="$2"
#args[2]="$3"

# echo arguments to the shell.
echo ${args[0]} ${args[1]} ${args[2]}

# Use ${array[@]} to print out all elements in the array at once.
echo ${args[@]}

# Use $@ to print out all arguments at once.
echo $@

# Use $# variable to print out number of arguments passed to the bash script.
echo "Number of arguments passed:" $#
