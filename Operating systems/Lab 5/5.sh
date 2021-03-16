#!/bin/bash
for var in $*
do
        if [ -f $var ]; then
                echo "File: ${var} the number of chars: " `cat $var | wc -m` " lines: " `cat $var | wc -l`
        fi
        if [ -d $var ]; then
                echo "Directory: ${var} the number of files: " `find $var -type f | wc -l`
        fi
done