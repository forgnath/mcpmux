// mcpmux: C REPL prototype
// Phase 1 - Input echo loop
// Author: forgnath
// Date: 2025-05-02

// Initial input loop to prompt user, accept input up to 1024 bytes, exit on /quit
#include <stdio.h>
#include <string.h>
#include "shell_interface.h"
#include "log.h"
#include "command.h"
#include "utils.h"

int main(void) {
    
    char input[1024];

    init_log("sessions/world_state.txt");

    while (1) {
                
        print_prompt();

        if (!read_input(input, sizeof(input))) {
            break;
        }
        
        strip_whitespace(input);        
        log_input(input);

        if (strcmp(input, "/quit") == 0) {
            printf("Goodbye!\n");
            break;
        }

        handle_command(input); 
        log_output(input); // eventually GPT or parsed output

    }

    close_log();

    return 0;

}
