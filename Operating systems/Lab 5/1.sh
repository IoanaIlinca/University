#!/bin/bash
files=`find $1 -type f`
sum=0
cnt=0
for file in $files
do
        is_text=`file $file | grep -c "text"`
        if [ $is_text -eq 1 ]; then
                nl=`cat $file | wc -l`
                sum=$((sum+nl))
                cnt=$((cnt+1))
        fi
done
echo $((sum/cnt))        