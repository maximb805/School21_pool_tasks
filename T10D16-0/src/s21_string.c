#include "./s21_string.h"

size_t s21_strlen(const char * str) {
    size_t str_length = 0;
    while (*str) {
        str_length++;
        str++;
    }
    return str_length;
}

int s21_strcmp(const char *str1, const char *str2) {
    int result = 0;
    for (int i = 0; str1[i] || str2[i]; i++) {
        if (str1[i] != str2[i]) {
            result = str1[i] - str2[i];
            break;
        }
    }
    return result;
}

char * s21_strcpy(char * str_new, const char * str) {
    int i;
    for (i = 0; str[i]; i++) {
        str_new[i] = str[i];
    }
    str_new[i] = '\0';
    return str_new;
}

char * s21_strcat(char * str1, const char * str2) {
    char * str1_start = str1;
    while (*str1) {
        str1++;
    }
    int i;
    for (i = 0; str2[i]; i++) {
        str1[i] = str2[i];
    }
    str1[i] = '\0';
    return str1_start;
}

char * s21_strchr(char *str, int ch) {
    int i;
    char * result = NULL;
    for (i = 0; str[i]; i++) {
        if (str[i] == ch) {
            result = &str[i];
            break;
        }
    }
    return result;
}


char * s21_strstr(char * str, char * str_search) {
    char * result = NULL;
    int str_search_counter = 0;
    if (str_search[str_search_counter] != '\0' && str != NULL) {
        int i;
        for (i = 0; str[i]; i++) {
            if (str[i] == str_search[str_search_counter]) {
                str_search_counter++;
            } else {
                i -= str_search_counter;
                str_search_counter = 0;
            }
            if (str_search[str_search_counter] == '\0') {
                break;
            }
        }
        if (str_search[str_search_counter] == '\0') {
            result = &str[i - str_search_counter + 1];
        }
    } else {
        if (str != NULL) {
            result = str;
        }
    }
    return result;
}
