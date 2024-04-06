#include <stdlib.h>
#include <stdio.h>
#include "../include/_stack.h"
#include "../include/stack.h"

static void _throw_error(char *msg);

Stack *stk_init() {
    Stack *s = malloc(sizeof *s);
    if (s == NULL)
        _throw_error("Could not allocate memory for stack");
    s->top = malloc(sizeof *s->top);
    if (s->top == NULL)
        _throw_error("Could not allocate memory for stack");
    s->size = 0;
    return s;
}

size_t stk_size(Stack *s) {
    return s->size;
}

size_t stk_is_empty(Stack *s) {
    return stk_size(s) == 0;
}

void stk_push(Stack *s, char c) {
    Entry *e = malloc(sizeof *e);
    if (e == NULL)
        _throw_error("Could not allocate memory for stack entry");
    e->c = c;
    e->next = stk_is_empty(s) ? NULL : s->top;
    s->top = e;
    s->size++;
}

char stk_pop(Stack *s) {
    if (stk_is_empty(s))
        _throw_error("Cannot pop from an empty stack");
    Entry *old_top = s->top;
    char c = old_top->c;
    s->top = s->top->next;
    free(old_top);
    s->size--;
    return c;
}

char stk_peek(Stack *s) {
    if (stk_is_empty(s))
        _throw_error("Cannot peek an empty stack");
    return s->top->c;
}

int stk_del(Stack *s) {
    while (s->top != NULL) {
        Entry *current = s->top;
        s->top = s->top->next;
        free(current);
    }
    free(s);
    return 0;
}

void stk_print(Stack *s) {
    Entry *current = s->top;
    while (current != NULL) {
        printf("| %c |\n", current->c);
        current = current->next;
    }
    puts("");
}

static void _throw_error(char *msg) {
    fprintf(stderr, "%s\n", msg);
    exit(EXIT_FAILURE);
}

