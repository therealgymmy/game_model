#include "../_include/map.h"

static bool initMap (Map *map);

Map createMap ()
{
    Map map;
    if (initMap(&map)) {
        return map;
    }
    else {
    }
}
