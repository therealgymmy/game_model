#ifndef PLAYER_H
#define PLAYER_H

// Dependencies
#include <stdbool.h>
#include <stdint.h>
#include "identity.h"
#include "map.h"

typedef struct player_t {
    uint32_t id_;
    Region **regions_;
} Player;

Player* newPlayer(IdStack* idStack);

bool delPlayer(Player *player);

#endif//PLAYER_H
