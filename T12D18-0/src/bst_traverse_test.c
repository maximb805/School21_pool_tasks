#include <stdio.h>
#include "./bst.h"

void test_bstree_traverse();
void print_tree(t_btree * root);

int main() {
    test_bstree_traverse();
    return 0;
}

void test_bstree_traverse() {
    t_btree * root = bstree_create_node(5);
    bstree_insert(root, 9, compare_items);
    bstree_insert(root, 8, compare_items);
    bstree_insert(root, -17, compare_items);
    bstree_insert(root, -15, compare_items);
    bstree_insert(root, -1, compare_items);
    bstree_insert(root, 17, compare_items);
    bstree_insert(root, 6, compare_items);

    bstree_apply_infix(root, print_item);
    printf("\n");
    bstree_apply_prefix(root, print_item);
    printf("\n");
    bstree_apply_postfix(root, print_item);
    destroy(root);
}
