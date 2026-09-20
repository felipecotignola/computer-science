typedef struct{
	int valor;
	struct Celula* prox;
}Celula;
Celula* construtorCelula(int x){
	Celula* c=malloc(sizeof(Celula));
	(*c).valor=x;
	(*c).prox=NULL;
	return c;	
}
typedef struct{
	Celula* p;
	Celula* u;
	int q;
}Lista;
Lista* construtorLista(){
	Lista* l=malloc(sizeof(Lista));
	Celula* c=construtorCelula(-1);
	(*l).p=c;
	(*l).u=c;
	(*l).q=0;
	return l;
}
void inserirInicio(Lista* l,int x){
	Celula* c=construtorCelula(x);
	if((*l).q==0){
		c->prox=(*l).u->prox;
		(*l).u->prox=c;
		(*l).u=c;
		(*l).q++;
	}
	else{
		c->prox=(*l).p->prox;
		(*l).p->prox=c;
		(*l).q++;	
	}
	
}
void inserirFim(Lista* l,int x){		
	Celula* c=construtorCelula(x);
	(*l).u->prox=c;
	(*l).u=c;
	(*l).q++;
}
void inserirPos(Lista* l,int x,int pos){
		if(pos>=0 && pos<=l->q){	
			Celula* c=construtorCelula(x);
			Celula* tmp=(*l).p;
			int i=0;
			while(i<pos-1){
				tmp=tmp->prox;
				i++;
			}
			c->prox=tmp->prox;
			tmp->prox=c;
			(*l).q++;
			if(pos==(*l).q){
				l->u=c;
			}	
		}
}
Celula* removerInicio(Lista* l){
	Celula resp=(*l).p->prox;
	(*l).p=resp->prox;
	if((*l).q==1){
		(*l).u=(*l).p;
	}
	(*l).q--;
	return resp;
}
Celula* removerFim(Lista* l){
	Celula* c=(*l)->u;	
	Celula* tmp=l->prox;
	int i=0;
	while(i<(*l).q-1){
		tmp=tmp->prox;	
		i++;
	}
	tmp->prox=NULL;
	(*l).q--;
	return c;
}
Celula* removerPos(Lista* l,int pos){
	if(pos>=0 && pos<(*l).q){
		Celula* tmp=(*l).p->prox;
		Celula* resp;
		int i=0;
		while(i<pos-1){
			tmp=tmp->prox;
			i++;
		}
		resp=tmp->prox;
		tmp->prox=resp->prox;
		return resp;
	}	
}
void print(Lista* l){
	Celula* tmp=(*l).p->prox;
	while(tmp!=NULL){
		printf("%d ",tmp->valor);
		tmp=tmp->prox;
	}
	printf("\n");
}

