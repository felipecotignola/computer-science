#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int* array;
    int inicio, pos, capacidade, quantidade;
} Fila;

void set(Fila* fila, int n) {
    fila->array = malloc(n * sizeof(int));
    fila->capacidade = n;
    fila->quantidade = 0;
    fila->pos = 0;
    fila->inicio = 0;
}

void enqueue(Fila* fila, int n) {
    if (fila->quantidade == fila->capacidade) {
        return;
    }
    fila->array[fila->pos] = n;
    fila->pos = (fila->pos + 1) % fila->capacidade;
    fila->quantidade++;
}

int dequeue(Fila* fila) {
    if (fila->quantidade == 0) {
        return -1;
    }
    int resp = fila->array[fila->inicio];
    fila->inicio = (fila->inicio + 1) % fila->capacidade;
    fila->quantidade--;
    return resp;
}
