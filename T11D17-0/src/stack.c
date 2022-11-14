#include <stdlib.h>

#include "./stack.h"

struct stack * create_node();

struct stack * create_node() {
    return (struct stack *) malloc(sizeof(struct stack));
}

struct stack * init(int value) {
    struct stack * stack = create_node();
    stack->value = value;
    stack->next = NULL;
    return stack;
}

struct stack * push(struct stack ** stack, int value) {
    struct stack * new_node = NULL;
    if (*stack != NULL) {
        new_node = create_node();
        new_node->next = *stack;
        new_node->value = value;
        *stack = new_node;
    }
    return *stack;
}

void pop(struct stack ** stack) {
    struct stack * pop_elem = NULL;
    if (*stack != NULL) {
        pop_elem = *stack;
        *stack = (*stack)->next;
        free(pop_elem);
    }
}

void destroy(struct stack * stack) {
    if (stack != NULL) {
        if (stack->next != NULL) {
            destroy(stack->next);
        }
        free(stack);
    }
}
