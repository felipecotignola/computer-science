void interscale(int left,int middle,int right){
	
}
void mergesort(int left,int right){
	if(left<dir){
		int meio=(left+right)/2;
		mergesort(esq,middle);
		mergesort(middle+1,right);
		interscale(left,middle,right);
	}
}
/*
	flaws: not in place (reqcuires extra memory aside of the array), and can be very expensive on memmory deppending on the size of the subarrays
	best for linked list
*/
