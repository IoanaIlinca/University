#!/bin/bash
files=`find . -type f`
for file in $files
do
        is_text=`file $file | egrep -c 'text'`
        if [ $is_text -gt 0 ]; then
                if [ `cat $file | wc -l` -lt 10 ]; then
                        cat $file
                else
                        cat $file | head -n5
                        cat $file | tail -n5
                fi
        fi
done
~                                                                                      ~                                                                                      ~                                                                                      ~                                                                                      ~                                                                                      ~                                                                                      ~              