#include <stdio.h>
#include <stdlib.h>
int main(){
    int n;
    scanf("%d",&n);
    for(int z=0;z<n;z++){
        int m;
        scanf("%d",&m);
        int* array=malloc(m*sizeof(int));
        int* sorted=malloc(m*sizeof(int));
        for(int i=0;i<m;i++){
            int numero;
            scanf("%d",&numero);
            array[i]=numero;
            sorted[i]=numero;
        }
        for(int i=1;i<m;i++){
            int key=sorted[i];
            int j=i-1;
            while(j>=0 && array[j]<key){
                array[j+1]=array[j];
                j--;
            }
            array[j+1]=key;
        }
        int cont=0;
        for(int i=0;i<m;i++){
            if(array[i]==sorted[i]){
                cont++;
            }
        }
        printf("%d\n",cont);
        free(array);
        free(sorted);
    }
    return 0;
}
