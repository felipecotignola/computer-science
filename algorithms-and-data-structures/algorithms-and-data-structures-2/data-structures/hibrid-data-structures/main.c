#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Contact{
	char name[51];
} Contact;

Contact newContact(char* str){
	Contact c;
	strcpy(c.name,str);
	return c;
}

typedef struct Cell{
	Contact c;
	struct Cell* next;
} Cell;

Cell* newCell(Contact c){
	Cell* cell=malloc(sizeof(Cell));
	cell->c=c;
	cell->next=NULL;
	return cell;
}

typedef struct List{
	Cell* start;
} List;

List* newList(Contact c){
	List* l=malloc(sizeof(List));
	Cell* cell=newCell(c);
	l->start=cell;
	return l;
}

void insertOrdered(List* l,Contact c){
	Cell* tmp=l->start;
	if(strcmp(tmp->c.name,c.name)>0){
		Cell* cell=newCell(c);
		cell->next=tmp;
		l->start=cell;
		return;	
	} 
	while(tmp->next!=NULL && strcmp(tmp->next->c.name,c.name)<0){
		tmp=tmp->next;
	}
	Cell* cell=newCell(c);
	cell->next=tmp->next;
	tmp->next=cell;
}
typedef struct Node{
	char letter;
	List* l;
	struct Node* left;
	struct Node* right;
} Node;

int searchList(List* l,char* str){
	Cell* tmp=l->start;
	while(tmp!=NULL && strcmp(tmp->c.name,str)<0){
		tmp=tmp->next;	
	}
	return tmp!=NULL && strcmp(tmp->c.name,str)==0;
}
Node* newNode(Contact c){
	Node* n=malloc(sizeof(Node));
	n->letter=c.name[0];
	n->l=newList(c);
	n->left=NULL;
	n->right=NULL;
	return n;
}

typedef struct Bst{
	Node* root;
} Bst;

Bst* newBst(){
	Bst* bst=malloc(sizeof(Bst));
	bst->root=NULL;
	return bst;
}

Node* insertion(Node* root,Contact c){
	if(root==NULL){
		return newNode(c);
	} else if(root->letter<c.name[0]){
		root->right=insertion(root->right,c);
	} else if (root->letter>c.name[0]){
		root->left=insertion(root->left,c);
	} else {
		insertOrdered(root->l,c);
	}
	return root;
}

int searchName(Node* root,char* str){
	if(root==NULL){
		return 0;
	}
	int answ;	
	if (root->letter<*str){
		answ=searchName(root->right,str);	
	} else if(root->letter>*str){
		answ=searchName(root->left,str);
	} else {
		answ=searchList(root->l,str);		
	}
	return answ;
}
