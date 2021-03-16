#!/bin/bash
files=`find $1 -type f -perm -222`
for f in $files
do
        mv "$f" "$f.all"
done