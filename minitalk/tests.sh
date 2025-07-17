#!/bin/zsh
export TEST='testing'
while true;
do export TEST=$TEST$TEST;
./client $1 $TEST
date +"%T"
sleep 1
done

