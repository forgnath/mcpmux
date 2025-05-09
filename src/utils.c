#include <string.h>
#include <ctype.h>
#include "utils.h"

// Checks if given string starts with specified prefix
// Uses strncmp to compare string start with prefix
// Returns true if match, false otherwise
int starts_with(const char *str, const char *prefix) {
    return strncmp(str, prefix, strlen(prefix)) == 0;
}

// Removes trailing whitespace from a string
// Iterates through string from end replacing any spaces with null terminator
void strip_whitespace(char *str) {
    size_t len = strlen(str);
    while (len > 0 && isspace((unsigned char)str[len - 1])) {
        str[--len] = '\0';
    }
}
