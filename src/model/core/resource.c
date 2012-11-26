#include "../_include/resource.h"

// Dependencies
#include <malloc.h>

//---Prototypes---

static Player* newPlayerList ();
static bool    delPlayerList (Player *list);

static Identity* newPlayerIdList ();
static bool      delPlayerIdList (Identity *list);

static Map* generateMap ();



//---Implementations---

Resource* newResource ()
{
    Resource *res = malloc(sizeof(Resource));

    if (!(res->internal_idStack_ = newIdStack())) {
        return NULL;
    }

    if (!(res->internal_map_ = generateMap())) {
        return NULL;
    }
    res->mapId_ = res->internal_map_->id_;

    if (!(res->internal_playerList_ = newPlayerList())) {
        return NULL;
    }
    if (!(res->playerIdList_ = newPlayerIdList())) {
        return NULL;
    }

    return res;
}

bool delResource (Resource *res)
{
    if (!res ||
        !delIdStack(res->internal_idStack_) ||
        !delMap(res->internal_map_) ||
        !delPlayerList(res->internal_playerList_) ||
        !delPlayerIdList(res->playerIdList_)) {
        return false;
    }

    return true;
}
