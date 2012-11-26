#include "../_include/ut_IdStack.h"

// Dependencies
#include "../_include/test_Log.h"

// Required by test
#include "../../src/model/_include/identity.h"

UnitTestIdStack ut_IdStack = {
    .base_ = {
        .type_ = UT_ID_STACK,
        .run_  = &run_idstack
    }
};

//---Prototypes---

static TestStatus singleIdStackTest();
static TestStatus doubleIdStackTest();



//---Implementations---

TestStatus run_idstack() {
    if (!singleIdStackTest()) {
        __log_print("Failed singleIdStackTest first try\n");
        __return_status(FAIL);
    }
    /*
    if (!singleIdStackTest()) {
        __log_print("Failed singleIdStackTest second try\n");
        __return_status(FAIL);
    }

    if (!doubleIdStackTest()) {
        __log_print("Failed doubleIdStackTest first try\n");
        __return_status(FAIL);
    }
    if (!doubleIdStackTest()) {
        __log_print("Failed doubleIdStackTest second try\n");
        __return_status(FAIL);
    }
    */

    __return_status(PASS);
}

TestStatus singleIdStackTest() {
    Identity id;
    IdStack* s1 = newIdStack();
    if (!s1) {
        __log_print("ERROR:  Function newIdStack() returned NULL pointer\n");
        __return_status(FAIL);
    }
    if (!s1->idList_) {
        __log_print("ERROR:  Function newIdStack() didn't initialize the idList_ pointer\n");
        __return_status(FAIL);
    }

    __checkpoint("Begin to stress test newId()\n");
    for (uint32_t i = 0; i < MAX_ID_STACK_ID_COUNT; i++) {
        id = newId(s1);
        if (id == NULL_ID) {
            __log_print("ERROR:  Function newId() returned null id when still available ids\n");
            __return_status(FAIL);
        }
    }
    id = newId(s1);
    if (id != NULL_ID) {
        __log_print("ERROR:  Function newId() didn't return null id when max id has been reached\n");
        __return_status(FAIL);
    }

    __checkpoint("clean up\n");
    if (!s1->idList_) {
        __log_print("ERROR:  The idList_ pointer is NULL prior to deleting the idStack\n");
        __return_status(FAIL);
    }
    if (!delIdStack(s1)) {
        __log_print("ERROR:  Function delIdStack() failed to free valid IdStack pointer\n");
        __return_status(FAIL);
    }
    s1 = NULL;

    if (delIdStack(s1)) {
        __log_print("ERROR:  Function delIdStack() attempted to free invalid IdStack pointer\n");
        __return_status(FAIL);
    }

    __return_status(PASS);
}

TestStatus doubleIdStackTest() {
    Identity id;
    IdStack* s1 = NULL;
    IdStack* s2 = NULL;

    if (delIdStack(s1)) {
        __log_print("ERROR:  Function delIdStack() attempted to free invalid IdStack pointer\n");
        __return_status(FAIL);
    }

    s1 = newIdStack();
    if (!s1) {
        __log_print("ERROR:  Function newIdStack() returned NULL pointer\n");
        __return_status(FAIL);
    }
    if (!s1->idList_) {
        __log_print("ERROR:  Function newIdStack() didn't initialize the idList_ pointer\n");
        __return_status(FAIL);
    }

    s2 = newIdStack();
    if (!s2) {
        __log_print("ERROR:  Function newIdStack() returned NULL pointer\n");
        __return_status(FAIL);
    }
    if (!s2->idList_) {
        __log_print("ERROR:  Function newIdStack() didn't initialize the idList_ pointer\n");
        __return_status(FAIL);
    }



    for (uint32_t i = 0; i < MAX_ID_STACK_ID_COUNT; i++) {
        id = newId(s1);
        if (id == NULL_ID) {
            __log_print("ERROR:  Function newId() returned null id when still available ids\n");
            __return_status(FAIL);
        }
        if (!s1->idList_) {
            __log_print("ERROR:  Function newId() didn't properly reallocate the idList_ pointer\n");
            __return_status(FAIL);
        }
    }
    id = newId(s1);
    if (id != NULL_ID) {
        __log_print("ERROR:  Function newId() didn't return null id when max id has been reached\n");
        __return_status(FAIL);
    }

    for (uint32_t i = 0; i < MAX_ID_STACK_ID_COUNT; i++) {
        id = newId(s2);
        if (id == NULL_ID) {
            __log_print("ERROR:  Function newId() returned null id when still available ids\n");
            __return_status(FAIL);
        }
        if (!s2->idList_) {
            __log_print("ERROR:  Function newId() didn't properly reallocate the idList_ pointer\n");
            __return_status(FAIL);
        }
    }
    id = newId(s2);
    if (id != NULL_ID) {
        __log_print("ERROR:  Function newId() didn't return null id when max id has been reached\n");
        __return_status(FAIL);
    }

    if (!s1->idList_) {
        __log_print("ERROR:  The idList_ pointer is NULL prior to deleting the idStack\n");
        __return_status(FAIL);
    }
    if (!delIdStack(s1)) {
        __log_print("ERROR:  Function delIdStack() failed to free valid IdStack pointer\n");
        __return_status(FAIL);
    }
    s1 = NULL;
    if (delIdStack(s1)) {
        __log_print("ERROR:  Function delIdStack() attempted to free invalid IdStack pointer\n");
        __return_status(FAIL);
    }

    if (!s2->idList_) {
        __log_print("ERROR:  The idList_ pointer is NULL prior to deleting the idStack\n");
        __return_status(FAIL);
    }
    if (!delIdStack(s2)) {
        __log_print("ERROR:  Function delIdStack() failed to free valid IdStack pointer\n");
        __return_status(FAIL);
    }
    s2 = NULL;
    if (delIdStack(s2)) {
        __log_print("ERROR:  Function delIdStack() attempted to free invalid IdStack pointer\n");
        __return_status(FAIL);
    }

    __return_status(PASS);
}
