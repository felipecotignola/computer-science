#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void readline(char* s,int size){
	if(fgets(s,size,stdin)!=NULL){
		s[strlen(s)-1]='\0';
	}
}
typedef struct Node{
	int id;
	char name[51];
	struct Node* left;
	struct Node* right;
} Node;

Node* newNode(int id,char* s){
	Node* n=malloc(sizeof(Node));
	n->id=id;
	strcpy(n->name,s);
	n->left=NULL;
	n->right=NULL;
	return n;
}

typedef struct Bst{
	Node* root;
} Bst;

Bst* newBst(){
	Bst* root=malloc(sizeof(Bst));
	root->root=NULL;
	return root;
}
Node* insertion(Node* root,int id,char* s){
	if(root==NULL){
		return newNode(id,s);
	} else if (root->id<id){
		root->right=insertion(root->right,id,s);
	} else {
		root->left=insertion(root->left,id,s);
	}
	return root;
}

int getLeafs(Node* root){
	if(root==NULL){
		return 0;
	} else if(root->left==NULL && root->right==NULL){
		return 1;
	}
	int leafs=getLeafs(root->left)+getLeafs(root->right);
	return leafs;	
}

void postOrder(Node* root){
	if(root==NULL){
		return;
	}
	postOrder(root->left);
	postOrder(root->right);
	printf("%s\n",root->name);
}

int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		Bst* bst=newBst();
		for(int i=0;i<n;i++){
			int id;
			char name[51];
			scanf("%d",&id);	
			getchar();
			readline(name,51);
			bst->root=insertion(bst->root,id,name);
		}
		printf("%d\n",getLeafs(bst->root));
		postOrder(bst->root);
	}
}
