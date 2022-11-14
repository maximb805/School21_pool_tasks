#ifndef QUEUE_H
#define QUEUE_H

struct queue {
    int value;
    struct queue * next;
};

struct queue * init_queue(char value);
struct queue * set(struct queue * queue, char value);
void get(struct queue ** queue);
void destroy_queue(struct queue * queue);
#endif