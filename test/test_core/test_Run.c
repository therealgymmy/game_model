#include "../_include/test_Run.h"

// Dependencies
#include <stdint.h>
#include "../_include/test_Base.h"
#include "../_include/test_Log.h"

// Unit Tests
#include "../_include/ut_IdStack.h"
#include "../_include/ut_Player.h"
#include "../_include/ut_Map.h"

static
UnitTestBase* UnitTests[] = {
    (UnitTestBase*)&ut_IdStack,
    (UnitTestBase*)&ut_Player,
    (UnitTestBase*)&ut_Map,
};

static const
uint32_t UnitTestsLength = sizeof(UnitTests) / sizeof(UnitTestBase*);

void runTest ()
{
    for (uint32_t i = 0; i < UnitTestsLength; ++i) {
        if (!UnitTests[i]->run_()) {
            __log_print("The %dth unit test failed.\n", i);
        }
    }
}
