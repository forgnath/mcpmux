#include "world.h"

//just a prototype single room

static Room current_room;

void init_world(void) {
    current_room.name = "Center of Town";
    current_room.description = "A small town square with a well";
}

const char *describe_current_room(void) {
    return current_room.description;
}

const char *get_current_room_name(void) {
    return current_room.name;
}
