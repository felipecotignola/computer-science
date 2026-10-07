void interscale(int* array, int left,int middle,int right){
	int i=0,j=0,k=left;
	int aux1[middle-left+1],aux2[right-middle];
	int n1=middle-left+1,n2=right-middle;
	for(int l=0;l<n1;l++){
		aux1[l]=array[k];
		k++;
	}	
	for(int l=0;l<n2;l++){
		aux2[l]=array[k];
		k++;
	}
	k=left;
	while(i<n1 && j<n2){
		if(aux1[i]<aux2[j]{
			array[k]=aux1[i];
			i++;
		} else{
			array[k]=aux2[j];
			j++;
		}
		k++;	
	}
	while(i<n1){
		array[k]=aux1[i];
		i++;
		k++;
	}
	while(j<n2){
		array[k]=aux2[j];
		j++;
		k++;	
	}
}
void mergesort(int* array, int left,int right){
	if(left<dir){
		int middle=(left+right)/2;
		mergesort(esq,middle);
		mergesort(middle+1,right);
		interscale(left,middle,right);
	}
}
/*
	flaws: not in place (reqcuires extra memory aside of the array), and can be very expensive on memmory deppending on the size of the subarrays
	always o(n*lg(n))
	stable
*/
