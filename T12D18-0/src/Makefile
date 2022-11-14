CC = gcc
FLAGS = -c -Wall -Wextra -Werror

bst_traverse_test : clean_obj mkdir bst_traverse_test.o bst.o
	$(CC) ../obj/bst_traverse_test.o ../obj/bst.o -o ./../build/Quest_5

bst_create_test : clean_obj mkdir bst_create_test.o bst.o
	$(CC) ../obj/bst_create_test.o ../obj/bst.o -o ./../build/Quest_3

bst_insert_test : clean_obj mkdir bst_insert_test.o bst.o
	$(CC) ../obj/bst_insert_test.o ../obj/bst.o -o ./../build/Quest_4

bst_traverse_test.o :
	$(CC) $(FLAGS) bst_traverse_test.c -o ../obj/bst_traverse_test.o

bst_insert_test.o :
	$(CC) $(FLAGS) bst_insert_test.c -o ../obj/bst_insert_test.o

bst_create_test.o :
	$(CC) $(FLAGS) bst_create_test.c -o ../obj/bst_create_test.o

bst.o :
	$(CC) $(FLAGS) bst.c -o ../obj/bst.o

print_module : clean_obj mkdir documentation_module.o print_module.o main_module_entry_point.o
	$(CC) ../obj/main_module_entry_point.o ../obj/print_module.o  ../obj/documentation_module.o -o ../build/Quest_1

documentation_module : clean_obj mkdir documentation_module.o main_module_entry_point.o
	$(CC) ../obj/main_module_entry_point.o ../obj/documentation_module.o -o ../build/Quest_2

main_module_entry_point.o :
	$(CC) $(FLAGS) main_module_entry_point.c -o ../obj/main_module_entry_point.o

print_module.o :
	$(CC) $(FLAGS) print_module.c -o ../obj/print_module.o

documentation_module.o :
	$(CC) $(FLAGS) documentation_module.c -o ../obj/documentation_module.o

mkdir :
	mkdir -p ./../obj 

rebuild : clean 
	make door_struct

clean : clean_obj clean_build

clean_obj :
	rm -rf ./../obj

clean_build :
	rm -f ./../build/*
