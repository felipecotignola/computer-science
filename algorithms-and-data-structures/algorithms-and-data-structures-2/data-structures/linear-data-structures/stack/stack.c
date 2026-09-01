typedef struct{
	int* vet;
	int topo,capacidade;
}stack;
void construtor(stack* pilha, int n){
	(*pilha).topo=-1;
	(*pilha).capacidade=n;
	(*pilha).vet=malloc(n*sizeof(int));
}
void push(*stack pilha,int n){
	if((*pilha).topo>=(*pilha).capacidade){
		return;
	}
	(*pilha).vet[(*pilha).++topo]=n;	
}
int pop(*stack pilha){
	if((*pilha).topo<0){
		return;
	}
	int resp=(*pilha).vet[(*pilha).topo--];
	return resp;
}
int isVazia(*stack pilha){
	if((*pilha).topo==-1){
		return 1;
	}
	else{
		return 0;
	}
}
int size(){
	return (*pilha).topo+1;
}
