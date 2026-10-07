void heapfy(int[] array, int n, int i){
	//current node	
	int biggest=i;
	//setting nodes sons
	int left=i*2+1;
	int right=i*2+2;
	//checking if the nodes indexes are valid
	if(left<n && array[left]>array[biggest]){
		biggest=left;	
	}
	if(right<n && array[right]>array[biggest]){
		biggest=right;
	}	
	//it either was a leaf (no sons) so biggest still equals to i
	//it had sons and one of them were bigger so biggest equals its index making it differ from the original node index
	//its sons were smaller
	if(biggest!=i){
		swap(array[i],array[biggest]);
		heapfy(array,n,biggest);
	}
}
void heapsort(int[] array){
	int n=array.length;
	//heap constructor, starts from the last node thats why we initialize i as (n/2)-1
	for(int i=(n/2)-1,i>=0;i--){
		//heap on current node
		heapfy(array,n,i);
	}
	//sorting/reconstruct/heapfy subarray
	for(int i=n-1;i>0;i--){
		swap(array[0],array[i];
		//heap on root
		heapfy(array,n,0);
	}
/*
	left son =index*2 +1
	right son = index*2 + 2
	treats an array as if it were an tree
	youll have to build and reconstruct the heap wich will sort the array
	heap max -> ascending sort, max value in the root
	heap min -> descending sort,
	o(n*lg(n))
	while quicksort has a quadratic worst case, heaps worst case is still n*log(n)	
	in average quicksort is better than heap, but its worse case is quadratic
	unstable
	
*/
