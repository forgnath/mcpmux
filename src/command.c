#include <stdio.h>
#include <string.h>
#include "command.h"
#include "utils.h"
#include "world.h"

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
