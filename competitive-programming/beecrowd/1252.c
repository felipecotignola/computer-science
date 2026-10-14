#include <stdio.h>
#include <stdlib.h>
int sort(int m,int key,int number){
    if(key%m<number%m){
        return 1;
    }
    else if(key%m==number%m){
        if(key%2!=0 &&number%2==0){
            return 1;
        }
        else if(key%2!=0 && number%2!=0){
            return key>number;
        }
        else if(key%2==0 && number%2==0){
            return key<number;
        }
        else{
            return 0;
        }
    }
    else{
        return 0;
    }
}
int main() {
    int n,m;
    scanf("%d %d",&n,&m);
    while(n!=0 && m!=0){
        int* array=malloc(n*sizeof(int));
        for(int i=0;i<n;i++){
            int number;
            scanf("%d",&number);
            array[i]=number;
        }
        for(int i=1;i<n;i++){
            int key=array[i];
            int k=i-1;
            while(k>=0 && sort(m,key,array[k])){
                array[k+1]=array[k];
                k--;
            }
            array[k+1]=key;
        }
        printf("%d %d\n",n,m);
        for(int i=0;i<n;i++){
            printf("%d\n",array[i]);
        }
        free(array);
        scanf("%d %d",&n,&m);
    }
    printf("%d %d\n",n,m);
    return 0;
}
