#ifndef UT_MAP_H
#define UT_MAP_H

#include "test_Base.h"

typedef struct unittestmap_t {
    // Unit Test Info
    UnitTestBase base_;

} UnitTestMap;

extern UnitTestMap ut_Map;

TestStatus run_map();

#endif//UT_MAP_H
