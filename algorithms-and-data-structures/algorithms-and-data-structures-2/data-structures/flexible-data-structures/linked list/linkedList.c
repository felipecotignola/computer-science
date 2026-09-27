#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node* next;
} Node;

Node* createNode(int x) {
    Node* n = (Node*)malloc(sizeof(Node));
    n->value = x;
    n->next = NULL;
    return n;
}

typedef struct {
    Node* head;
    Node* tail;
} SinglyLinkedList;

SinglyLinkedList* createSinglyLinkedList() {
    SinglyLinkedList* list = (SinglyLinkedList*)malloc(sizeof(SinglyLinkedList));
    list->head = createNode(0);
    list->tail = list->head;
    return list;
}

void insertFirst(SinglyLinkedList* list, int x) {
    list->head->value = x;
    Node* newHead = createNode(0);
    newHead->next = list->head;
    list->head = newHead;
}

void insertLast(SinglyLinkedList* list, int x) {
    list->tail->next = createNode(x);
    list->tail = list->tail->next;
}

int removeFirst(SinglyLinkedList* list) {
    if (list->head == list->tail) {
        return -1;
    }
    Node* tmp = list->head->next;
    int res = tmp->value;
    list->head->next = tmp->next;
    if (tmp == list->tail) {
        list->tail = list->head;
    }
    free(tmp);
    return res;
}

void print(SinglyLinkedList* list) {
    Node* tmp = list->head->next;
    while (tmp != NULL) {
        printf("%d ", tmp->value);
        tmp = tmp->next;
    }
    printf("\n");
}