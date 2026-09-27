void binarySearch(int key,int j){
	int esq=0,dir=j;
	while(esq<=dir){
		int meio=(esq+dir)/2;
		if(array[meio]==key){
			return meio;
		}	
		else if(array[meio]>key){
			dir=meio-1;
		}
		else esq=meio+1;
	}
	return meio;
}
void insertion sort(){
	for(int i=1;i<n;i++){
		int key=array[i];
		int j=i-1;
		int pos=binarySearch(key,j);
		while(j>=pos){
			array[j+1]=array[j];
			j--;
		}
		array[pos]=key;
	}
}
