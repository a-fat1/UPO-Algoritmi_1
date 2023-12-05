#ifndef MY_TIMER3_PRIVATE_H
#define MY_TIMER3_PRIVATE_H

#include <time.h>
#include "timer3.h"

/** Implementation of the \c timer3_t type. */

struct timer3_s{
    time_t start;
    time_t stop;
};

static void timer3_throw_error(const char *msg);    /* Prints the given message to the standard error and abort the program. */

#endif /* MY_TIMER3_PRIVATE_H */
