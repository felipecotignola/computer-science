void insertionsort(List* l){
	for(Node* i=l->h->next;i!=NULL;i=i->next){
		int key=i->value;
		Node* j=i->ant;
		while(j!=NULL && key<j->value){
			j->next->value=j->value;
			j=j->ant;
		}
		if(j==NULL){
			l->h->value=key;
		} else {
			j->next->value=key;
		}
	}
}
