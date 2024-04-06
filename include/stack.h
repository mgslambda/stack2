#ifndef STACK_H
#define STACK_H

#include <stddef.h>

typedef struct stack Stack;
extern Stack *stk_init();
extern size_t stk_size(Stack *);
extern size_t stk_is_empty(Stack *);
extern void stk_push(Stack *, char);
extern char stk_pop(Stack *);
extern char stk_peek(Stack *);
extern int stk_del(Stack *);
extern void stk_print(Stack *);

#endif
