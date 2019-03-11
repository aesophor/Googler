#!/usr/bin/env bash
# Bash function can be declared in any order
function func_B()
{
    echo func_B
}

function func_A()
{
    echo $1
    func_C fuck the world
}

function func_C()
{
    echo $@
}

# Function calls
func_B
func_A "I'll"
