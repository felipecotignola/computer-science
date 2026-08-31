#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int tam, capacidade;
    int *lista;
} list;

void construtor(list *Struct, int capacidade) {
    (*Struct).tam = 0;
    (*Struct).capacidade = capacidade;
    (*Struct).lista = malloc(capacidade * sizeof(int));
}

void inserirInicio(list *Struct, int n) {
    if ((*Struct).tam >= (*Struct).capacidade) {
        return;
    }

    for (int i = (*Struct).tam; i > 0; i--) {
        (*Struct).lista[i] = (*Struct).lista[i - 1];
    }

    (*Struct).lista[0] = n;
    (*Struct).tam++;
}

void inserirPos(list *Struct, int n, int pos) {
    if ((*Struct).tam >= (*Struct).capacidade ||
        pos < 0 || pos > (*Struct).tam) {
        return;
    }

    for (int i = (*Struct).tam; i > pos; i--) {
        (*Struct).lista[i] = (*Struct).lista[i - 1];
    }

    (*Struct).lista[pos] = n;
    (*Struct).tam++;
}

void inserirFim(list *Struct, int n) {
    if ((*Struct).tam >= (*Struct).capacidade) {
        return;
    }

    (*Struct).lista[(*Struct).tam] = n;
    (*Struct).tam++;
}

int removerInicio(list *Struct) {
    if ((*Struct).tam <= 0) {
        return -1;
    }

    int resp = (*Struct).lista[0];

    for (int i = 0; i < (*Struct).tam - 1; i++) {
        (*Struct).lista[i] = (*Struct).lista[i + 1];
    }

    (*Struct).tam--;

    return resp;
}

int removerPos(list *Struct, int pos) {
    if (pos < 0 || pos >= (*Struct).tam) {
        return -1;
    }

    int resp = (*Struct).lista[pos];

    for (int i = pos; i < (*Struct).tam - 1; i++) {
        (*Struct).lista[i] = (*Struct).lista[i + 1];
    }

    (*Struct).tam--;

    return resp;
}

int removerFim(list *Struct) {
    if ((*Struct).tam <= 0) {
        return -1;
    }

    int resp = (*Struct).lista[(*Struct).tam - 1];

    (*Struct).tam--;

    return resp;
}

void print(list *Struct) {
    for (int i = 0; i < (*Struct).tam; i++) {
        printf("%d ", (*Struct).lista[i]);
    }

    printf("\n");
}
