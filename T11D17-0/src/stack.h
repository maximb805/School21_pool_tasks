#ifndef STACK_H
#define STACK_H

struct stack {
    int value;
    struct stack * next;
};

struct stack * init(int value);
struct stack * push(struct stack ** stack, int value);
void pop(struct stack ** stack);
void destroy(struct stack * stack);

#endif