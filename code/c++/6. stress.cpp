#!/usr/bin/env bash
wrong="solution"
correct="brute"
gen="gen"
g++ -g solution.cpp -DONPC -o "$wrong"
g++ -g brute.cpp -DONPC -o "$correct"
g++ -g gen.cpp -DONPC -o "$gen"

for ((testNum=0;testNum<$1;testNum++))
do
	./$gen 2>/dev/null > stdinput
	./$correct < stdinput 2>/dev/null > outSlow
	./$wrong < stdinput 2>/dev/null > outWrong
	H1=`md5sum outWrong`
	H2=`md5sum outSlow`
	if !(cmp -s "outWrong" "outSlow")
	then
    	echo "Error found!"
    	echo "Input:"
    	cat stdinput
    	echo "Wrong Output:"
    	cat outWrong
    	echo "Slow Output:"
    	cat outSlow
    	exit
	fi
done
echo Passed $1 tests
# Usage: ./contest.sh times
