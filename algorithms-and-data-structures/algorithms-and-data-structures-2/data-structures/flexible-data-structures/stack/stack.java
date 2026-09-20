class Celula{
	int elemento
	Celula* prox;
	public Celula(int x){
		elemento=x;
		prox=null;
	}
}
class Stack{
	Celula* topo;
	public Stack(){
		topo=null;
	}
	void push(int x){
		Celula c=new Celula(x);
		c.prox=topo;
		topo=c;
	}
	void pop(){
		if(topo!=null){
			Celula resp=topo;
			topo=topo.prox;
			return resp;
		}
	}
	void print(){
		Celula tmp=topo;
		while(tmp!=null){
			printf("%d ",tmp.valor);
			tmp=tmp.prox;
		}
		printf("\n");
	}
}
