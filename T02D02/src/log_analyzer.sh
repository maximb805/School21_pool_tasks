#!/bin/bash
cd ..
path=$1
if [ $# != 1 ]
    then
        echo 'Command must contain 1 parameter (path to a log file)'
    else
        if [[ $path == *'.log' ]]
            then
                if test -f "$path";
                    then
                        LINES=$(wc -l $path | awk '{print $1}')
                        FILES=$(awk '{print $1}' $path | sort | uniq | wc -l)
                        HASHES=$(awk '{print $8}' $path | sort | uniq | wc -l)
                        echo $LINES" "$FILES" "$HASHES
                    else
                        echo 'File does not exist'
                fi
            else
                echo 'Not a log file'
        fi
fi

