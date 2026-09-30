void quicksort(int left,int right){
	int i=left, j=right, pivot=array[(left+right)/2];
	while(i<=j){
		while(array[i]<pivot){
			i++;
		}
		while(array[j]>pivot){
			j--;
		}
		if(i<=j){
			temp=array[i];
			array[i]=array[j];
			array[j]=temp;
			i++;
			j--;
		}
	}
	if(left<j){
		quicksort(left,j);
	}
	if(right>i){
		quicksort(i,right);
	}
}
