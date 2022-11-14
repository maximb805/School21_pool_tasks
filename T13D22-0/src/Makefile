CC = gcc
FLAGS = -c -Wall -Werror -Wextra 

cipher : clean_obj mkdir cipher.o
	$(CC) ../obj/cipher.o -o ../build/cipher

cipher.o :
	$(CC) $(FLAGS) cipher.c -o ../obj/cipher.o

mkdir :
	mkdir -p ./../obj 

rebuild : clean 
	make door_struct

clean : clean_obj clean_build

clean_obj :
	rm -rf ./../obj

clean_build :
	rm -f ./../build/*
