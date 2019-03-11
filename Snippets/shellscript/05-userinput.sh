#!/usr/bin/env bash
echo -e "Hi, please type a word: \c"
#    ^^                         ^^
#    -e means "Enable interpretation of backslash escape".
#    \c means "Stay on the same line."

# It has the same effect as:
#echo -n "Hi, please type a word:"

read word

echo "The word you just entered is: $word"
echo -e "Can you please enter another two words: \c"
read word1 word2

echo "Here is your input: \"$word1\" \"$word2\""

# -a makes read command to read into an array
echo -n "What are your top 3 favourite colors: "
read -a colours
echo "My favourite colours are ${colours[0]} ${colours[1]} ${colours[2]}"
