#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "./door_struct.h"
#include "./list.h"

#define DOORS_COUNT 15
#define MAX_ID_SEED 10000

void initialize_doors(struct door * doors);
void doors_show_status(struct door * doors);
void sort_doors_by_id(struct door * doors);
void close_all_doors(struct door * doors);
void print_list(struct node * root);

int main() {
    struct door doors[DOORS_COUNT];

    initialize_doors(doors);
    sort_doors_by_id(doors);
    close_all_doors(doors);
    doors_show_status(doors);
    return 0;
}

// Doors initialization function
// ATTENTION!!!
// DO NOT CHANGE!
void initialize_doors(struct door* doors) {
    srand(time(0));

    int seed = rand() % MAX_ID_SEED;
    for (int i = 0; i < DOORS_COUNT; i++) {
        doors[i].id = (i + seed) % DOORS_COUNT;
        doors[i].status = rand() % 2;
    }
}

void doors_show_status(struct door * doors) {
    int i;
    for (i = 0; i < DOORS_COUNT - 1; i++) {
        printf("%d, %d\n", doors[i].id, doors[i].status);
    }
    printf("%d, %d", doors[i].id, doors[i].status);
}

void sort_doors_by_id(struct door * doors) {
    for (int i = DOORS_COUNT - 1; i > 0; i--) {
        int max_index = 0;
        for (int j = 0; j <= i; j++) {
            if (doors[max_index].id < doors[j].id) {
                max_index = j;
            }
        }
        struct door temp = doors[i];
        doors[i] = doors[max_index];
        doors[max_index] = temp;
    }
}

void close_all_doors(struct door * doors) {
    for (int i = 0; i < DOORS_COUNT; i++) {
        doors[i].status = 0;
    }
}
