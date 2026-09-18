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
	if(pos==(*l).q){
		inserirFim(l,x);
	}
	else if(pos==0){
		inserirInicio(l,x);
	}
	else{
		Celula* c=construtorCelula(x);
		Celula* tmp=(*l).p->prox;
		int i=0;
		while(i<pos-1 && i<(*l).q){
			tmp=tmp->prox;
			i++;
		}
		c->prox=tmp->prox;
		tmp->prox=c;
		(*l).q++;
	}
}
Celula* removerInicio(Lista* l){
	if((*l).q==1){
		Celula* c=(*l).u;
		(*l).p->prox=NULL;
		(*l).u=(*l).p;
		(*l).q--;
		return c;
	}
	else{		
		Celula* c=(*l).p->prox;
		(*l).p->prox=c->prox;
		(*l).q--;
		return c;
	}
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
	if(pos==(*l).q-1){
		removerFim(l);
	}
	else if(pos==0){
		removerInicio(l);
	}
	else{
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

