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
#include "world.h"

// mcpmux operational roles
typedef enum {
    ROLE_UNSET,
    ROLE_SERVER,
    ROLE_CLIENT
} McpmuxRole;

void run_client_loop(void);
void run_server_loop(void);

int main(int argc, char *argv[]) {
    // unsets the default role; user specifies
    McpmuxRole role = ROLE_UNSET;
    
    // parsing CLI arguments for --client and --server roles
    if (argc > 1) {
        if (strcmp(argv[1], "--client") == 0) {
            role = ROLE_CLIENT;
        } else if (strcmp(argv[1], "--server") == 0) {
            role = ROLE_SERVER;
        } else {
            printf("Usage: mcpmux --server | --client\n");
            return 1;
        }
    } else {
        printf("Usage: mcpmux --server | --client\n");
        return 1;
    }

    // Launch loop based on role
    
    if (role == ROLE_CLIENT) {
        run_client_loop();
    } else if (role == ROLE_SERVER) {
        run_server_loop();
    }

    return 0;
}

// Client REPL loop (standard I/O and prompt)
void run_client_loop(void) {

    char input[1024];
    
    init_log("sessions/world_state.txt");
    init_world();
  
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

        const char *response = handle_command(input);
        printf("%s\n", response); 
        log_output(response); // eventually GPT or parsed output
    }

    close_log();
}

// Server stub (eventual pipe/socket loop)
void run_server_loop(void) {
    printf("mcpmux server mode active\n");
    printf("GPT routing not yet implimented\n");
}

