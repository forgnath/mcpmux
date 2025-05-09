#include <string.h>
#include <ctype.h>
#include "utils.h"

// Parse checker for strings to use with command input structure
// checks with strncmp match between a given char array/command
// and returns true if no match found giving hand_command in 
// command.c a means to check for input commands
int starts_with(const char *str, const char *prefix) {
    return strncmp(str, prefix, strlen(prefix)) == 0;
}

//takes in a given character array and searches through its length starting
//at the end to one by one look for a space using the isspace() function
//from string.h and replace that array position with a disappearing null value
void strip_whitespace(char *str) {
    size_t len = strlen(str);
    while (len > 0 && isspace((unsigned char)str[len - 1])) {
        str[--len] = '\0';
    }
}
