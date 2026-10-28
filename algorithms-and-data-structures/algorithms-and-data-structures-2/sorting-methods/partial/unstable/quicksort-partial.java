void quicksort(int[] array,int left,int right,int k){
	int i=left;
	int j=right;
	int pivot=array[(left+right)/2];
	while(i<=j){
		while(i<=j && array[i]<pivot){
			i++;
		}
		while(i<=j && array[j]>pivot){
			j--;
		}
		if(i<=j){
			swap(array,i,j);
			i++;
			j--;
		}
	}
	if(left<j){
		quicksort(array,left,j,k);
	}
	if(i<k && i<right){
		quicksort(array,i,right,k);
	}
}
