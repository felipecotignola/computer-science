void sort(List* l){
	for(Celula* i=l->prox->prox;i!=NULL;i=i->prox){
		int key=i->value;
		Celula* j=i->ant;
		while(j!=l->p && key<j->value){
			j->prox->value=j->value;
			j=j->ant;
		}
		j->prox->value=key;
	}
}
