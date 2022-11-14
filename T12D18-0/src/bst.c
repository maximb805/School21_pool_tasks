#include <stdlib.h>
#include <stdio.h>
#include "./bst.h"

t_btree *bstree_create_node(int item) {
    t_btree * new_node = (t_btree *)malloc(sizeof(t_btree));
    new_node->left = NULL;
    new_node->right = NULL;
    new_node->item = item;
    return new_node;
}

int compare_items(int this_item, int new_item) {
    return this_item > new_item ? 0 : 1;
}

void bstree_insert(t_btree *root, int item, int(*cmpf)(int, int)) {
    if (root != NULL) {
        if (cmpf(root->item, item)) {
            if (root->right != NULL) {
                root = root->right;
                bstree_insert(root, item, cmpf);
            } else {
                t_btree * new_node = bstree_create_node(item);
                root->right = new_node;
            }
        } else {
            if (root->left != NULL) {
                root = root->left;
                bstree_insert(root, item, cmpf);
            } else {
                t_btree * new_node = bstree_create_node(item);
                root->left = new_node;
            }
        }
    }
}

void bstree_apply_infix(t_btree *root, void (*applyf)(int)) {
    if (root != NULL) {
        bstree_apply_infix(root->left, applyf);
        applyf(root->item);
        bstree_apply_infix(root->right, applyf);
    }
}

void bstree_apply_prefix(t_btree *root, void (*applyf)(int)) {
    if (root != NULL) {
        applyf(root->item);
        bstree_apply_prefix(root->left, applyf);
        bstree_apply_prefix(root->right, applyf);
    }
}

void bstree_apply_postfix(t_btree *root, void (*applyf)(int)) {
    if (root != NULL) {
        bstree_apply_postfix(root->right, applyf);
        applyf(root->item);
        bstree_apply_postfix(root->left, applyf);
    }
}

void print_item(int item) {
    printf("%d ", item);
}

void destroy(t_btree *root) {
    if (root != NULL) {
        destroy(root->left);
        t_btree * tmp = root;
        free(root);
        destroy(tmp->right);
    }
}
