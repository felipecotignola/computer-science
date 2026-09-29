class Celula{
	int elemento;
	Celula* prox;
	public Celula(int x){
		elemento=x;
		prox=null;
	}
}
class Stack{
	Celula* topo;
	public Stack(int x){
		topo=new Celula(x);
	}
	void push(int x){
		Celula c=new Celula(x);
		c.prox=topo;
		topo=c;
	}
	int pop(){
		int resp=topo.elemento;
		topo=topo->prox;
		return resp;
	}
}
