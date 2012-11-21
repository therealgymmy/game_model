#ifndef MAP_H
#define MAP_H

// Dependencies
#include <stdint>
#include "player.h"

typedef struct position_t {
    uint32_t x_;
    uint32_t y_;
} Position;

typedef struct troop_t {
    uint32_t count_;
} Troop;

typedef struct region_t {
    Player  *owner_;
    Position pos_;
    Troop    troop_;
} Region;

typedef struct map_t {
    Region **regions_;
} Map;

Map createMap ();

#endif//MAP_H
