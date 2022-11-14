#include <stdio.h>
#include "./list.h"

void init_doors(struct door * doors);
void test_add_door(struct node * root, char * result_str);
void test_remove_door(struct node * root, char * result_str);
void print_list(struct node * root);

int main() {
    struct door doors[15];
    init_doors(doors);

    struct node * list = init(&doors[5]);
    struct node * node1 = add_door(list, &doors[1]);
    struct node * node2 = add_door(node1, &doors[2]);
    struct node * node3 = add_door(list, &doors[3]);
    struct node * node4 = add_door(node2, &doors[4]);
    struct node * node0 = add_door(list, &doors[0]);
    // expected id_order after all additions: 5 0 3 1 2 4
    char * result_str = "503124";
    test_add_door(list, result_str);
    printf("\n");
    list = remove_door(node1, list);
    list = remove_door(node3, list);
    list = remove_door(node0, list);
    // expected id_order after 3 deletions: 5 2 4
    result_str = "524";
    test_remove_door(list, result_str);
    printf("\n");
    list = remove_door(list, list);
    list = remove_door(node4, list);
    list = remove_door(list, list);
    // expected id_order after 3 deletions:
    result_str = "";
    test_remove_door(list, result_str);
    return 0;
}

void test_add_door(struct node * root, char * result_str) {
    int result = 1;
    int i = 0;
    while (root != NULL) {
        if (root->door.id != result_str[i] - '0') {
            result = 0;
            break;
        }
        root = root->next;
        i++;
    }
    if (result) {
        printf("SUCCESS");
    } else {
        printf("FAIL");
    }
}

void test_remove_door(struct node * root, char * result_str) {
     int result = 1;
    int i = 0;
    while (root != NULL) {
        if (root->door.id != result_str[i] - '0') {
            result = 0;
            break;
        }
        root = root->next;
        i++;
    }
    if (result) {
        printf("SUCCESS");
    } else {
        printf("FAIL");
    }
}

void init_doors(struct door * doors) {
    for (int i = 0; i < 15; i++) {
        doors[i].id = i;
        doors[i].status = 1;
    }
}
