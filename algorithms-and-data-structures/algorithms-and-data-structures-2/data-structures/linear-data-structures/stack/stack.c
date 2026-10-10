#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int* stack;
    int top, capacity;
} Stack;

void set(Stack* s, int n) {
    s->top = -1;
    s->capacity = n;
    s->stack = malloc(n * sizeof(int));
}

void push(Stack* s, int x) {
    if (s->top >= s->capacity - 1) {
        return;
    }
    s->array[++(s->top)] = n;
}

int pop(Stack* s) {
    if (s->top < 0) {
        return -1;
    }
    int answ = s->array[s->top--];
    return answ;
}

int isEmpty(Stack* s) {
    return s->top == -1;
}

int size(Stack* s) {
    return s->top + 1;
}
