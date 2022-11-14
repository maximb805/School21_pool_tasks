#include <stdio.h>
#include <math.h>

void encode();

void decode();

int main(int n, char *arr[]) {
    if (n != 2) {
        printf("Wrong number of args!\n");
    } else {
        if (*arr[1] != '1' && *arr[1] != '0') {
            printf("Wrong argument! %c\n", *arr[1]);
        } else {
            char arg = *arr[1];
            if (arg == '1') {
                decode();
            } else {
                encode();
            }
        }
    }
}

void encode() {
    char f;
    for ( ; f != ; scanf("%x%c", &s, &f)) {
        printf("%x", s);
    }
}

void decode() {
    char * str;
    scanf("%[^\r\n]", str);
    printf("%s", *str);
    
}
