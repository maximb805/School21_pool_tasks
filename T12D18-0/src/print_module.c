#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "print_module.h"

char * get_time_str();

char print_char(char ch) {
    if (ch) {
        printf("%c", ch);
    }
    return ch;
}

void print_log(char (*print)(char), char * message) {
    for (int i = 0; print(Log_prefix[i]); i++) {}
    print(32);
    char * time = get_time_str();
    for (int i = 0; print(time[i]); i++) {}
    free(time);
    print(32);
    for (int i = 0; print(message[i]); i++) {}
}

char * get_time_str() {
    struct tm * time_struct;
    time_t time_sec = time(NULL);
    char * time_string = malloc(8);
    time_struct = localtime(&time_sec);
    strftime(time_string, 8, "%H:%M:%S", time_struct);
    return time_string;
}
