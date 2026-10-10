#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int size, capacity;
    int *list;
} List;

void set(List* list, int n) {
    list->size = 0;
    list->capacity = n;
    list->list = malloc(n * sizeof(int));
}

void insertBeggining(List* l, int x) {
    if (l->size >= l->capacity) {
        return;
    }

    for (int i = l->size; i > 0; i--) {
        l->list[i] = l->list[i - 1];
    }

    l->list[0] = x;
    l->size++;
}

void insertPos(List* l, int x, int pos) {
    if (l->size >= l->capacity || pos < 0 || pos > l->size) {
        return;
    }

    for (int i = l->size; i > pos; i--) {
        l->list[i] = l->list[i - 1];
    }

    l->list[pos] = x;
    l->size++;
}

void insertEnd(List* l, int x) {
    if (l->size >= l->capacity) {
        return;
    }

    l->list[l->size] = x;
    l->size++;
}

int removeBeggining(List* l) {
    if (l->size <= 0) {
        return -1;
    }

    int answ = l->list[0];

    for (int i = 0; i < l->size - 1; i++) {
        l->list[i] = l->list[i + 1];
    }

    l->size--;

    return answ;
}

int removePos(List* l, int pos) {
    if (pos < 0 || pos >= l->size) {
        return -1;
    }

    int answ = l->list[pos];

    for (int i = pos; i < l->size - 1; i++) {
        l->list[i] = l->list[i + 1];
    }

    l->size--;

    return answ;
}

int removeEnd(List* l) {
    if (l->size <= 0) {
        return -1;
    }

    int answ = l->list[l->size - 1];

    l->size--;

    return answ;
}

void print(List* l) {
    for (int i = 0; i < l->size; i++) {
        printf("%d ", l->list[i]);
    }

    printf("\n");
}
