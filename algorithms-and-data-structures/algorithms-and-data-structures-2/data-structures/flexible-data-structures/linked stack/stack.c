typedef struct Node{
	int value;
	struct Node* next;
}Node;
Node* newNode(int x){
	Node* n=malloc(sizeof(Celula));
	n->value=x;
	n->next=NULL;
	return n;
}
typedef struct{
	Node* top;
}Stack;
Stack* newStack(int x){
	Stack* s=malloc(sizeof(Stack));
	Celula* c=newCelula(x);
	s->topo=c;
	return s;	
}
void push(Stack* s,int x){
	Node* n=newNode(x);
	n->next=s->top;
	s->top=n;
}
int pop(Stack* s){
	int answ=s->top->value;
	Node* tmp=s->top;
	s->top=s->top->next;
	free(tmp);
	return answ;
}
