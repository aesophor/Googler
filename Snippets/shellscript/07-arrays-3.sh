#!/usr/bin/env bash
declare -A aa
aa[hello]=world
aa[ab]=cd

echo ${aa[@]}
