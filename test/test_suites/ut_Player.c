#include "../_include/ut_Player.h"

// Dependencies
#include <stdio.h>
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

static bool singlePlayerTest();
static bool doublePlayerTest();



//---Implementations---
//
TestStatus run_player() {
    if (!isIdStackCreated) {
        idStack = newIdStack();
        isIdStackCreated = true;
    }

    if (!singlePlayerTest()) {
        printf("Failed singlePlayerTest first try\n");
        return FAIL;
    }
    if (!singlePlayerTest()) {
        printf("Failed singlePlayerTest second try\n");
        return FAIL;
    }

    if (!doublePlayerTest()) {
        printf("Failed doublePlayerTest first try\n");
        return FAIL;
    }
    if (!doublePlayerTest()) {
        printf("Failed doublePlayerTest second try\n");
        return FAIL;
    }

    if (isIdStackCreated) {
        delIdStack(idStack);
        isIdStackCreated = false;
    }

    return PASS;
}

bool singlePlayerTest() {
    Player* p1 = newPlayer(idStack);
    if (!p1) {
        printf("ERROR:  Function newPlayer() returned NULL pointer\n");
        return false;
    }
    if (!delPlayer(p1)) {
        printf("ERROR:  Function delPlayer() failed to free valid Player pointer\n");
        return false;
    }
    p1 = NULL;

    if (delPlayer(p1)) {
        printf("ERROR:  Function delPlayer() attempted to free invalid Player pointer\n");
        return false;
    }

    return true;
}

bool doublePlayerTest() {
    Player* p1 = NULL;
    Player* p2 = NULL;

    if (delPlayer(p1)) {
        printf("ERROR:  Function delPlayer() attempted to free invalid Player pointer\n");
        return false;
    }

    p1 = newPlayer(idStack);
    if (!p1) {
        printf("ERROR:  Function newPlayer() returned NULL pointer\n");
        return false;
    }
    p2 = newPlayer(idStack);
    if (!p2) {
        printf("ERROR:  Function newPlayer() returned NULL pointer\n");
        return false;
    }

    if (!delPlayer(p1)) {
        printf("ERROR:  Function delPlayer() failed to free valid Player pointer\n");
        return false;
    }
    p1 = NULL;
    if (delPlayer(p1)) {
        printf("ERROR:  Function delPlayer() attempted to free invalid Player pointer\n");
        return false;
    }

    if (!delPlayer(p2)) {
        printf("ERROR:  Function delPlayer() failed to free valid Player pointer\n");
        return false;
    }
    p2 = NULL;
    if (delPlayer(p2)) {
        printf("ERROR:  Function delPlayer() attempted to free invalid Player pointer\n");
        return false;
    }

    return true;
}
