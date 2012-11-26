#ifndef RESOURCE_H
#define RESOURCE_H

// Dependencies
#include "identity.h"
#include "map.h"
#include "player.h"

//---Types---

typedef struct resource_t {
    // Resource internal data,
    // do not use them.
    IdStack *internal_idStack_;
    Map     *internal_map_;
    Player  *internal_playerList_;

    // Public data
    Identity mapId_;
    Identity *playerIdList_;
} Resource;



//---Functions---

Resource* newResource ();
bool      delResource (Resource *res);

#endif//RESOURCE_H
