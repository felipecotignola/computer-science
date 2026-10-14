#include <stdio.h>
int size(char* str){
    int cont=0;
    while(*str!='\0'){
        cont++;
        str++;
    }
    return cont;
}
void readline(char* str,int tam){
    fgets(str,tam,stdin);
    if(str[size(str)-1]=='\n'){
        str[size(str)-1]='\0';
    }
}
int main() {
    int n;
    scanf("%d",&n);
    getchar();
    for(int i=0;i<n;i++){
        char str[1000];
        readline(str,1000);
        int tam=size(str),m1=0,d=0;
        for(int j=0;j<tam;j++){
            if(str[j]=='<'){
                m1++;
            }
            else if(str[j]=='>' && m1>0){
                m1--;
                d++;
            }
        }
        printf("%d\n",d);
    }
    return 0;
}
