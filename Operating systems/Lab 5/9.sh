#!/bin/bash
for file in `find $1 -type f -perm 755`
do
        echo "Can I change ${file}'s permissions to 744? [y/n]"
        read answer
        if [ $answer == "y" ]; then
                chmod 744 $file
        fi
done