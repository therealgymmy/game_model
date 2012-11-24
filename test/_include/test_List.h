#ifndef TEST_LIST_H
#define TEST_LIST_H

typedef enum testtype_t {
    SAMPLE_SUITE = 0,

    // Low Level Resource Management
    ID_STACK = 1,
    MAP      = 2,
    PLAYER   = 3,
} TestType;

struct testlist_t {
    TestType *tests_;
} TestList;

#endif//TEST_LIST_H
