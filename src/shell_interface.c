#include <stdio.h>
#include <string.h>
#include "shell_interface.h"

// Basic console prompt
void print_prompt(void) {
    printf("> ");
    fflush(stdout);
}

// Wrapper function for input read succes or fail via EOF/lack of input
// and return success otherwise
int read_input(char *buffer, size_t size) {
    if (fgets(buffer, size, stdin) == NULL) {
        return 0; 
    }
// If there is input, strip the newline character by replacing with a disappearing null 
    size_t len = strlen(buffer);
    if (len > 0 && buffer[len - 1] == '\n') {
        buffer[len - 1] = '\0';
    }

    return 1;

}
