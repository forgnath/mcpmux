#include "world.h"

//just a prototype single room structure representing a current world state
static Room current_room;

// initializes the name and description fields of the current_room structure 
void init_world(void) {
    current_room.name = "Center of Town";
    current_room.description = "A small town square with a well";
}

// returns descriptions and names for current room for use in command output 
const char *describe_current_room(void) {
    return current_room.description;
}

const char *get_current_room_name(void) {
    return current_room.name;
}
