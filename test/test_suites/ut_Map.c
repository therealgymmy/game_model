#include "../_include/ut_Map.h"

// Dependencies
#include <stdio.h>
#include <stdbool.h>
#include "../../src/model/_include/map.h"

UnitTestMap ut_Map = {
    .base_ = {
        .type_ = UT_MAP,
        .run_  = &run_map
    }
};

static
IdStack* idStack;

static
bool isIdStackCreated = false;

//---Prototypes---

static bool singleMapTest();
static bool doubleMapTest();



//---Implementations---
//
TestStatus run_map() {
    if (!isIdStackCreated) {
        idStack = newIdStack();
        isIdStackCreated = true;
    }

    if (!singleMapTest()) {
        printf("Failed singleMapTest first try\n");
        return FAIL;
    }
    if (!singleMapTest()) {
        printf("Failed singleMapTest second try\n");
        return FAIL;
    }

    if (!doubleMapTest()) {
        printf("Failed doubleMapTest first try\n");
        return FAIL;
    }
    if (!doubleMapTest()) {
        printf("Failed doubleMapTest second try\n");
        return FAIL;
    }

    if (isIdStackCreated) {
        delIdStack(idStack);
        isIdStackCreated = false;
    }

    return PASS;
}

bool singleMapTest() {
    Map* m1 = newMap(idStack);
    if (!m1) {
        printf("ERROR:  Function newMap() returned NULL pointer\n");
        return false;
    }

    if (!m1->regions_) {
        printf("ERROR:  The regions_ pointer is NULL prior to deleting the map\n");
    }
    if (m1->regions_ && m1->size_ == 0) {
        printf("ERROR:  The regions_ pointer is not NULL the size of the Map is 0\n");
    }
    if (!delMap(m1)) {
        printf("ERROR:  Function delMap() failed to free valid Map pointer\n");
        return false;
    }
    m1 = NULL;
    if (delMap(m1)) {
        printf("ERROR:  Function delMap() attempted to free invalid Map pointer\n");
        return false;
    }

    return true;
}

bool doubleMapTest() {
    Map* m1 = NULL;
    Map* m2 = NULL;

    if (delMap(m1)) {
        printf("ERROR:  Function delMap() attempted to free invalid Map pointer\n");
        return false;
    }

    m1 = newMap(idStack);
    if (!m1) {
        printf("ERROR:  Function newMap() returned NULL pointer\n");
        return false;
    }
    m2 = newMap(idStack);
    if (!m2) {
        printf("ERROR:  Function newMap() returned NULL pointer\n");
        return false;
    }

    if (!m1->regions_ && m1->size_ > 0) {
        printf("ERROR:  The regions_ pointer is NULL when the size of the Map is greater than 0\n");
    }
    if (m1->regions_ && m1->size_ == 0) {
        printf("ERROR:  The regions_ pointer is not NULL the size of the Map is 0\n");
    }
    if (!delMap(m1)) {
        printf("ERROR:  Function delMap() failed to free valid Map pointer\n");
        return false;
    }
    m1 = NULL;
    if (delMap(m1)) {
        printf("ERROR:  Function delMap() attempted to free invalid Map pointer\n");
        return false;
    }

    if (!m2->regions_ & m2->size_ > 0) {
        printf("ERROR:  The regions_ pointer is NULL when the size of the Map is greater than 0\n");
    }
    if (m2->regions_ && m2->size_ == 0) {
        printf("ERROR:  The regions_ pointer is not NULL the size of the Map is 0\n");
    }
    if (!delMap(m2)) {
        printf("ERROR:  Function delMap() failed to free valid Map pointer\n");
        return false;
    }
    m2 = NULL;
    if (delMap(m2)) {
        printf("ERROR:  Function delMap() attempted to free invalid Map pointer\n");
        return false;
    }

    return true;
}
