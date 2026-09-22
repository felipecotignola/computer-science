void remove(Lista* l){
	for(Celula* i=l->p->prox;i!=NULL;i=i->prox){
		for(int j=i->prox;j!=NULL;j=j->prox){
			if(i->value==j->value){
				if(j==l->u){
					j->ant->prox=null;
					j->ant=l->u;
					free(j);	
				}
				else{	
					j->ant->prox=j->prox;
					if(j->prox!=null){
						j->prox->ant=j->ant;
					}
					j->prox=null;
					j->ant=null;
					free(j);
				}
			}
		}
	}
}
