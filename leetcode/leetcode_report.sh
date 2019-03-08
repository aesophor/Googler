#!/usr/bin/env zsh

time_complexity_lines=`cat *.cc | grep Runtime | cut -d ' ' -f 7`
space_complexity_lines=`cat *.cc | grep Memory | cut -d ' ' -f 8`

time_complexity_sum=`echo $time_complexity_lines | awk '{s+=$1} END {print s}'`
space_complexity_sum=`echo $space_complexity_lines | awk '{s+=$1} END {print s}'`
file_count=`echo $time_complexity_lines | wc -l`

write_to="README.md"

echo "## LeetCode Report" > $write_to
echo "* Avg Runtime is" $((time_complexity_sum / file_count))% "faster than other submissions" >> $write_to
echo "* Avg Memory is" $((space_complexity_sum / file_count))% "less than other submissions" >> $write_to
