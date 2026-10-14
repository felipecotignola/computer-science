#include <stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct Node{
    int value;
    struct Node* next;
}Node;
Node* newNode(int x){
    Node* n=malloc(sizeof(Node));
    n->value=x;
    n->next=NULL;
    return n;
}
typedef struct{
    Node* top;
}Stack;
Stack* newStack(){
    Stack* s=malloc(sizeof(Stack));
    s->top=NULL;
    return s;
}
void push(int x,Stack* s){
    Node* n=newNode(x);
    n->next=s->top;
    s->top=n;
}
int pop(Stack* s){
    if(s->top==NULL){
        printf("EMPTY\n");
        return -1;
    }
    int resp=s->top->value;
    Node* tmp=s->top;
    s->top=s->top->next;
    tmp->next=NULL;
    free(tmp);
    return resp;
}
int findMin(Stack* s){
    Node* tmp=s->top;
    int min=tmp->value;
    tmp=tmp->next;
    while(tmp!=NULL){
        if(tmp->value<min){
            min=tmp->value;
        }
        tmp=tmp->next;
    }
    return min;
}
int size(char* str){
    int count=0;
    while(*str!='\0'){
        count++;
        str++;
    }
    return count;
}
int main() {
    int n;
    scanf("%d",&n);
    getchar();
    Stack* s=newStack();
    for(int i=0;i<n;i++){
        char operation[26];
        int x;
        scanf("%s",operation);
        if(strcmp(operation,"PUSH")==0){
            scanf("%d",&x);
            push(x,s);
            getchar();
        }
        else if(strcmp(operation,"POP")==0){
            pop(s);
        }
        else{
            if(s->top==NULL){
                printf("EMPTY\n");
            }
            else{
                printf("%d\n",findMin(s));
            }
        }    
    }
    return 0;
}#include <stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct Node{
    int value;
    struct Node* next;
}Node;
Node* newNode(int x){
    Node* n=malloc(sizeof(Node));
    n->value=x;
    n->next=NULL;
    return n;
}
typedef struct{
    Node* top;
}Stack;
Stack* newStack(){
    Stack* s=malloc(sizeof(Stack));
    s->top=NULL;
    return s;
}
void push(int x,Stack* s){
    Node* n=newNode(x);
    n->next=s->top;
    s->top=n;
}
int pop(Stack* s){
    if(s->top==NULL){
        printf("EMPTY\n");
        return -1;
    }
    int resp=s->top->value;
    Node* tmp=s->top;
    s->top=s->top->next;
    tmp->next=NULL;
    free(tmp);
    return resp;
}
int findMin(Stack* s){
    Node* tmp=s->top;
    int min=tmp->value;
    tmp=tmp->next;
    while(tmp!=NULL){
        if(tmp->value<min){
            min=tmp->value;
        }
        tmp=tmp->next;
    }
    return min;
}
int size(char* str){
    int count=0;
    while(*str!='\0'){
        count++;
        str++;
    }
    return count;
}
void readline(char* str,int tam){
    fgets(str,stdin,tam);
    str[size(str)-1]='\0';
} 
int main() {
    int n;
    scanf("%d",&n);
    getchar();
    Stack* s=newStack();
    for(int i=0;i<n;i++){
        char operation[26];
        int x;
        readline(operation,26);
        if(strcmp(operation,"PUSH")==0){
            scanf("%d",&x);
            push(x,s);
            getchar();
        }
        else if(strcmp(operation,"POP")==0){
            pop(s);
        }
        else{
            if(s->top==NULL){
                printf("EMPTY\n");
            }
            else{
                printf("%d\n",findMin(s));
            }
        }    
    }
    return 0;
}


