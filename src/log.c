#include <stdio.h>
#include "log.h"

// Sets up log file; placeholder for local file presently
static FILE *log_file = NULL;

// Sets up file for apending based on placeholder, returns true
int init_log(const char *filename) {
    log_file = fopen(filename, "a");
    return log_file != NULL;
}

// Prints user input with a prefix to file based on init_log setup if true
void log_input(const char *msg) {
    if (log_file) fprintf(log_file, "[IN ] %s\n", msg);
}

// Prints output with a prefix to file based on init_log setup if true
void log_output(const char *msg) {
    if (log_file) fprintf(log_file, "[OUT ] %s\n",msg);
}

void close_log(void) {
    if (log_file) {
        fflush(log_file);
        fclose(log_file);
        log_file = NULL;
    }
}


