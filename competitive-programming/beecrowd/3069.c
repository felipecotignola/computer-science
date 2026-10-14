#include <stdio.h>
#include<stdlib.h>
typedef struct{
    int cmc,fim;
}Sorveteiro;
int main() {
    int p,s;
    scanf("%d %d",&p,&s);
    int teste=1;
    while(p!=0 && s!=0){
        printf("Teste %d\n",teste);
        teste++;
        Sorveteiro* array=malloc(s*sizeof(Sorveteiro));
        for(int i=0;i<s;i++){
            int u,v;
            scanf("%d %d",&u,&v);
            array[i].cmc=u;
            array[i].fim=v;
        }
        for(int i=1;i<s;i++){
            Sorveteiro key=array[i];
            int j=i-1;
            while(j>=0 && array[j].cmc>key.cmc){
                array[j+1]=array[j];
                j--;
            }
            array[j+1]=key;
        }
        int inicio=array[0].cmc;
        int fim=array[0].fim;
        for(int i=1;i<s;i++){
            if(fim>=array[i].cmc){
                if(fim<array[i].fim){
                    fim=array[i].fim;
                }
            }
            else{
                printf("%d %d\n",inicio,fim);
                inicio=array[i].cmc;
                fim=array[i].fim;
            }
        }
        printf("%d %d\n\n",inicio,fim);
        free(array);
        scanf("%d %d",&p,&s);
        
    }
 
    return 0;
}
