for(int i=(array.inicio+1)%array.capacidade;i!=(array.fim+1)%capacidade;i=(i+1)%array.capacidade){
	int key=array[i];
	int j=(i-1+array.capacidade)%array.capacidade;
	while(j!=(array.inicio-1+array.capacidade)%array.capacidade && key<array[j]){
		array[(j+1)%array.capacidade]=array[j];
		j=(j-1+array.capacidade)%array.capacidade;	
	}
	array[(j+1)%array.capacidade]=key;
}
