#include "../_include/ut_IdStack.h"

// Dependencies
#include <stdio.h>
#include <stdbool.h>
#include "../../src/model/_include/identity.h"

UnitTestIdStack ut_IdStack = {
    .base_ = {
        .type_ = UT_ID_STACK,
        .run_  = &run_idstack
    }
};

//---Prototypes---

static bool singleIdStackTest();
static bool doubleIdStackTest();



//---Implementations---
//
TestStatus run_idstack() {
    if (!singleIdStackTest()) {
        printf("Failed singleIdStackTest first try\n");
        return FAIL;
    }
    if (!singleIdStackTest()) {
        printf("Failed singleIdStackTest second try\n");
        return FAIL;
    }

    if (!doubleIdStackTest()) {
        printf("Failed doubleIdStackTest first try\n");
        return FAIL;
    }
    if (!doubleIdStackTest()) {
        printf("Failed doubleIdStackTest second try\n");
        return FAIL;
    }

    return PASS;
}

bool singleIdStackTest() {
    Identity id;
    IdStack* s1 = newIdStack();
    if (!s1) {
        printf("ERROR:  Function newIdStack() returned NULL pointer\n");
        return false;
    }
    if (!s1->idList_) {
        printf("ERROR:  Function newIdStack() didn't initialize the idList_ pointer\n");
    }

    for (int i = 0; i < MAX_ID_STACK_ID_COUNT; i++) {
        id = newId(s1);
        if (id == NULL_ID) {
            printf("ERROR:  Function newId() returned null id when still available ids\n");
        }
        if (!s1->idList_) {
            printf("ERROR:  Function newId() didn't properly reallocate the idList_ pointer\n");
        }
    }
    id = newId(s1);
    if (id != NULL_ID) {
        printf("ERROR:  Function newId() didn't return null id when max id has been reached\n");
    }

    if (!s1->idList_) {
        printf("ERROR:  The idList_ pointer is NULL prior to deleting the idStack\n");
    }
    if (!delIdStack(s1)) {
        printf("ERROR:  Function delIdStack() failed to free valid IdStack pointer\n");
        return false;
    }
    s1 = NULL;

    if (delIdStack(s1)) {
        printf("ERROR:  Function delIdStack() attempted to free invalid IdStack pointer\n");
        return false;
    }

    return true;
}

bool doubleIdStackTest() {
    Identity id;
    IdStack* s1 = NULL;
    IdStack* s2 = NULL;

    if (delIdStack(s1)) {
        printf("ERROR:  Function delIdStack() attempted to free invalid IdStack pointer\n");
        return false;
    }

    s1 = newIdStack();
    if (!s1) {
        printf("ERROR:  Function newIdStack() returned NULL pointer\n");
        return false;
    }
    if (!s1->idList_) {
        printf("ERROR:  Function newIdStack() didn't initialize the idList_ pointer\n");
    }

    s2 = newIdStack();
    if (!s2) {
        printf("ERROR:  Function newIdStack() returned NULL pointer\n");
        return false;
    }
    if (!s2->idList_) {
        printf("ERROR:  Function newIdStack() didn't initialize the idList_ pointer\n");
    }



    for (int i = 0; i < MAX_ID_STACK_ID_COUNT; i++) {
        id = newId(s1);
        if (id == NULL_ID) {
            printf("ERROR:  Function newId() returned null id when still available ids\n");
        }
        if (!s1->idList_) {
            printf("ERROR:  Function newId() didn't properly reallocate the idList_ pointer\n");
        }
    }
    id = newId(s1);
    if (id != NULL_ID) {
        printf("ERROR:  Function newId() didn't return null id when max id has been reached\n");
    }

    for (int i = 0; i < MAX_ID_STACK_ID_COUNT; i++) {
        id = newId(s2);
        if (id == NULL_ID) {
            printf("ERROR:  Function newId() returned null id when still available ids\n");
        }
        if (!s2->idList_) {
            printf("ERROR:  Function newId() didn't properly reallocate the idList_ pointer\n");
        }
    }
    id = newId(s2);
    if (id != NULL_ID) {
        printf("ERROR:  Function newId() didn't return null id when max id has been reached\n");
    }

    if (!s1->idList_) {
        printf("ERROR:  The idList_ pointer is NULL prior to deleting the idStack\n");
    }
    if (!delIdStack(s1)) {
        printf("ERROR:  Function delIdStack() failed to free valid IdStack pointer\n");
        return false;
    }
    s1 = NULL;
    if (delIdStack(s1)) {
        printf("ERROR:  Function delIdStack() attempted to free invalid IdStack pointer\n");
        return false;
    }

    if (!s2->idList_) {
        printf("ERROR:  The idList_ pointer is NULL prior to deleting the idStack\n");
    }
    if (!delIdStack(s2)) {
        printf("ERROR:  Function delIdStack() failed to free valid IdStack pointer\n");
        return false;
    }
    s2 = NULL;
    if (delIdStack(s2)) {
        printf("ERROR:  Function delIdStack() attempted to free invalid IdStack pointer\n");
        return false;
    }

    return true;
}
