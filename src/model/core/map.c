#include "../_include/map.h"

// Dependencies
#include <malloc.h>

//---Prototypes---
static bool initMap (Map *map, IdStack *stack);

Map* newMap (IdStack *stack)
{
    Map *map = malloc(sizeof(Map));

    if (!map) {
        return NULL;
    }

    if (!initMap(map, stack)) {
        return NULL;
    }

    return map;
}

bool delMap (Map *map)
{
    if (map) {
        free(map);
    }
    else {
        return false;
    }

    return true;
}

bool initMap (Map *map, IdStack *stack)
{
    uint32_t id;

    if (newId(stack) == NULL_ID) {
        return false;
    }

    map->id_      = id;
    map->size_    = 0;
    map->stack_   = stack;
    map->regions_ = NULL;

    return true;
}
