#include <stdio.h>
#include <stdlib.h>

typedef struct Node { 
    int value;
    struct Node* next;
} Node;

Node* createNode(int x) {
    Node* n = malloc(sizeof(Node));
    n->value = x;
    n->next = NULL;
    return n;
}

typedef struct {
    Node* top;
} Stack;

Stack* createStack() {
    Stack* stack = malloc(sizeof(Stack));
    stack->top = NULL;    
    return stack;
}

void push(Stack* stack, int x) {
    Node* n = createNode(x);
    n->next = stack->top;
    stack->top = n;    
}

int pop(Stack* stack) {
    if (stack->top != NULL) {    
        int res = stack->top->value; 
        Node* tmp = stack->top;
        stack->top = tmp->next;
        free(tmp);
        return res;    
    }
    return -1;
}

void print(Stack* stack) {
    Node* tmp = stack->top;
    while (tmp != NULL) {
        printf("%d ", tmp->value);
        tmp = tmp->next;
    }
    printf("\n");
}