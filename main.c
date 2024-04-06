#include <stdio.h>
#include "./include/stack.h"

int main() {
    Stack *s = stk_init();
    stk_push(s, 'a');
    stk_print(s);
    printf("Current stack size = %lu\n\n", stk_size(s));
    stk_push(s, 'b');
    stk_print(s);
    printf("Current stack size = %lu\n\n", stk_size(s));
    stk_push(s, 'c');
    stk_print(s);
    printf("Current stack size = %lu\n\n", stk_size(s));
    stk_push(s, 'd');
    stk_print(s);
    printf("Current stack size = %lu\n\n", stk_size(s));
    printf("Popped '%c' from stack\n", stk_pop(s));
    printf("Current stack size = %lu\n\n", stk_size(s));
    printf("'%c' is now at the top of the stack:\n\n", stk_peek(s));
    stk_print(s);
    int res = stk_del(s);
    puts(!res ? "Stack deallocated" : "Error deallocating stack");
}

