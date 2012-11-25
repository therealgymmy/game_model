#include "../_include/test_Run.h"

// Dependencies
#include <stdint.h>
#include "../_include/test_Base.h"

// Unit Tests
#include "../_include/ut_Player.h"

static
UnitTestBase* UnitTests[] = {
    (UnitTestBase*)&ut_Player
};

static const
uint32_t UnitTestsLength = sizeof(UnitTests) / sizeof(UnitTestBase*);

void runTest ()
{
    for (uint32_t i = 0; i < UnitTestsLength; ++i) {
        if (!UnitTests[i]->run_()) {
            // Output info about this specific unit test.
        }
    }
}
