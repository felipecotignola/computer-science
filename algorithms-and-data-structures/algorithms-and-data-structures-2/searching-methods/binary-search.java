int dir=array.length-1;
int esq=0;
int meio=(esq+dir+1)/2;
while(esq<=dir){
    if(array[meio]==resp){
        return meio;
    }
    else{
        if(vet[meio]>resp){
            dir=meio-1;
            meio=(esq+dir+1)/2;
        }
        else{
            esq=meio+1;
            meio=(esq+dir+1)/2;
        }
    }
}

 
