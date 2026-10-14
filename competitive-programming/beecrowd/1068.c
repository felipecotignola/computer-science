#include <stdio.h>
int tam(char* str){
    int c=0;
    while(*str!='\0'){
        c++;
        str++;
    }
    return c;
}
int readline(char* str,int size){
    if(fgets(str,size,stdin)==NULL){
        return 0;
    }
    int t=tam(str)-1;
    if(str[t]=='\n'){
        str[t]='\0';
    }
    return 1;
}
int main() {
    char str[1001];
    while(readline(str,1001)){
        int c1=0,c2=0;
<<<<<<< HEAD:beecrowd/1068.c
        char str[1001];
        readline(str,1001);
=======
>>>>>>> 475ba04c38a929ca7334ce411acb7eca7d5b6b14:beecrowd/data-structures-and-libraries/1068.c
        int parar=0;
        for(int i=0;str[i]!='\0' && parar==0;i++){
            if(str[i]==')'){
                if(c1<=0){
                 parar=1;
                }
                else{
                    c2++;
                    if(c2>c1){
                        parar=1;
                    }
                }
                
            }
            else if(str[i]=='('){
                c1++;
            }
        }
<<<<<<< HEAD:beecrowd/1068.c
        if(c1==c2){
=======
        if(c1==c2 && parar==0){
>>>>>>> 475ba04c38a929ca7334ce411acb7eca7d5b6b14:beecrowd/data-structures-and-libraries/1068.c
            printf("correct\n");
        }
        else{
            printf("incorrect\n");
        }
    }
    return 0;
}
