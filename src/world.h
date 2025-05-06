#ifndef WORLD_H
#define WORLD_H

//room structure

typedef struct {
    const char *name;
    const char *description;
} Room;

void init_world(void);
const char *describe_current_room(void);
const char *get_current_room_name(void);

#endif
