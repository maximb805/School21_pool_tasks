CC = gcc
FLAGS = -c -Wall -Wextra -Werror

all : mkdir data_process.o data_io.o data_stat.o main_executable_module.o decision.o
	$(CC) ./../../obj/*.o -o ./../../build/Quest_3

data_io.o : ./../data_libs/data_io.c
	$(CC) $(FLAGS) ./../data_libs/data_io.c -o ./../../obj/data_io.o

data_stat.o : ./../data_libs/data_stat.c
	$(CC) $(FLAGS) ./../data_libs/data_stat.c -o ./../../obj/data_stat.o

data_process.o : ./../data_module/data_process.c
	$(CC) $(FLAGS) ./../data_module/data_process.c -o ./../../obj/data_process.o

main_executable_module.o : ./main_executable_module.c
	$(CC) $(FLAGS) ./main_executable_module.c -o ./../../obj/main_executable_module.o

decision.o : ./../yet_another_decision_module/decision.c
	$(CC) $(FLAGS) ./../yet_another_decision_module/decision.c -o ./../../obj/decision.o

data_stat.a : data_stat.o
	ar rcs ./../../obj/data_stat.a ./../../obj/data_stat.o 

build_with_static : clean_obj mkdir data_process.o data_io.o data_stat.a main_executable_module.o decision.o
	$(CC) ./../../obj/*.o ./../../obj/data_stat.a -o ./../../build/Quest_5

data_process.so :
	gcc -fPIC -shared ./../data_module/data_process.c ./../data_libs/data_stat.c -o ./../../obj/data_process.so

build_with_dynamic : clean_obj mkdir data_io.o main_executable_module.o decision.o data_process.so
	$(CC) ./../../obj/*.o ./../obj/data_process.so -o ./../../build/Quest_6

mkdir :
	mkdir -p ./../../obj 

rebuild : clean 
	make all

clean : clean_obj clean_build

clean_obj :
	rm -rf ./../../obj

clean_build :
	rm -f ./../../build/*