class Stack[
	int[] array;
	int topo,capacidade;
	public Stack(int n){
		array=new int[n];
		topo=-1,capacidade=n;
		
	}
	void push(int n){
		if(topo>=capacidade){
			return;
		}
		array[++topo]=n;	
	}
	int pop(){
		if(topo<0){
			return;
		}
		int resp=array[topo--];	
		return resp;
	}
	boolean isVazia(){
		return topo==-1;
	}
	int size(){
		return topo+1;
	}
	
}
