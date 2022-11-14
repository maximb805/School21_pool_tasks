#include <stdlib.h>

#include "./queue.h"

struct queue * create_node();

struct queue * create_queue_node() {
    return (struct queue *) malloc(sizeof(struct queue));
}

struct queue * init_queue(char value) {
    struct queue * queue = create_queue_node();
    queue->value = value;
    queue->next = NULL;
    return queue;
}

struct queue * set(struct queue * queue, char value) {
    struct queue * new_node = NULL;
    struct queue * first = queue;
    if (queue != NULL) {
        new_node = create_queue_node();
        while (queue->next != NULL) {
            queue = queue->next;
        }
        new_node->next = NULL;
        new_node->value = value;
        queue->next = new_node;
    }
    return first;
}

void get(struct queue ** queue) {
    struct queue * get_elem = NULL;
    if (*queue != NULL) {
        get_elem = *queue;
        *queue = (*queue)->next;
        free(get_elem);
    }
}

void destroy_queue(struct queue * queue) {
    if (queue != NULL) {
        if (queue->next != NULL) {
            destroy_queue(queue->next);
        }
        free(queue);
    }
}