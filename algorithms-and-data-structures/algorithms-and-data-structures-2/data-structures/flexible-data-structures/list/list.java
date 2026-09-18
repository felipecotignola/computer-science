class Celula{
	int valor;
	Celula* prox;
	public Celula(int x){
		valor=x;
		prox=null;	
	}
}
class List{
	Celula* p;
	Celula* u;
	int q;
	public List(){
		Celula c=new Celula(-1);
		p=c;
		u=c;
		q=0;
	}
	void inserirInicio(int x){
		Celula c=new Celula(x);	
		if(q==0){

		}
	}
	void inserirFim(int x){

	}
	void inserirPos(int x,int pos){

	}
	Celula removerInicio(){

	}
	Celula removerFim(){

	}
	Celula removerPos(int pos){

	}
}
