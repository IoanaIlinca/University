#!/bin/bash
while [ $# -ne 0 ]
do
        file=$1
        word=$2
        number=$3
        #cat $file
        awk -v num=$number -v w=$word '{
        n=0
        for(i=1;i<=NF;i++)
                if($i==w) n++
        if(n==num) print $0
        }' "$file"
        shift 3
done