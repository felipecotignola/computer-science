Cell* newCell(int x){
	Cell* c=malloc(sizeof(Cell));
	c->val=x;
	c->next=NULL;
	return c;
}
void insert(Cell* h,int x){
	Cell* cell=newCell(x);
	if(head->next==NULL){
		head->next=cell;
		return;
	}	
	Cell* tmp=head;
	while(tmp!=NULL && tmp->next->val>x){
		tmp=tmp->next;
	}
	cell->next=tmp->next;
	tmp->next=cell;	
}
int find(Node* root,int target){ 
	if(root==NULL){
		return 0;
	} else if(root->val==target){
		return 1;
	}
	return find(root->right,target) || find(root->left,target);	
}
Cell* newList(Matrix* m,Node* root){
	Cell* c=newCell(-1);
	for(Cell* i=m->start;i!=NULL;i=i->lower){
		for(Cell* j=i;j!=NULL;j=j->right){
			if(find(root,j->val)){
				insert(c->next,j->val);	
			}
		}
	}
	return c->next;
}
Cell* encontrarRepetidos(Node* root,Matrix* m){
	Cell* list=newList(m,root);		
	return list;
}
