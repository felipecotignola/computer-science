void insertion(int[] array,int k){
	for(int i=0;i<array.length;i++){
		int key=array[i];
		int j;
		if(i<k){
			j=i-1;
		} else {
			j=k-1;
		}
		while(j>=0 && check(array,key,j)){
			array[j+1]=array[j];
			j--;
		}
		array[j+1]=key;	
	}
}
