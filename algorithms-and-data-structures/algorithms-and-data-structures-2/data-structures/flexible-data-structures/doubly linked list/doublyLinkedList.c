#include <stdio.h>
#include <stdlib.h>

typedef struct DoubleNode {
    int value;
    struct DoubleNode* prev;
    struct DoubleNode* next;
} DoubleNode;

DoubleNode* createDoubleNode(int x) {
    DoubleNode* n = (DoubleNode*)malloc(sizeof(DoubleNode));
    n->value = x;
    n->prev = NULL;
    n->next = NULL;
    return n;
}

typedef struct {
    DoubleNode* head;
    DoubleNode* tail;
} DoublyLinkedList;

DoublyLinkedList* createDoublyLinkedList() {
    DoublyLinkedList* list = (DoublyLinkedList*)malloc(sizeof(DoublyLinkedList));
    list->head = createDoubleNode(0);
    list->tail = list->head;
    return list;
}

void insertFirst(DoublyLinkedList* list, int x) {
    DoubleNode* tmp = createDoubleNode(x);
    tmp->next = list->head->next;
    tmp->prev = list->head;

    if (list->head->next != NULL) {
        list->head->next->prev = tmp;
    } else {
        list->tail = tmp;
    }
    list->head->next = tmp;
}

void insertLast(DoublyLinkedList* list, int x) {
    DoubleNode* tmp = createDoubleNode(x);
    tmp->prev = list->tail;
    list->tail->next = tmp;
    list->tail = tmp;
}

int removeFirst(DoublyLinkedList* list) {
    if (list->head == list->tail) {
        return -1;
    }
    DoubleNode* tmp = list->head->next;
    int res = tmp->value;
    list->head->next = tmp->next;

    if (tmp->next != NULL) {
        tmp->next->prev = list->head;
    } else {
        list->tail = list->head;
    }

    free(tmp);
    return res;
}

int removeLast(DoublyLinkedList* list) {
    if (list->head == list->tail) {
        return -1;
    }
    DoubleNode* tmp = list->tail;
    int res = tmp->value;

    list->tail = list->tail->prev;
    list->tail->next = NULL;

    free(tmp);
    return res;
}

void print(DoublyLinkedList* list) {
    DoubleNode* tmp = list->head->next;
    while (tmp != NULL) {
        printf("%d ", tmp->value);
        tmp = tmp->next;
    }
    printf("\n");
}