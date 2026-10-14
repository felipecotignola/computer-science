#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct{
    char str[256];
    int weight,age;
    float height;
}Reindeers;
void strCopy(char* destino,char* origem){
    while(*origem!='\0'){
        *destino=*origem;
        destino++;
        origem++;
    }
    *destino='\0';
}
void setReindeer(Reindeers* r,char* str,int w,int a,float h){
    strCopy((*r).str,str);
    (*r).weight=w;
    (*r).age=a;
    (*r).height=h;
}

int conditions(Reindeers* array,Reindeers key,int j){
    if(key.weight>array[j].weight){
        return 1;
    }
    else if(key.weight==array[j].weight){
        if(key.age<array[j].age){
            return 1;
        }
        else if(key.age==array[j].age){
            if(key.height<array[j].height){
                return 1;
            }
            else if(key.height==array[j].height){
                if(strcmp(key.str,array[j].str)<0){
                    return 1;
                }
                else{
                    return 0;
                }
            }
            else{
                return 0;
            }
        }
        else{
            return 0;
        }
    }
    else{
        return 0;
    }
}
void sort(Reindeers* array,int n){
    for(int i=1;i<n;i++){
        Reindeers key= array[i];
        int j=i-1;
        while(j>=0 && conditions(array,key,j)){
            array[j+1]=array[j];
            j--;
        }
        array[j+1]=key;
    }
}
int main() {
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++){
        printf("CENARIO {%d}\n",i);
        int n,m;
        scanf("%d %d",&n,&m);
        Reindeers* totalArray=malloc(n*sizeof(Reindeers));
        char str[256];
        int w,a;
        float h;
        for(int j=0;j<n;j++){
            scanf("%s %d %d %f",str,&w,&a,&h);
            setReindeer(&totalArray[j],str,w,a,h);
        }
        sort(totalArray,n);
        for(int j=0;j<m;j++){
            printf("%d - %s\n",j+1,totalArray[j].str);
        }
        free(totalArray);
    }
    return 0;
}
