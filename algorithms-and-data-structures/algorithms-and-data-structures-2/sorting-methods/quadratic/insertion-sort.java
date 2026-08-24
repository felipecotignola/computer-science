for(int i=1;i<n;i++){
  int key=vet[i];
  int j=i-1;
	while((j>=0)&&(key<vet[j])){
		vet[j+1]=vet[j];
    		j--;
  	}
  	vet[j+1]=key;
}

/*
THE Best when slightly unsorted (becomes almost linear)
stable
in place
best case: n
medium case: n²
worst case: n²
*/
