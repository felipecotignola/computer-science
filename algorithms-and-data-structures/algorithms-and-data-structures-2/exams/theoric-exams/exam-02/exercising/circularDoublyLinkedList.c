Node* newNode(int x){
	Node* n=malloc(sizeof(Node));
	n->val=x;
	n->next=NULL;
	n->previous=NULL;
	return n;
}
void inserirFim(int x){
	if(first==NULL){
		first=newNode(x);
		return;
	}
	Node* tmp=first->previous;
	Node* n=newNode(x);
	tmp->next=n;
	n->next=first;
	first->previous=n;
	free(tmp);
}
