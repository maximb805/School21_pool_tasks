#include <stdarg.h>
#include <stdlib.h>
#include "documentation_module.h"

int validate(char* data) {
    int validation_result = !strcmp(data, Available_document);
    return validation_result;
}

int* check_available_documentation_module(
    int (*validate)(char*), char * document_count, ...) {
        char * format = document_count + 1;
        // va_list param_list;
        int arg = 1;
        int * args = &arg;
        // va_start(param_list, document_count);
        if (*document_count > 15) {
            *document_count = 15;
        }
        for (int i = 0; i < *document_count; i++) {
            validate(format + i);
            printf("%s ", format + i);
        }
        // va_end(param_list);
        return args;
}
