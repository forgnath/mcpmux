#include <stdio.h>
#include <string.h>
#include "command.h"
#include "utils.h"

void handle_command(const char *input) {
    if (starts_with(input, "/help")) {
        printf("Available Commands: /help /look /quit\n");
    } else if (starts_with(input, "/look")) {
        printf("Looking around, you notice there is very little here of note\n");
    } else {
        printf("Unknown Command: %s\n", input);
    }
}
