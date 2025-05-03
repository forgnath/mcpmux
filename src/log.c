#include <stdio.h>
#include "log.h"

static FILE *log_file = NULL;

int init_log(const char *filename) {
    log_file = fopen(filename, "a");
    return log_file != NULL;
}

void log_input(const char *msg) {
    if (log_file) fprintf(log_file, "[IN ] %s\n", msg);
}

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


