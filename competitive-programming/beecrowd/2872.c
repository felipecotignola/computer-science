#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct Package{
    char package[8];
    int number;
}Package;
Package* newPackage(char* input,int x){
    Package* p=malloc(sizeof(Package));
    strncpy(p->package,input,8);
    p->number=x;
    return p;
}

typedef struct Node{
    Package* p;
    struct Node* next;
}Node;
Node* newNode(Package* p){
    Node* n=malloc(sizeof(Node));
    n->p=p;
    n->next=NULL;
    return n;
}

typedef struct List{
    Node* h;
    Node* t;
    int q;
}List;
List* newList(){
    Package* p=newPackage("LIXO",-1);
    Node* n=newNode(p);
    List* l=malloc(sizeof(List));
    l->h=n;
    l->t=n;
    l->q=0;
    return l;
}
void insert(List* l,Package* p){
    Node* n=newNode(p);
    l->t->next=n;
    l->t=n;
    l->q++;
}
void sort(List* l){
    for(Node* i=l->h->next;i!=l->t;i=i->next){
        Node* smallest=i;
        for(Node* j=smallest->next;j!=NULL;j=j->next){
            if(j->p->number<smallest->p->number){
                smallest=j;
            }
        }
        Package* tmp=i->p;
        i->p=smallest->p;
        smallest->p=tmp;
    }
}
void print(List* l){
    Node* nav=l->h->next;
    while(nav!=NULL){
        printf("%s %d\n",nav->p->package,nav->p->number);
        nav=nav->next;
    }
    printf("\n");
}
void freeList(List* l){
	Node* nav=l->h;
	Node* tmp;
	while(nav!=NULL){
		tmp=nav->next;
		free(nav->p);
		free(nav);
		nav=tmp;
	}
	free(l);
}
int main(){
    char input[8];
    List* l=newList();
    while(scanf("%s",input)!=EOF){
        if(input[0]=='1'){
            scanf("%s",input);
            while(input[0]!='0'){
                int x;
                scanf("%d",&x);
                Package* package=newPackage(input,x);
                insert(l,package);
                scanf("%s",input);
            }
        } 
	sort(l);
        print(l);
        freeList(l);
        l=newList();
    }
    freeList(l);
    return 0;
}
