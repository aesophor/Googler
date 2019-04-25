#!/usr/bin/env bash
echo "Which is your preferred programming/scripting language?"
echo "1) bash"
echo "2) perl"
echo "3) python"
echo "4) c++"
read select

# simple case bash structure
case $select in
    1) echo "You selected bash!";;
    2) echo "You selected perl!";;
    3) echo "You selected python!";;
    4) echo "You selected c++!";;
esac
