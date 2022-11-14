// Copyright 2022 team57
#include <stdio.h>

int printField(int * f, int * s,  int bi, int bj,
               int mv, int mh, int p1s, int p2s);

int move(int * f, int * s, int * bi, int * bj, int * mv, int * mh);

int moveBall(int f, int s, int * i, int * j, int * mv, int * mh);

int main() {
    int p1 = 0;
    int p2 = 0;
    int winner;
    int f = 13;
    int s = 13;
    while (p1 < 21 && p2 < 21) {
        int c = printField(&f, &s, 40, 13, 0, 0, p1, p2);
        if (c == 1) {
            p1++;
        } else {
            p2++;
        }
    }
    winner = p1 > p2 ? 1 : 2;
    printf("                                PLAYER %d WINS!!!"
           "                                \n", winner);
    return 0;
}

int printField(int * f, int * s, int bi, int bj,
               int mv, int mh, int p1s, int p2s) {
    int r = 0;
    while (r == 0) {
        if (p1s / 10 == 0 && p2s / 10 == 0) {
            printf("PLAYER 1 - %d                         "
            "                               %d - PLAYER 2\n", p1s, p2s);
        } else {
            if (p1s / 10 > 0 && p2s / 10 > 0) {
                printf("PLAYER 1 - %d                       "
                "                               %d - PLAYER 2\n", p1s, p2s);
            } else {
                    printf("PLAYER 1 - %d                        "
                    "                               %d - PLAYER 2\n", p1s, p2s);
            }
        }
        for (int j = 0; j < 25; j++) {
            int i = 0;
            if (j == 0 || j == 24) {
                printf("#");
                i++;
            } else {
                printf("|");
                i++;
            }
            for ( ; i < 80; i++) {
                if (j == 0 || j == 24) {
                printf("#");
                } else {
                    if (i == 79) {
                        printf("|");
                    } else {
                        if ((i == 1 && (j >= *f - 1 && j <= *f + 1))
                            || (i == 78 && (j >= *s - 1 && j <= *s + 1))) {
                            printf("I");
                        } else {
                            if (i == bi && j == bj) {
                                printf("o");
                            } else {
                                printf(" ");
                            }
                        }
                    }
                }
            }
            printf("\n");
        }
        r = move(f, s, &bi, &bj, &mv, &mh);
        printf("\033[0;0f");
    }
    return r;
}

int move(int * f, int * s, int * bi, int * bj, int * mv, int * mh) {
    char c;
    scanf("%c", &c);
    if (c == 'k') {
        *s = *s == 2 ? *s : *s - 1;
    }
    if (c == 'm') {
        *s = *s == 22 ? *s : *s + 1;
    }
    if (c == 'a') {
        *f = *f == 2 ? *f : *f - 1;
    }
    if (c == 'z') {
        *f = *f == 22 ? *f : *f + 1;
    }
    if (c != '\n') {
        return moveBall(*f, *s, bi, bj, mv, mh);
    } else {
        return 0;
    }
}

int moveBall(int f, int s, int * i, int * j, int * mv, int * mh) {
    if (*i == 0) {
        return 2;
    }
    if (*i == 79) {
        return 1;
    }
    *mh = (*i == 2 && (*j >= (f - 1) && *j <= (f + 1))) ? 0 : *mh;
    *mh = (*i == 77 && (*j >= (s - 1) && *j <= (s + 1))) ? 1 : *mh;
    *mv = (*j == 1 && *mv == 1) ? 0 : *mv;
    *mv = (*j == 23 && *mv  == 0) ? 1 : *mv;
    if (*mh == 0) {
        *i = *i + 1;
    } else {
        *i = *i - 1;
    }
    if (*mv == 0) {
        *j = *j + 1;
    } else {
        *j = *j - 1;
    }
    return 0;
}
