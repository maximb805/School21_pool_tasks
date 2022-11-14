#ifndef S21_STRING_H
#define S21_STRING_H

#include <stdlib.h>
#include <stdio.h>

size_t s21_strlen(const char * str);
int s21_strcmp(const char *str1, const char *str2);
char * s21_strcpy(char * str_new, const char * str);
char * s21_strcat(char * str1, const char * str2);
char * s21_strchr(char *str, int ch);
char * s21_strstr(char * str, char * str_search);

#endif
