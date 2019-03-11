#!/usr/bin/env bash
# Define bash global variable.
# This variable is global and can be used anywhere in this bash script.
var="global variable"

# Define bash local variable (inside the function "bash")
# This variable is local to function "bash" only.
function bash()
{
    local var="local variable"
    echo $var
}

echo $var
bash
echo $var
