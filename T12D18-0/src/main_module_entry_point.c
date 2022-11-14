#include <stdio.h>

#include "print_module.h"
#include "./documentation_module.h"

int main() {
    print_log(print_char, Module_load_success_message);

    // int * availability_mask = check_available_documentation_module(
    //   validate, &dc, Documents);

    // printf("%d", *availability_mask);

    // Output availability for each document....
    return 0;
}
