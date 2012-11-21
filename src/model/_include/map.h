#ifndef MAP_H
#define MAP_H

// Dependencies
#include <stdbool.h>
#include <stdint.h>
#include "player.h"

//---Types---

typedef struct position_t {
    uint32_t x_;
    uint32_t y_;
} Position;

typedef struct troop_t {
    uint32_t count_;
} Troop;

typedef struct region_t {
    Player   *owner_;
    Position pos_;
    Troop    troop_;
} Region;

typedef struct map_t {
    uint32_t id_;
    uint32_t size_;
    Region   *regions_;
} Map;


//---Functions---

// Initialize all resources needed to use map.
// Should be called first and only once before using any other function here.
bool initMapProc ();

Map* newMap ();

bool delMap (Map *map);

bool populateMap (Map *map, uint32_t size);

#endif//MAP_H
