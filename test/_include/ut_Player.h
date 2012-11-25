#ifndef UT_PLAYER_H
#define UT_PLAYER_H

#include "test_Base.h"

typedef struct unittestplayer_t {
    // Unit Test Info
    UnitTestBase base_;

} UnitTestPlayer;

extern UnitTestPlayer ut_Player;

TestStatus run_player();

#endif//UT_PLAYER_H
