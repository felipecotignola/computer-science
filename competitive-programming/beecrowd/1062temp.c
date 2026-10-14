#include <stdio.h>
typedef struct{
    int* array;
    int topo,capacidade,quantidade;
}Stack;
Stack* newStack(int n){
    Stack* s=mallloc(sizeof(Stack));
    s->array=malloc(n*sizeof(int));
    s->topo=-1;
    s->capacidade=n;
}
void push(Stack* s,int x){
    if(s->topo<capacidade){
        s->array[s->++topo]=x;
    }
}
int pop(){
    if(s->topo>=0){
        return s->array[s->topo--];
    }
}
int getTopo(Stack* s){
    return s->topo;
}
int main() {
    int n;
    scanf("%d",&n);
    Stack* a=newStack(n);
    for(int i=1;i<+n;i++){
        push(a,i);
    }
    int sequencia[n];
    for(int i=0;i<n;i++){
        scanf("%d",&sequencia[i]);
    }
    Stack* e=newStack();
    Stack* b=newStack();
    int index=0;
    for(int i=0;i<n;i++){
    while(getTopo(a)!=array[i] && i<n){
        push(estacao,pop(a));
        i++;
    }
    push(estacao,pop(a));
    push(b,pop(e));
    while()
    return 0;
}
