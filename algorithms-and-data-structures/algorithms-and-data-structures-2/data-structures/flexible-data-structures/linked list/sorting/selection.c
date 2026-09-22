void selection(List* l){
	for(Celula* i=l->p->prox;i<l->u;i=i->prox){
		Celula* smallest=i;
		for(Celula* j=i->prox;j!=NULL;j=j->prox;){
			if(j->value<smalles->value){
				smallest=j;
			}
		}
		int temp=i->value;
		i->value=smallest->value;
		smallest->value=temp;	
	}
}
