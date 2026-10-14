#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct Node{
    char plane[6];
    struct Node* next;
}Node;
Node* newNode(char* plane){
    Node* node=malloc(sizeof(Node));
    strcpy(node->plane,plane);
    node->next=null;
    return node;
}
typedef struct Queue{
    Node* h;
    Node* t;
    int q;
}
Queue* newQueue(){
    char c='-1';
    Node* node=newNode(&c);
    Queue* q=malloc(sizeof(Queue));
    q->h=node;
    q->t=node;
    q->q=0;
    return q;
}
void enqueue(Queue* q,char* input){
    Node* node=newNode(input);
    q->t->next=node;
    q->t=node;
    q->q++;
}
char* dequeue(Queue* q){
    if(q->q>0){
     Node* tmp=q->h->next;
     char answ[6];
     strcpy(tmp->plane,answ);
     q->h->next=tmp->next;
     tmp->next=NULL;
     if(q->t==tmp){
         q->t=q->h;
     }
     free(tmp);
     q->q--;
     return answ;
    }
}
int main() {
    Queue* array[4];
    for(int i=0;i<4;i++){
        array[i]=newQueue(-1);
    }
    char input[6];
    scanf("%s",input);
    int atual;
        while(strcmp(input,"0")!=0){
            if(input[0]=='-'){
                atual=abs(atoi(input))-1;
            }
            enqueue(array[atual],input);
        }
    }
    return 0;
}
