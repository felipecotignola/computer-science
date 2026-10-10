for(int i=(array.beggining+1)%array.capacity;i!=array.end;i=(i+1)%array.capacity){
	int key=array[i];
	int j=(i-1+array.capacity)%array.capacity;
	while(j!=(array.beggining-1+array.capacity)%array.capacity && key<array[j]){
		array[(j+1)%array.capacity]=array[j];
		j=(j-1+array.capacity)%array.capacity;	
	}
	array[(j+1)%array.capacity]=key;
}
