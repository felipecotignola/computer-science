#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Contact{
	char name[51];
} Contact;

Contact newContact(char* str){
	Contact* c=malloc(sizeof(Contact));
	strcpy(c->name,str);
	Contact cntct=*c;
	free(c);
	return cntct;
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
		
}
typedef struct Node{
	char letter;
	List* l;
	struct Node* left;
	struct Node* right;
} Node;

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

Node* newBst(){
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
