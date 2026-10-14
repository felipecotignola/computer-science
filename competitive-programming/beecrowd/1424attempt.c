#include <stdio.h>
#include <stdlib.h>
typedef struct Node{
    int value;
    struct Node* next;
}Node;
Node* newNode(int x){
    Node* node=malloc(sizeof(Node));
    node->value=x;
    node->next=NULL;
    return node;
}
typedef struct{
    Node* head,tail;
}List;
List* newList(){
    List* l=malloc(sizeof(List));
    Node* node=newNode(-1);
    l->head=node;
    l->tail=node;
}
void insertEnd(List* l,int x){
    Node* node=newNode(x);
    l->tail->next=node;
    l->tail=node;
}
int getOccurrency(List* l,int pos){
    if(l->head->next==NULL){
        return 0;
    }
    Node* tmp=
}
int main() {
    int n,m;
    while(scanf("%d %d",&n,&m)!='EOF'){
           int* array=malloc(n*sizeof(int));
        for(int i=0;i<n;i++){
            scanf("%d",&array[i]);
        }
        for(int i=0;i<m;i++){
            int k,v,count=0,answ=0;
            scanf("%d",&k,&v);
        }       
    }
 
    return 0;
}
