#include "../_include/ut_Player.h"

// Dependencies
#include "../_include/test_Log.h"

// Required by test
#include "../../src/model/_include/player.h"

UnitTestPlayer ut_Player = {
    .base_ = {
        .type_ = UT_PLAYER,
        .run_  = &run_player
    }
};

static
IdStack* idStack;

static
bool isIdStackCreated = false;

//---Prototypes---

static TestStatus singlePlayerTest();
static TestStatus doublePlayerTest();



//---Implementations---
//
TestStatus run_player() {
    __enter;

    __checkpoint("IdStack initialization\n");
    if (!isIdStackCreated) {
        idStack = newIdStack();
        isIdStackCreated = true;
    }

    if (!singlePlayerTest()) {
        __return_status(FAIL);
    }
    if (!singlePlayerTest()) {
        __return_status(FAIL);
    }

    if (!doublePlayerTest()) {
        __return_status(FAIL);
    }
    if (!doublePlayerTest()) {
        __return_status(FAIL);
    }

    __checkpoint("IdStack cleanup\n");
    if (isIdStackCreated) {
        delIdStack(idStack);
        isIdStackCreated = false;
    }

    __return_status(PASS);
}

TestStatus singlePlayerTest() {
    __enter;

    Player* p1 = newPlayer(idStack);
    if (!p1) {
        __log_print("ERROR:  Function newPlayer() returned NULL pointer\n");
        __return_status(FAIL);
    }
    if (!delPlayer(p1)) {
        __log_print("ERROR:  Function delPlayer() failed to free valid Player pointer\n");
        __return_status(FAIL);
    }
    p1 = NULL;

    if (delPlayer(p1)) {
        __log_print("ERROR:  Function delPlayer() attempted to free invalid Player pointer\n");
        __return_status(FAIL);
    }

    __return_status(PASS);
}

TestStatus doublePlayerTest() {
    __enter;

    Player* p1 = NULL;
    Player* p2 = NULL;

    if (delPlayer(p1)) {
        __log_print("ERROR:  Function delPlayer() attempted to free invalid Player pointer\n");
        __return_status(FAIL);
    }

    p1 = newPlayer(idStack);
    if (!p1) {
        __log_print("ERROR:  Function newPlayer() returned NULL pointer\n");
        __return_status(FAIL);
    }
    p2 = newPlayer(idStack);
    if (!p2) {
        __log_print("ERROR:  Function newPlayer() returned NULL pointer\n");
        __return_status(FAIL);
    }

    if (!delPlayer(p1)) {
        __log_print("ERROR:  Function delPlayer() failed to free valid Player pointer\n");
        __return_status(FAIL);
    }
    p1 = NULL;
    if (delPlayer(p1)) {
        __log_print("ERROR:  Function delPlayer() attempted to free invalid Player pointer\n");
        __return_status(FAIL);
    }

    if (!delPlayer(p2)) {
        __log_print("ERROR:  Function delPlayer() failed to free valid Player pointer\n");
        __return_status(FAIL);
    }
    p2 = NULL;
    if (delPlayer(p2)) {
        __log_print("ERROR:  Function delPlayer() attempted to free invalid Player pointer\n");
        __return_status(FAIL);
    }

    __return_status(PASS);
}
