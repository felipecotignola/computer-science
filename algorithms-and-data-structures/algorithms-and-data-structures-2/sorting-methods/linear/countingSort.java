	static void countingSort(int[] array){
		int min=array[0],max=array[0];
		
		//find min and max values
		for(int i=1;i<array.length;i++){
			if(array[i]<min){
				min=array[i];
			}
			if(array[i]>max){
				max=array[i];
			}
		}
		
		//setting up k
		int k=max-min+1;
		int[] count=new int[k];
		
		//count occurrences
		for(int i=0;i<array.length;i++){
			count[array[i]-least]++;
		}
		
		//rebuilding sorted array
		int pos=0;
		for(int i=0;i<k;i++){
			while(count[i]>0){
				array[pos]=i+menor;
				pos++;
				count[i]--;
			}
		}
	}
/*
n==size of array
k==MAX-MIN+1

best case: o(n+k)
medium case: o(n+k)
worst case: o(n+k)

bad when k is too big
migth spend to much memory deppending on k value

best when theres many elements in one small value gap
really fast quen k is small in comparison to n

counts how many times each value appears then construct the array in order
*/
