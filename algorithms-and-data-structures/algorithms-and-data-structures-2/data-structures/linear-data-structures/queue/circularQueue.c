	typedef struct{
		int* array;
		int inicio,fim,capacidade,quantidade;
	}Fila;
	void set(*Fila struct,int n){
		(*struct).array=malloc(n*sizeof(int));
		(*struct).inicio=0;
		(*struct).fim=-1;
		(*struct).capacidade=n;
		(*struct).quantidade=0;
	}
	void enqueue(*Fila struct,int n){
		if((*struct).quantidade==(*struct).capacidade){
			return;
		}
		(*struct).array[(*struct).++fim]=n;
		(*struct).quantidade++;
	}
	int dequeue(*Fila struct){
		if((*struct).quantidade==0){
			return -1;
		}
		(*struct).quantidade--;
		return (*struct).array[(*struct).inicio++];
	}
