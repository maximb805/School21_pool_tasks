#include <stdlib.h>

#include "./list.h"

struct node * create_node();

struct node * create_node() {
    return (struct node *) malloc(sizeof(struct node));
}

struct node * init(struct door * door) {
    struct node * root = create_node();
    root->door = *door;
    root->next = NULL;
    return root;
}

struct node * add_door(struct node * elem, struct door * door) {
    struct node * new_node = NULL;
    if (elem != NULL) {
        new_node = create_node();
        new_node->door = *door;
        new_node->next = elem->next;
        elem->next = new_node;
    }
    return new_node;
}

struct node * find_door(int door_id, struct node * root) {
    while (root != NULL && root->door.id != door_id) {
        root = root->next;
    }
    return root;
}

struct node * remove_door(struct node * elem, struct node * root) {
    struct node * real_root = root;
    struct node * prev_node = NULL;
    while (root != NULL  && root != elem) {
        prev_node = root;
        root = root->next;
    }
    if (root != NULL) {
        if (root == real_root) {
            real_root = root->next;
            free(root);
        } else {
            prev_node->next = root->next;
            free(root);
        }
    } else {
        if (prev_node != NULL) {
            free(prev_node);
        }
    }
    return real_root;
}

void destroy(struct node * root) {
    if (root != NULL) {
        if (root->next != NULL) {
            destroy(root->next);
        }
        free(root);
    }
}
