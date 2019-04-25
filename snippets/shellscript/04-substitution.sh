#!/usr/bin/env bash
# Use backticks "` `" to exectute shell command.
echo `uname -o`
#    ^^^^^^^^^^
#    command substitution.

# Exectute bash command without backticks.
echo uname -o

# An alternative way to perform command substituion.
echo $(uname -o)
