mv door_management_fi door_management_files
cd door_management_files

mkdir door_configuration
mkdir door_map
mkdir door_logs

for file in `find . -maxdepth 1 -type f -name "*.conf"`
    do
        mv $file door_configuration
    done
    
for file in `find . -maxdepth 1 -type f -name "*.log"`
    do
        mv $file door_logs
    done
    
mv door_map_1.1 door_map

cd ..
