void selection(int[] array, int k){
	for(int i=0;i<k;i++){
		int min=i;
		for(int i=0;i<array.length;i++){
			if(array[j]<array[min]){
				min=j;
			}
		}
		swap(array,i,min);
	}
}
