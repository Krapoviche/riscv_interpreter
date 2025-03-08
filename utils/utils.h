#ifndef UTILS_H_
#define UTILS_H_

#if defined(DEBUG_ACTIVE)
    #define DEBUG(fmt, args...) fprintf(stderr, "DEBUG: %s:%d:%s(): " fmt, \
        __FILE__, __LINE__, __func__, ##args)
#else
    #define DEBUG(fmt, args...)
#endif

#include <stdio.h>
#include <stdint.h>
#include "../memory/memory.h"
#include "../cpu/clock.h"

void memory_dump(memory mem);
struct timespec sub_timespec(struct timespec* t1, struct timespec* t2);

#endif
