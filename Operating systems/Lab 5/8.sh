#!/bin/bash
dir=$1
for f in `find $dir -type f`
do
        file_name=`echo "${f}" | awk -F/ '{print $NF}'`
        if [ `echo "${file_name}" | wc -m` -lt 8 ]; then
                echo "${file_name}"
                if [ `file $f | grep "text" | wc -l` -gt 0 ]; then
                        cat $f | head
                fi
        fi
done