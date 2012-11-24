#include "../_include/player.h"

// Dependencies
#include <malloc.h>

//---Prototypes---

static bool initPlayer(Player* player, IdStack* idStack);



//---Implementations---

Player* newPlayer(IdStack* idStack) {
    Player* player = malloc(sizeof(Player));

    if (!player) {
        return NULL;
    }

    if (!initPlayer(player, idStack)) {
        return NULL;
    }

    return player;
}

bool delPlayer(Player *player) {
    if (player) {
        free(player);
    } else {
        return false;
    }
    return true;
}

bool initPlayer(Player* player, IdStack* idStack) {
    Identity id;

    if ((id = newId(idStack)) == NULL_ID) {
        return false;
    }

    player->id_ = id;
    player->regions_ = NULL;
    return true;
}
