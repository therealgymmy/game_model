#ifndef TEST_LOG_H
#define TEST_LOG_H

// Dependencies
#include <stdio.h>
#include <stdlib.h>
#include "test_Base.h"

#if defined(__GNUC__) || \
    defined(__MINGW32__) || \
    defined(__MINGW64__)
 #define FUNC __PRETTY_FUNCTION__
#else
 #define FUNC __func__
#endif

#define TEST_NAME FUNC

#define LOG_FILE "test_results.log"

#define __checkpoint(...) do {\
                          __log_print("<--CheckPoint-->    "__VA_ARGS__);\
                          } while (0)

#define __enter __log_print("<--Enter-->        %s\n", FUNC)

#define __return(arg) do {\
                      __log_print("<--Leave-->        %s\n", FUNC);\
                      return (arg);\
                      } while (0)

#define __return_status(arg) do {\
                             testStatus (arg, TEST_NAME);\
                             __return(arg);\
                             } while (0)


#define __log_print(...) __log_print_impl("--TEST--    "__VA_ARGS__)

#define __log_print_impl(...) do {\
                              FILE *file = fopen(LOG_FILE, "a");\
                              if (!file) {\
                                  printf("CANNOT OPEN "LOG_FILE);\
                                  exit(EXIT_FAILURE);\
                              }\
                              printf(__VA_ARGS__);\
                              fprintf(file, __VA_ARGS__);\
                              if (fclose(file)) {\
                                  printf("CANNOT CLOSE "LOG_FILE);\
                                  exit(EXIT_FAILURE);\
                              }\
                              } while (0)

inline
void testStatus (TestStatus status, const char *testName)
{
    switch (status) {
        case FAIL:
            __log_print("<--Test: \'%s\'-->    failed\n", testName);
            break;
        case PASS:
            __log_print("<--Test: \'%s\'-->    passed\n", testName);
            break;
    }
}

#endif//TEST_LOG_H
