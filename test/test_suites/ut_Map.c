#include "../_include/ut_Map.h"

// Dependencies
#include "../_include/test_Log.h"

// Required by test
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

static TestStatus singleMapTest();
static TestStatus  doubleMapTest();



//---Implementations---
//
TestStatus run_map() {
    __enter;

    __checkpoint("IdStack initialization\n");
    if (!isIdStackCreated) {
        idStack = newIdStack();
        isIdStackCreated = true;
    }

    if (!singleMapTest()) {
        __return_status(FAIL);
    }
    if (!singleMapTest()) {
        __return_status(FAIL);
    }

    if (!doubleMapTest()) {
        __return_status(FAIL);
    }
    if (!doubleMapTest()) {
        __return_status(FAIL);
    }

    __checkpoint("IdStack cleanp\n");
    if (isIdStackCreated) {
        delIdStack(idStack);
        isIdStackCreated = false;
    }

    __return_status(PASS);
}

TestStatus singleMapTest() {
    __enter;

    Map* m1 = newMap(idStack);
    if (!m1) {
        __log_print("ERROR:  Function newMap() returned NULL pointer\n");
        __return_status(FAIL);
    }

    if (!m1->regions_ && m1->size_ > 0) {
        __log_print("ERROR:  The regions_ pointer is NULL prior to deleting the map\n");
       __return_status(FAIL);
    }
    if (m1->regions_ && m1->size_ == 0) {
        __log_print("ERROR:  The regions_ pointer is not NULL the size of the Map is 0\n");
        __return_status(FAIL);
    }
    if (!delMap(m1)) {
        __log_print("ERROR:  Function delMap() failed to free valid Map pointer\n");
        __return_status(FAIL);
    }
    m1 = NULL;
    if (delMap(m1)) {
        __log_print("ERROR:  Function delMap() attempted to free invalid Map pointer\n");
        __return_status(FAIL);
    }

    __return_status(PASS);
}

TestStatus doubleMapTest() {
    __enter;

    Map* m1 = NULL;
    Map* m2 = NULL;

    if (delMap(m1)) {
        __log_print("ERROR:  Function delMap() attempted to free invalid Map pointer\n");
        __return_status(FAIL);
    }

    m1 = newMap(idStack);
    if (!m1) {
        __log_print("ERROR:  Function newMap() returned NULL pointer\n");
        __return_status(FAIL);
    }
    m2 = newMap(idStack);
    if (!m2) {
        __log_print("ERROR:  Function newMap() returned NULL pointer\n");
        __return_status(FAIL);
    }

    if (!m1->regions_ && m1->size_ > 0) {
        __log_print("ERROR:  The regions_ pointer is NULL when the size of the Map is greater than 0\n");
        __return_status(FAIL);
    }
    if (m1->regions_ && m1->size_ == 0) {
        __log_print("ERROR:  The regions_ pointer is not NULL the size of the Map is 0\n");
        __return_status(FAIL);
    }
    if (!delMap(m1)) {
        __log_print("ERROR:  Function delMap() failed to free valid Map pointer\n");
        __return_status(FAIL);
    }
    m1 = NULL;
    if (delMap(m1)) {
        __log_print("ERROR:  Function delMap() attempted to free invalid Map pointer\n");
        __return_status(FAIL);
    }

    if (!m2->regions_ && m2->size_ > 0) {
        __log_print("ERROR:  The regions_ pointer is NULL when the size of the Map is greater than 0\n");
        __return_status(FAIL);
    }
    if (m2->regions_ && m2->size_ == 0) {
        __log_print("ERROR:  The regions_ pointer is not NULL the size of the Map is 0\n");
        __return_status(FAIL);
    }
    if (!delMap(m2)) {
        __log_print("ERROR:  Function delMap() failed to free valid Map pointer\n");
        __return_status(FAIL);
    }
    m2 = NULL;
    if (delMap(m2)) {
        __log_print("ERROR:  Function delMap() attempted to free invalid Map pointer\n");
        __return_status(FAIL);
    }

    __return_status(PASS);
}
