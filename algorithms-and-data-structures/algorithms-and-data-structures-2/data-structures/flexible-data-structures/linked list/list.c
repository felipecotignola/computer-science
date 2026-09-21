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
	Celula* c=construtorCelula();
	c->prox=p;
	(*l).p->valor=x;	
	(*l).p=c;	
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
int removerInicio(Lista* l){
	if(l->p->prox!=null){
		Celula* tmp=(*l).p;
		(*l).p=tmp->prox; 
		free(tmp);
		(*l).q--;
		return (*l).p->valor;
	}
}
int removerFim(Lista* l){
	if(l->u!=l->p){	
		int resp=(*l)->u->valor;
		Celula* antigoFim=l->u;
		Celula* tmp=(*l).p->prox;
		int i=0;	
		while(i<(*l).q-1){
			tmp=tmp->prox;
			i++;
		}
		(*l).u=tmp;
		(*l).u->prox=NULL;
		free(antigoFim);
		return resp;	
	}
}
int removerPos(Lista* l,int pos){
	if(pos>=0 && pos<(*l).q){
		Celula* tmp=(*l).p->prox;
		int resp;
		int i=0;
		while(i<pos-1){
			tmp=tmp->prox;
			i++;
		}
		Celula* referencia=tmp->prox;
		resp=referencia->valor;
		tmp->prox=referencia->prox;
		free(referencia);
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

