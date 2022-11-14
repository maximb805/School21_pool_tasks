CC = gcc
FLAGS = -c -Wall -Wextra -Werror

door_struct : mkdir dmanager_module.o
	$(CC) ../obj/dmanager_module.o -o ../build/Quest_1

list_test : mkdir list.o list_test.o
	$(CC) ../obj/list.o ../obj/list_test.o -o ../build/Quest_2

stack_test : mkdir stack.o stack_test.o
	$(CC) ../obj/stack.o ../obj/stack_test.o -o ../build/Quest_3

stack.o : 
	$(CC) $(FLAGS) ./stack.c -o ../obj/stack.o

stack_test.o : 
	$(CC) $(FLAGS) ./stack_test.c -o ../obj/stack_test.o

list.o :
	$(CC) $(FLAGS) list.c -o ../obj/list.o

dmanager_module.o : 
	$(CC) $(FLAGS) ./dmanager_module.c -o ../obj/dmanager_module.o

list_test.o :
	$(CC) $(FLAGS) list_test.c -o ../obj/list_test.o

mkdir :
	mkdir -p ./../obj 

rebuild : clean 
	make door_struct

clean : clean_obj clean_build

clean_obj :
	rm -rf ./../obj

clean_build :
	rm -f ./../build/*
