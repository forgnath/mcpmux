#include <stdio.h>
#include <string.h>
#include "command.h"
#include "utils.h"
#include "world.h"

// Parse user input commands or return a string indicating unknown
// to ensure output and output logging includes all output not just user input
const char *handle_command(const char *input) {
    if (starts_with(input, "/help")) {
        return "Available Commands: /help /look /where /quit\n";
    } else if (starts_with(input, "/look")) {
        return describe_current_room();
    } else if (starts_with(input, "/where")) {
        return get_current_room_name();
    } else {
        static char unknown[256];
        snprintf(unknown, sizeof(unknown), "Unknown Command: %s", input);
        return unknown;
    }
}
