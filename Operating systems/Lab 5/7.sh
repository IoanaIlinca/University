#!/bin/bash
IFS='$'
for file in $*
do
        counter=-1
        finalLine=""
        for line in `grep "^.*$" $file`
        do
                echo "${line} 1"
                IFS=' '
                if [ `grep -c "$line" $file` -gt $counter ]; then
                        #counter=`grep -c "${line}" $file`
                        finalLine=`echo "${line}"`
                fi
                IFS='$'
        done
        #echo "${finalLine}"
done