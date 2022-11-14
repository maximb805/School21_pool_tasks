#include <stdio.h>
#include "./bst.h"

void test_bstree_create_node(int item);

int main() {
    test_bstree_create_node(5);
    test_bstree_create_node(8);
    test_bstree_create_node(-176);
    return 0;
}

void test_bstree_create_node(int item) {
    t_btree * node = bstree_create_node(item);
    if (node->item == item && node->left == NULL && node->right == NULL) {
        printf("SUCCESS\n");
    } else {
        printf("FAIL\n");
    }
    destroy(node);
}
