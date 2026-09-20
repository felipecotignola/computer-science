typedef struct{ 
	int valor;
	struct Celula* prox;
}Celula;
Celula* construtorCelula(int x){
	Celula* c=malloc(sizeof(Celula));
	c->valor=x;
	c->prox=NULL;
	return c;
}
typedef struct{
	Celula* topo;
}Stack;
Stack* construtorStack(){
	Stack* stack=malloc(sizeof(Stack));
	stack->topo=NULL;	
	return stack;
}
void push(Stack* stack,int x){
	Celula* c=construtorCelula(x);
	c->prox=stack->topo;
	stack->topo=c;	
}
Celula* pop(Stack* stack){
	if(stack->topo!=NULL){	
		Celula* resp=stack->topo; 
		stack->topo=resp->prox;
		return resp;	
	}
}
void print(Stack* stack){
	Celula* tmp=stack->topo;
	while(tmp!=NULL){
		printf("%d ",tmp->valor);
		tmp=tmp->prox;
	}
	printf("\n");
}

