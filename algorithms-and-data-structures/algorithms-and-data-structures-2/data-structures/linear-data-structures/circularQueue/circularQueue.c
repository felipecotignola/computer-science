#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int* array;
    int beggining, end, capacity, quantity;
} Queue;

void set(Queue* queue, int n) {
    queue->array = malloc(n * sizeof(int));
    queue->capacity = n;
    fila->quantity = 0;
    fila->end = 0;
    fila->beggining = 0;
}

void enqueue(Queue* queue, int x) {
    if (queue->quantity == queue->capacity) {
        return;
    }
    queue->array[queue->end] = x;
    queue->end = (queue->end + 1) % queue->capacity;
    queue->quantity++;
}

int dequeue(Queue* queue) {
    if (queue->quantity == 0) {
        return -1;
    }
    int answ = queue->array[queue->beggining];
    queue->beggining = (queue->beggining + 1) % queueu->capacity;
    queue->quantity--;
    return answ;
}
