#include <stdio.h>
#include "./stack.h"

void stack_test();
void print_stack();

int main() {
    struct stack * stack = init(9);
    push(&stack, 5);
    push(&stack, 4);
    push(&stack, 3);
    push(&stack, 2);
    push(&stack, 1);
    push(&stack, 6);
    push(&stack, 7);
    // expected_result: "7 6 1 2 3 4 5 9"
    char * exp_res = "76123459";
    stack_test(&stack, exp_res);
    printf("\n");

    struct stack * stack1;
    push(&stack1, 10);
    // expected result: ""
    exp_res = "76123459";
    stack_test(&stack1, exp_res);
    pop(&stack);
    pop(&stack1);
    return 0;
}

void stack_test(struct stack ** stack, char * expected_result) {
    int result = 1;
    int i = 0;
    while (*stack != NULL) {
        if ((*stack)->value != expected_result[i] - '0') {
            result = 0;
            break;
        }
        pop(stack);
        i++;
    }
    if (result) {
        printf("SUCCESS");
    } else {
        printf("FAIL");
    }
}

void print_stack(struct stack * stack) {
    while (stack != NULL) {
        printf("%d\n", stack->value);
        stack = stack->next;
    }
}
