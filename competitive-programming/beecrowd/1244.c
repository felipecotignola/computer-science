#include <stdio.h>
int len(char* str){
    int cont=0;
    while(*str!='\0'){
        cont++;
        str++;
    }
    return cont;
}
void readline(char* str,int tam){
    fgets(str,tam,stdin);
    if(str[len(str)-1]=='\n'){
        str[len(str)-1]='\0';
    }
}
int main(){
    int n;
    scanf("%d",&n);
    getchar();
    for(int i=0;i<n;i++){
        char str[1000];
        readline(str,1000);
        char array[50][1000];
        int arrayIndex=0,charIndex=0;
        for(int j=0;str[j]!='\0';j++){
            if(str[j]==' '){
                array[arrayIndex][charIndex]='\0';
                arrayIndex++;
                charIndex=0;
            }
            else{
                array[arrayIndex][charIndex]=str[j];
                charIndex++;
            }
        }
        array[arrayIndex][charIndex]='\0';
        char* ordem[arrayIndex+1];
        for(int j=0;j<=arrayIndex;j++){
            ordem[j]=array[j];
        }
        for(int j=1;j<=arrayIndex;j++){
            char* key=ordem[j];
            int l=j-1;
            while(l>=0 &&len(ordem[l])<len(key)){
                ordem[l+1]=ordem[l];
                l--;
            }
            ordem[l+1]=key;
        }
        for(int j=0;j<=arrayIndex;j++){
            printf("%s",ordem[j]);
            if(j<arrayIndex){
                printf(" ");
            }
        }
        printf("\n");
    }
}
            
        
    
