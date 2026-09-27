#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int* vet;
    int topo, capacidade;
} stack;

void construtor(stack* pilha, int n) {
    pilha->topo = -1;
    pilha->capacidade = n;
    pilha->vet = malloc(n * sizeof(int));
}

void push(stack* pilha, int n) {
    if (pilha->topo >= pilha->capacidade - 1) {
        return;
    }
    pilha->vet[++(pilha->topo)] = n;
}

int pop(stack* pilha) {
    if (pilha->topo < 0) {
        return -1;
    }
    int resp = pilha->vet[pilha->topo--];
    return resp;
}

int isVazia(stack* pilha) {
    return pilha->topo == -1;
}

int size(stack* pilha) {
    return pilha->topo + 1;
}