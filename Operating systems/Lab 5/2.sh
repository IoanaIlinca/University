#!/bin/bash
files=`find $1 -type f`
for file in $files
do
        cond=`cat $file | sed 's/[^0-9]/ /g' | awk  '{for(i=0; i<NF; ++i) if ($i > 99999) print $i}' | wc -l`

        #echo "${cond}"
        #echo "${file}"
        #cond=0
        #for i in `cat $file`
        #do
                #if [[ $i =~ ^[0-9]+$ ]]; then
                        #if [ $i -gt 99999 ]; then
                                #cond=1
                        #fi
                #fi
        #done
        if [ $cond -gt 0 ]; then
                echo "${file}"
        fi
done
~       