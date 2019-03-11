#!/usr/bin/env bash
# Declare variable choice and assign value 4.
choice=`echo 4`

# Print to stdout
echo "1. Bash"
echo "2. Scripting"
echo "3. Tutorial"
echo -n "Please choose a word [1,2,3] ?: "

# Loop while the variable is equal to 4.
# Bash while loop
while [ $choice -eq 4 ]; do
    read choice
    if [ $choice -eq 1 ]; then
        echo "You have chosen the word \"Bash\""
    elif [ $choice -eq 2 ]; then
        echo "You have chosen the word \"Scripting\""
    elif [ $choice -eq 3 ]; then
        echo "You have chosen the word \"Tutorial\""
    else
        echo "Wrong option. Retry!"
        choice=4
    fi
done

