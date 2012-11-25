#ifndef UT_ID_STACK_H
#define UT_ID_STACK_H

#include "test_Base.h"

typedef struct unittestidstack_t {
    // Unit Test Info
    UnitTestBase base_;

} UnitTestIdStack;

extern UnitTestIdStack ut_IdStack;

TestStatus run_idstack();

#endif//UT_ID_STACK_H
