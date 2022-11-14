CC = gcc
FLAGS = -c -Wall -Wextra -Werror

strlen_tests : mkdir s21_string_test.o s21_string.o
	$(CC) ./../obj/s21_string_test.o ./../obj/s21_string.o -o ./../build/Quest_1

strcmp_tests : mkdir s21_string_test.o s21_string.o
	$(CC) ./../obj/s21_string_test.o ./../obj/s21_string.o -o ./../build/Quest_2

strcpy_tests : mkdir s21_string_test.o s21_string.o
	$(CC) ./../obj/s21_string_test.o ./../obj/s21_string.o -o ./../build/Quest_3

strcat_tests : mkdir s21_string_test.o s21_string.o
	$(CC) ./../obj/s21_string_test.o ./../obj/s21_string.o -o ./../build/Quest_4

strchr_tests : mkdir s21_string_test.o s21_string.o
	$(CC) ./../obj/s21_string_test.o ./../obj/s21_string.o -o ./../build/Quest_5

strstr_tests : mkdir s21_string_test.o s21_string.o
	$(CC) ./../obj/s21_string_test.o ./../obj/s21_string.o -o ./../build/Quest_6

s21_string_test.o : 
	$(CC) $(FLAGS) s21_string_test.c -o ./../obj/s21_string_test.o

s21_string.o : 
	$(CC) $(FLAGS) s21_string.c -o ./../obj/s21_string.o

text_processor : text_processor.o
	$(CC) ./../obj/text_processor.o -o ./../build/Quest_8

text_processor.o : 
	$(CC) $(FLAGS) ./text_processor.c -o ./../obj/text_processor.o


mkdir :
	mkdir -p ./../obj 

rebuild : clean 
	make all

clean : clean_obj clean_build

clean_obj :
	rm -rf ./../obj

clean_build :
	rm -f ./../build/*
