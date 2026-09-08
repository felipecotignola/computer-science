	for(int i=array.inicio;i!=array.fim;i++%array.capacidade){
		int smallest=i;
		for(int j=(i+1)%array.capacidade;j!=((array.fim)+1)%array.capacidade;j++%array.capacidade){
			if(array[j]<array[smallest]){
				smallest=j;
			}
		}
		int temp=array[i];
		array[i]=array[smallest];
		array[smallest]=temp;
	}
