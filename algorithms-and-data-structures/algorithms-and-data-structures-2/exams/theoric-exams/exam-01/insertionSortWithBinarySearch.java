int binarySearch(int key,int j){
	int left=0,right=j;
	while(left<=right){
		int mid=(left+right)/2;
		if(array[mid]==key){
			return mid;
		}	
		else if(array[mid]>key){
			right=mid-1;
		}
		else left=mid+1;
	}
	return mid;
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
