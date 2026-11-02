public static int[] sortedArray(int[] a,int[] b){
	int sizeA=a.length;
	int sizeB=b.length;
	int[] c=new int[sizeA+sizeB];
	int i=sizeA+sizeB-1;
	int j=0;
	int k=0;
	while(j<sizeA && k<sizeB){	
		if(a[j]>=b[k]){
			c[i]=a[j];
			j++;
			i--;
		} else {
			c[i]=b[k];
			k++;
			i--;
		}
	}
	while(j<sizeA){
		c[i]=a[j];
		i--;
		j++;
	}
	while(k<sizeB){
		c[i]=b[k];
		i--;
		k++;
	}
	return c;
}
