for(int i=array.inicio;i!=array.fim;i=(i+1)%array.capacidade){
	int smallest=i;
	for(int j=(i+1)%array.capacidade;j!=(array.fim+1)%capacidade;j=(j+1)%array.capacidade){
		if(array[j]<array[smallest]){
			smallest=j;
		}
	}
	int tmp=array[i];
	array[i]=array[smallest];
	array[smallest]=tmp;
}
