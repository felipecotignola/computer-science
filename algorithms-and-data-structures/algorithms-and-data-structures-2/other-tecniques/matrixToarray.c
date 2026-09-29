matrix[m][n]==array[m*n]

//an use for this technique is sorting and printing a matrix look:

sort(array);
int k=0;
for(int i=0;i<m;i++){
	for(int j=0;j<n;j++){
		printf("%d",array[k]);
		k++;
	}
}
