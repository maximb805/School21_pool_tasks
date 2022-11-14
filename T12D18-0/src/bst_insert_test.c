#include <stdio.h>
#include "./bst.h"

void test_bstree_insert();
void print_tree(t_btree * root);

int main() {
    test_bstree_insert();
    return 0;
}

void test_bstree_insert() {
    t_btree * root = bstree_create_node(5);
    bstree_insert(root, 9, compare_items);
    bstree_insert(root, 8, compare_items);
    bstree_insert(root, -17, compare_items);
    bstree_insert(root, -15, compare_items);
    bstree_insert(root, -1, compare_items);
    bstree_insert(root, 17, compare_items);
    bstree_insert(root, 6, compare_items);
    char * expected_result = "-17 -15 -1 5 6 8 9 17\n";
    printf("%s", expected_result);
    print_tree(root);
    destroy(root);
}

void print_tree(t_btree * root) {
    if (root != NULL) {
        print_tree(root->left);
        printf("%d ", root->item);
        print_tree(root->right);
    }
}
