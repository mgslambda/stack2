#ifndef _STACK_H
#define _STACK_H

#include <stddef.h>

typedef struct entry {
    char c;
    struct entry *next;
} Entry;

struct stack {
    Entry *top;
    size_t size;
};

#endif
