void selection(List* l){
	for(Node* i=l->h->next;i!=l->t;i=i->next){
		Node* smallest=i;
		for(Node* j=i->next;j!=NULL;j=j->next;){
			if(j->value<smalles->value){
				smallest=j;
			}
		}
		int temp=i->value;
		i->value=smallest->value;
		smallest->value=temp;	
	}
}
