#include "./s21_string.h"

void s21_strlen_test(char * str, size_t length);
void s21_strcmp_test(char * str1, char * str2, int diff);
void s21_strcpy_test(char * str_new, char * str);
void s21_strcat_test(char * str1, char * str2);
void s21_strchr_test(char * str, int ch, char * expected_result);
void s21_strstr_test(char * str, char * str_search, char * expected_result);

int main() {
    // TEST 1 --->
//     size_t str_length, str1_length, str2_length;
//     char * str = "This is normal string!";
//     char * str1 = "";
//     char * str2 = "\\\'\"@";
//     str_length = 22;
//     str1_length = 0;
//     str2_length = 4;
//     s21_strlen_test(str, str_length);
//     printf("\n");
//     s21_strlen_test(str1, str1_length);
//     printf("\n");
//     s21_strlen_test(str2, str2_length);

    // TEST 2 --->
    // char * str = "This is normal string!";
    // char * str1 = "";
    // char * str2 = "\\\'\"@";
    // s21_strcmp_test(str, str, 0);
    // printf("\n");
    // s21_strcmp_test(str1, str, -84);
    // printf("\n");
    // s21_strcmp_test(str2, str, 8);

    // TEST 3 --->
    // char * str_new = malloc(1);
    // char * str = "This is normal string!";
    // char * str1 = "";
    // char * str2 = "\\\'\"@";
    // s21_strcpy_test(str_new, str);
    // printf("\n");
    // s21_strcpy_test(str_new, str1);
    // printf("\n");
    // s21_strcpy_test(str_new, str2);
    // free(str_new);

    // TEST 4 --->
    // char * str_new = malloc(1);
    // char * str = "This is normal string!";
    // char * str1 = "";
    // char * str2 = "\\\'\"@";
    // s21_strcat_test(str_new, str);
    // printf("\n");
    // s21_strcat_test(str_new, str2);
    // printf("\n");
    // s21_strcat_test(str_new, str1);
    // printf("\n");
    // s21_strcat_test(str_new, str);
    // free(str_new);

    // TEST 5 --->
    // char * str = "This is normal string!";
    // char * str1 = "";
    // char * str2 = "\\\'\"@";
    // s21_strchr_test(str, 'i', &str[2]);
    // printf("\n");
    // s21_strchr_test(str1, 'i', NULL);
    // printf("\n");
    // s21_strchr_test(str2, 'f', NULL);
    // printf("\n");
    // s21_strchr_test(str2, '@', &str2[3]);

    // TEST 6 --->
    // char * str = "This is normal string!";
    // char * str1 = "";
    // char * str2 = "\\\'\"@";
    // s21_strstr_test(str, "is n", &str[20]);
    // printf("\n");
    // s21_strstr_test(str1, "f", NULL);
    // printf("\n");
    // s21_strstr_test(str2, "@\f", NULL);
    // printf("\n");
    // s21_strstr_test(str2, "", &str2[0]);
    // printf("\n");
    // s21_strstr_test(str, "nort", NULL);
    return 0;
}

void s21_strlen_test(char * str, size_t length) {
    printf("%s\n", str);
    size_t check_length = s21_strlen(str);
    printf("%s\n", str);
    if (check_length == length) {
        printf("SUCCESS");
    } else {
        printf("FAIL");
    }
}

void s21_strcmp_test(char * str1, char * str2, int diff) {
    printf("%s %s\n", str1, str2);
    int check_cmp = s21_strcmp(str1, str2);
    printf("%s %s %d\n", str1, str2, check_cmp);
    if (check_cmp == diff) {
        printf("SUCCESS");
    } else {
        printf("FAIL");
    }
}

void s21_strcpy_test(char * str_new, char * str) {
    printf("%s %s\n", str_new, str);
    str_new = s21_strcpy(str_new, str);
    printf("%s %s\n", str_new, str);
    if (!s21_strcmp(str, str_new)) {
        printf("SUCCESS");
    } else {
        printf("FAIL");
    }
}

void s21_strcat_test(char * str1, char * str2) {
    printf("%s %s\n", str1, str2);
    size_t strs_len = s21_strlen(str1) + s21_strlen(str2);
    str1 = s21_strcat(str1, str2);
    printf("%s %s\n", str1, str2);
    if (s21_strlen(str1) == strs_len) {
        printf("SUCCESS");
    } else {
        printf("FAIL");
    }
}

void s21_strchr_test(char * str, int ch, char * expected_result) {
    printf("%s\n", str);
    char * result = s21_strchr(str, ch);
    printf("%s %s\n", str, result);
    if ((expected_result == NULL && result == NULL) ||
        !s21_strcmp(expected_result, result)) {
        printf("SUCCESS");
    } else {
        printf("FAIL");
    }
}

void s21_strstr_test(char * str, char * str_search, char * expected_result) {
    printf("%s\n", str);
    char * result = s21_strstr(str, str_search);
    printf("%s %s\n", str, result);
    if ((expected_result == NULL && result == NULL) ||
        !s21_strcmp(expected_result, result)) {
        printf("SUCCESS");
    } else {
        printf("FAIL");
    }
}
