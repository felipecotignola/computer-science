void insertionsort(List* l){
	for(Node* i=l->h->next;i!=NULL;i=i->next){
		int key=i->value;
		Node* j=i->ant;
		while(j!=l->h && key<j->value){
			j->next->value=j->value;
			j=j->ant;
		}
		j->next->value=key;
	}
}
