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
			p->prox=c;
			u=c;
			q++;	
		}
		else{
			c->prox=p->prox;
			p->prox=c;
			q++;
		}
	}
	void inserirFim(int x){
		Celula c=new Celula(x);
		if(q==0){
			p->prox=c;
			u=c;
			q++;	
		}
		else{
			u->prox=c;
			u=c;
			q++;
		}
	}
	void inserirPos(int x,int pos){
		if(pos>=0 && pos<=q){	
			Celula c=new Celula(x);
			Celula tmp=p;
			int i=0;
			while(i<q && i<pos-1){
				tmp=tmp->prox;
				i++;
			}
			c->prox=tmp->prox;
			tmp->prox=c;
			q++;
			if(pos==q){
				u=c;	
			}
		}	
	}
	Celula removerInicio(){
		Celula resp=p->prox;
		p=resp->prox;
		if(q==1){
			u=p;
		}
		q--;
		return resp;
	}
	Celula removerFim(){
		Celula resp=u;
		Celula tmp=p.prox;
		int i=0;
		while(i<q-1){
			tmp=tmp.prox;
			i++;	
		}
		tmp->prox=resp->prox;
		q--;
		return resp;
	}
	Celula removerPos(int pos){
		if(pos>=0 && pos<q){
			Celula tmp=p->prox;
			int i=0;
			while(i<pos-1){
				tmp=tmp->prox;
				i++;
			}
			Celula resp=tmp->prox;
			tmp.prox=resp->prox;
			return resp;	
		}	
	}
}
