#include "../_include/map.h"

// Dependencies
#include <malloc.h>

//---Macro---
#define DEFAULT_ID_STORE_SIZE     20
#define DEFAULT_ID_STORE_ID_START 0
#define MAX_ID_STORE_ID_COUNT     (UINT32_MAX / 2)
#define NULL_ID                   0

//---Types---
typedef struct idstore_T {
    uint32_t capacity_;
    uint32_t size_;
    uint32_t curId_;
    uint32_t *idList_;
} IdStore;

//---Prototypes---
static bool initIdStore (IdStore *idStore);
static bool initMap     (Map *map);
static bool incIdStore  (IdStore *idStore);
static bool newId       (IdStore *idStore, uint32_t *id);

//---Global---
static IdStore idStack;         // Global id storage.

bool initMapProc ()
// Initialize resources needed for managing maps.
{
    if (!initIdStore(&idStack)) {
        return false;
    }

    return true;
}

Map* newMap ()
{
    Map *map = malloc(sizeof(Map));

    if (!map) {
        return NULL;
    }

    if (!initMap(map)) {
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

bool initMap (Map *map)
{
    uint32_t id;

    if (!newId(&idStack, &id)) {
        return false;
    }

    map->id_ = id;
    map->size_ = 0;
    map->regions_ = NULL;

    return true;
}

bool initIdStore (IdStore *idStore)
{
    IdStore new;

    new.capacity_ = DEFAULT_ID_STORE_SIZE;
    new.size_     = 0;
    new.curId_    = DEFAULT_ID_STORE_ID_START;
    new.idList_   = malloc(sizeof(uint32_t) * DEFAULT_ID_STORE_SIZE);

    if (!new.idList_) {
        return false;
    }

    *idStore = new;

    return true;
}

bool incIdStore (IdStore *idStore)
{
    uint32_t newCapacity = idStore->capacity_ * 2;

    uint32_t *newList = realloc(idStore->idList_,
                                sizeof(uint32_t) * newCapacity);

    if (!newList) {
        return false;
    }

    idStore->capacity_ = newCapacity;
    idStore->idList_   = newList;
    return false;
}

bool newId (IdStore *idStore, uint32_t *id)
{
    if (idStore->curId_ >= MAX_ID_STORE_ID_COUNT) {
        return false;
    }

    if (idStore->size_ >= idStore->capacity_) {
        if (!incIdStore(idStore)) {
            return false;
        }
    }

    uint32_t size  = ++(idStore->size_);
    uint32_t newId = ++(idStore->curId_);
    idStore->idList_[size - 1] = newId;
    *id = newId;

    return true;
}
