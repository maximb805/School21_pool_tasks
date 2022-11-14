cd ai_help
ls
sh keygen.sh
cd key
ls
cd ..
cd ..
echo "Deleting... "

for file in ai_help/key/*
    do
        if [[ $file =~ \.key$ ]]
        then
            continue
        else
            rm $file
        fi
    done

cd ai_help/key
ls
cd ..
sh unifier.sh
