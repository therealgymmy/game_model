#ifdef _DEBUG

// Dependencies
#include <time.h>
#include "_include/test_Log.h"
#include "_include/test_Run.h"

static void curTime ();

int main ()
{
    curTime();
    runTest();
    curTime();
    __log_print("\n");
    return 0;
}

void curTime ()
{
    time_t t = time(0);
    struct tm *now = localtime(&t);
    __log_print("<--Current Time-->        %d-%d-%d    %d:%d:%d\n",
                (now->tm_year + 1900),
                (now->tm_mon  + 1),
                (now->tm_mday),
                (now->tm_hour),
                (now->tm_min),
                (now->tm_sec));
}

#endif
