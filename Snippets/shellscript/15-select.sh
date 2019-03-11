#!/usr/bin/env bash
PS3='Choose one word: '

arr[0]="linux"
arr[1]="bash"
arr[2]="scripting"

# bash select
select word in ${arr[@]}; do
    if [ $word = "linux" ]; then
        echo "all hail linux. Exitting."
        break
    elif [ $word = "bash" ]; then
        echo "bash is awesome. Exitting."
        break
    else
        echo "The word you have selected is: $word, Try again"
    fi
done

exit 0
