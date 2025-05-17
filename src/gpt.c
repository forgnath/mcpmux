#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include "gpt.h"

// Function to run simulated gpt stub script and capture output

int run_gpt_stub(const char *input, char *output, size_t size) {
    // Puts command string together
    char cmd[1024];
    snprintf(cmd, sizeof(cmd), "python3 python/gpt_stub.py \"%s\"", input);

    // Opens pipe to subprocess
    FILE *fp = popen(cmd, "r");
    if (fp == NULL) {
        snprintf(output, size, "[GPT ERROR] Could not run GPT subprocess.");
        return 1;
    }

    // Read first line of output
    if (fgets(output, size, fp) == NULL) {
        snprintf(output, size, "[GPT ERROR] No response received.");
        pclose(fp);
        return 2;
    }

    // Remove trailing new line
    size_t len = strlen(output);
    if (len > 0 && output [len - 1] == '\n') {
        output[len - 1] = '\0';
    }

    pclose(fp);
    return 0;
}
