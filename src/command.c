#include <stdio.h>
#include <string.h>
#include "command.h"
#include "utils.h"

const char *handle_command(const char *input) {
    if (starts_with(input, "/help")) {
        return "Available Commands: /help /look /quit\n";
    } else if (starts_with(input, "/look")) {
        return "Looking around, you notice there is very little here of note\n";
    } else {
        static char unknown[256];
        snprintf(unknown, sizeof(unknown), "Unknown Command: %s", input);
        return unknown;
    }
}
