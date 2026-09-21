	typedef struct{
		int* array;
		int inicio,pos,capacidade,quantidade;
	}Fila;
	void set(*Fila struct,int n){
		(*struct).array=malloc(n*sizeof(int));
		(*struct).capacidade=n;
		(*struct).quantidade=0;
		(*struct).pos=0;
		(*struct).inicio=0;
	}
	void enqueue(*Fila struct,int n){
		if((*struct).quantidade==(*struct).capacidade){
			return;
		}
		(*struct).array[(*struct).pos]=n;
		(*struct).pos=(*struct).pos+1%(*struct).capacidade;
		(*struct).quantidade++;
	}
	int dequeue(*Fila struct){
		if((*struct).quantidade==0){
			return -1;
		}
		(*struct).quantidade--;
		return (*struct).array[(*struct).inicio++];
	}
