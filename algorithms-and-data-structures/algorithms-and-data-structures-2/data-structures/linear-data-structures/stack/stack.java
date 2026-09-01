class Stack[
	int[] array;
	int topo,capacidade;
	public Stack(int n){
		array=new int[n];
		topo=-1,capacidade=n;
		
	}
	void empilhar(int n){
		if(topo>=capacidade){
			return;
		}
		array[++topo]=n;	
	}
	int desempilhar(){
		if(topo<0){
			return;
		}
		int resp=array[topo--];	
		return resp;
	}
	boolean isVazia(){
		return topo==-1;
	}
	int tamanho(){
		return topo+1;
	}
	
}
