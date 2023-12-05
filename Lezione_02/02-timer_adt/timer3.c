#include <assert.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "timer3_private.h"

timer3_t timer3_create()
{
    timer3_t timer = NULL;

    timer = malloc(sizeof(struct timer3_s));
    if (timer == NULL)
        timer3_throw_error(strerror(errno));

    timer->start = timer->stop = -1;        /* Invalidates the timer */

    return timer;
}

void timer3_destroy(timer3_t timer)
{
    if (timer != NULL)
        free(timer);
}

void timer3_start(timer3_t timer)
{
    if (timer == NULL)
        timer3_throw_error("Invalid timer argument");

    time(&timer->start);
    timer->stop = -1; 
}

void timer3_stop(timer3_t timer)
{
    if (timer == NULL)
        timer3_throw_error("Invalid timer argument");

    if (!timer3_is_stopped(timer))
        time(&timer->stop);
} 

int timer3_is_started(const timer3_t timer) 
{
    if (timer == NULL)
        timer3_throw_error("Invalid timer argument");

    return (timer->start != -1) ? 1 : 0;
}

int timer3_is_stopped(const timer3_t timer) 
{
    if (timer == NULL)
        timer3_throw_error("Invalid timer argument");

    return (timer->stop != -1) ? 1 : 0;
}

double timer3_elapsed(const timer3_t timer)
{
    if (timer == NULL)
        timer3_throw_error("Invalid timer argument");
    
    if (timer3_is_stopped(timer))
        return difftime(timer->stop, timer->start);     /* The timer is stopped: returns the length of the [start,stop) interval */
    
    if (timer3_is_started(timer))
        return difftime(time(NULL), timer->start);      /* The timer isn't stopped: returns the time elapsed so far */

    return -1;
}

void timer3_throw_error(const char *msg)
{
    assert(msg);

    fprintf(stderr, "[file: %s, line: %d] %s\n", __FILE__, __LINE__, msg);
    abort();
}
