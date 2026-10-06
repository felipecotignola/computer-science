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
/*
	best/medium case: o(n*lg(n))
		the array if divided by halve each function calling so the complexity is n times log n
		
	worst case: o(n²)
		 when the pivot is either the biggest or smallest element, so the partition gets completely unbalanced (one side with n-1 elements and the other empty), each calling of function removes only one number
	horrible for linked list since we need direct access to the pivot and in linked lists this would cost o(n) instead of o(1)

	
*/
