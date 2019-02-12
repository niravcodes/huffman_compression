#! /bin/bash

if [ -z "$1" ]
then
    file=a 
else
    file=$1
fi

echo "no. of raw alphabets processed"
./huff $file | tr -cd '^' | wc -c

echo "no. of dequeued elements "
./huff $file | tr -cd '*' | wc -c

echo "no. of contrived alphabets (huffman nodes?)"
./huff $file | tr -cd '-' | wc -c

echo "all elements dequeued, sorted"
./huff $file | grep '*' | sort -k 1n