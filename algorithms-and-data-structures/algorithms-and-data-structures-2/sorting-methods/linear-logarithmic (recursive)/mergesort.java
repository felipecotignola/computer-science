void interscale(int[] array, int left,int middle,int right){
	
}
void mergesort(int[] array, int left,int right){
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
