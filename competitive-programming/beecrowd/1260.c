#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int readline(char* str,int size){
	if(fgets(str,size,stdin)==NULL){
		return -1;
	}
	if(str[strlen(str)-1]=='\n'){
		str[strlen(str)-1]=='\0';
		return 0;
	}
}
typedef struct Node{
	char specie[31];
	int q;
	struct Node* left;
	struct Node* right;	
}Node;
Node* newNode(char* str){
	Node* n=malloc(sizeof(Node));
	strcpy(n->specie,str);
	n->q=1;
	n->left==NULL;
	n->right==NULL;
	return n;
}
typedef struct Bst{
	Node* root;
}Bst;
Node* insert(Node* root,char* specie){
	if(root==NULL){
		Node* n=newNode(specie);
		n->q++;
		return n;
	} else {
		if(strcmp(root->specie,specie)<0){
			root->right=insert(root->right,specie);
		} else if(strcmp(root->specie,specie)>0) {
			root->left=insert(root->left,specie);
		} else {
			root->q++;
		}
	}	
	return;
}
void print(Node* root){
	if(root==NULL){
		return;
	} else {
		print(root->left);
		//printf
		print(root->right);
	}
	return;
}
int main(){
	int n;
	getchar();
	getchar();
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		Bst* bst=malloc(sizeof(Bst));
		char specie[31]; 
		while(readline(specie,31)!=0){
			bst->root=insert(bst->root,specie);	
		}
		print(bst->root);
		getchar();
		getchar();
	}
}
