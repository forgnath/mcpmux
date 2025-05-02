#include <stdio.h>
#include <string.h>
#include "shell_interface.h"

void print_prompt(void) {
    printf("> ");
    fflush(stdout);
}

int read_input(char *buffer, size_t size) {
    if (fgets(buffer, size, stdin) == NULL) {
        return 0; 
    }

    size_t len = strlen(buffer);
    if (len > 0 && buffer[len - 1] == '\n') {
        buffer[len - 1] = '\0';
    }

    return 1;

}
