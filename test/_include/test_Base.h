#ifndef TEST_BASE_H
#define TEST_BASE_H

#include "test_List.h"

typedef enum teststatus_t {
    FAIL = 0,
    PASS = 1,
} TestStatus;

typedef struct unittestbase_t {
    TestType type_;

    // Entry point to unit test.
    TestStatus (*run_) ();
} UnitTestBase;

#endif//TEST_BASE_H
