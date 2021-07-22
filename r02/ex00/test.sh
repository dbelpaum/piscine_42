#!/bin/bash

if [ "$#" != "1" ]; then
	echo "error: Invalid argument"
	exit
fi

num=$1 
while [ "$num" -ge "0" ]; do
	./rush-02 numbers.dict $num
	num=`expr "$num" - 1`;
done
