#include <stdio.h>
#include <stdlib.h>
#define MAX_LENGTH 100

int check_argv(char * argv[]);
int get_params(char str[MAX_LENGTH], int * n, int * length);
void format_string(char str[MAX_LENGTH], int n, int length);
int check_word_length(char str[MAX_LENGTH], int i);

int main(int n, char * argv[]) {
    
    if (n != 2 || check_argv(argv) == 0) {
        printf("n/a");
    } else {
        char str[MAX_LENGTH];
        int n;
        int length;
        if (get_params(str, &n, &length) == 0) {
            printf("n/a");
        } else {
            format_string(str, n, length);
        }
    }
    return 0;
}

int check_argv(char * argv[]) {
    int result = 0;
    char * arg = argv[1];
    printf("%s\n", arg);
    if (arg[0] == '-' && arg[1] == 'w' && arg[2] == '\0') {
        result = 1;
    }
    return result;
}

int get_params(char str[MAX_LENGTH], int * n, int * length) {
    int result = 0;
    char char_after_length;
    if (scanf("%i%c", n, &char_after_length) == 2 && *n > 0 &&
        (char_after_length == '\n' || char_after_length == ' ')) {
        char check;
        *length = 0;
        while (1) {
            scanf("%c", &check);
            if (check != '\n') {
                str[*length] = check;
                *length += 1;
            } else {
                break;
            }
        }
        if (*length <= MAX_LENGTH) {
            str[*length] = '\0';
            result = 1;
        }
    }
    return result;
}

void format_string(char str[MAX_LENGTH], int n, int length) {
    int word_length = 0;
    int symbs_left = n;
    for (int i = 0; i < length; i++) {
        if (word_length == 0) {
            if (i != 0) {
                if (symbs_left > 0) {
                    if (symbs_left == 1) {
                        printf("\n");
                        symbs_left = n;
                    } else {
                        printf(" ");
                        symbs_left--;
                    }
                } else {
                    printf("\n");
                    symbs_left = n;
                    i++;
                }
            }
            word_length = check_word_length(str, i);
        }
        if (symbs_left < word_length && word_length <= n) {
            printf("\n");
            symbs_left = n;
            while (word_length > 0 && str[i] != '\0') {
                printf("%c", str[i]);
                word_length--;
                symbs_left--;
                i++;
            }
            continue;
        }
        if (symbs_left < word_length && word_length > n) {
            while (word_length > 0 && str[i] != '\0') {
                if (symbs_left == 1) {
                    printf("-\n");
                    symbs_left = n;
                } else {
                    printf("%c", str[i]);
                    i++;
                    symbs_left--;
                    word_length--;
                }
            }
            continue;
        }
        if (symbs_left >= word_length) {
            while (word_length > 0 && str[i] != '\0') {
                printf("%c", str[i]);
                symbs_left--;
                word_length--;
                i++;
            }
        }
    }
}

int check_word_length(char str[MAX_LENGTH], int i) {
    int result = 0;
    for ( ; str[i] != ' ' && str[i] != '\0'; i++) {
        result++;
    }
    return result;
}