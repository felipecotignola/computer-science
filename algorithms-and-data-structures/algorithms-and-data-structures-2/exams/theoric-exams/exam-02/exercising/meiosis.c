Node* newNode(int x){
	Node* n=malloc(sizeof(Node));
	n->val=x;
	n->next=NULL;
	return n;
}
void append(Node* n){
	Node* node=newNode(n->val/2);
	n->val=n->val/2;	
	node->next=n->next;
	n->next=node;
}
void meiosis(){
	Node* tmp=start;
	while(tmp!=NULL){
		append(tmp);
		tmp=tmp->next->next;
	}
}
