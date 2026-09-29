typedef struct Celula{
	int valor;
	struct Celula* prox;
}Celula;
Celula* newCelula(int x){
	Celula* c=malloc(sizeof(Celula));
	c->valor=x;
	c->prox=NULL;
	return c;
}
typedef struct{
	Celula* topo;
}Stack;
Stack* newStack(int x){
	Stack* s=malloc(sizeof(Stack));
	Celula* c=newCelula(x);
	s->topo=c;
	return s;	
}
void push(Stack* s,int x){
	Celula* c=newCelula(x);
	c->prox=s->topo;
	s->topo=c;
}
int pop(Stack* s){
	int resp=s->topo->valor;
	Celula tmp=s->topo;
	s->topo=s->topo->prox;
	free(tmp);
	return resp;
}
