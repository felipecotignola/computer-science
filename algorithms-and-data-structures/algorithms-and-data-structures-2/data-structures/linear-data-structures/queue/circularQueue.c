	typedef struct{
		int* array;
		int capacidade,quantidade;
	}Fila;
	void set(*Fila struct,int n){
		(*struct).array=malloc(n*sizeof(int));
		(*struct).capacidade=n;
		(*struct).quantidade=0;
	}
	void enqueue(*Fila struct,int n){
		if((*struct).quantidade==(*struct).capacidade){
			return;
		}
		(*struct).array[(*struct).quantidade]=n;
		(*struct).quantidade=(*struct).quantidade+1%(*struct).capacidade;
	}
	int dequeue(*Fila struct){
		if((*struct).quantidade==0){
			return -1;
		}
		(*struct).quantidade--;
		return (*struct).array[(*struct).inicio++];
	}
