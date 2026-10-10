int  left=0,right=array.length-1;
while(left<=right){
    int mid=(left+right+1)/2;
    if(array[mid]==target){
        return mid;
    }
    else{
        if(vet[mid]>target){
            right=mid-1;
        }
        else{
            left=mid+1;
        }
    }
}

 
