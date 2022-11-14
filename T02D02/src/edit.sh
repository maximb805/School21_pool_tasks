#!/bin/bash
cd ..
read -p 'Enter path to file: ' path
if test -f "$path";
    then
        read -p 'Enter the substring for change ("\" and "/" are unavailable): ' stSearch
        if [[ $stSearch != '' && $stSearch != '\' && $stSearch != *'/'* ]]
            then
                read -p 'Enter new substring ("\" and "/" are unavailable): ' stNew
                if [[ $stNew != '\' && $stNew != *'/'* ]]
                    then
                        sed -i '' "s/$stSearch/$stNew/g" $path
                        
                        DATE=`stat -f %SB -t "%Y-%m-%d %H:%M" $path`
                        BYTES=$(wc -c $path | awk '{print $1}')
                        SHA256=$(shasum -a 256 $path | awk '{print $1}')
                    else
                        echo 'Unavailable substring'
                    fi
                echo $path" - "$BYTES" - "$DATE" - "$SHA256" - sha256" >> ~/T02D02/src/files.log
            else
                echo 'Unavailable substring'
        fi
    else
        echo 'File not found'
fi
