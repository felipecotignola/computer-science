for(int i=0;i<n-1;i++){
  smallest=i;
  for(int j=i+1;j<n;j++){
    if(array[j]<array[smallest]){
      smallest=j;
    }
  }
  swap(i,smallest);
}

/*
best for heavy swaps projects since it does o(n) swaps
not stable
in place
does less swaps but tons of comparisons (still does n² comparisons in almost sorted arrays)
best case: n²
medium case: n²
worst case: n²
*/
