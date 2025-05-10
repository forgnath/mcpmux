// mcpmux: C REPL prototype
// Phase 1 - Input echo loop
// Author: forgnath
// Date: 2025-05-02

// Initial input loop to prompt user, accept input up to 1024 bytes, exit on /quit
#include <stdio.h>
#include <string.h>
#include "shell_interface.h"
#include <fcntl.h> // open()
#include <unistd.h> // read(), write(), close()
#include <sys/stat.h> // mkfifo()
#include <errno.h>

#include "log.h"
#include "command.h"
#include "utils.h"
#include "world.h"

#define PIPE_PATH "/tmp/mcpmux_pipe"

// mcpmux operational roles
typedef enum {
    ROLE_UNSET,
    ROLE_SERVER,
    ROLE_CLIENT
} McpmuxRole;

// Forward declarations for server operational role loops
void run_client_loop(void);
void run_server_loop(void);

// entry point checks for CLI args befor initializing mcpmux operational mode
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

// Client REPL loop 
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
        
        // If string starts with "/rp", send to server via named ppe
        if (starts_with(input, "/rp")) {
            int fd = open(PIPE_PATH, O_WRONLY);
            if (fd == -1) {
                perror("open pipe");
            } else {
                const char *msg = input + 4; // strip "/rp "
                write(fd, msg, strlen(msg));
                close(fd);
            }
            continue; // Dont echo or log locally
        }
        
        // All other commands handled normally
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

// Server loop - reads /rp messages from pipe
void run_server_loop(void) {
    // Create FIFO if none exists
    if (mkfifo(PIPE_PATH, 0666) == -1 && errno != EEXIST) {
        perror("mkfifo");
        return;
    }

    printf("[mcpmux] Server running. Waitin for /rp messages ...\n");

    char buffer[1024];

    while (1) {
        int fd = open(PIPE_PATH, O_RDONLY);
        if (fd == -1) {
            perror("open pipe");
            break;
        }

        ssize_t bytes_read = read(fd, buffer, sizeof(buffer) - 1);
        if (bytes_read > 0) {
            buffer[bytes_read] = '\0'; // null terminator
            printf("[CLIENT] %s\n", buffer); // Print client message
        }

        close(fd);
    }
}

