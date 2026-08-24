	#include<stdio.h>
	int tam(char* str){
		int cont=0;
		while(*str!='\0'){
			cont++;
			str++;
		}
		return cont;
	}
	void readline(char* str,int size){
		fgets(str,size,stdin);
		str[tam(str)-1]=='\0';
	}
	void cypher(char* str){
		if(*str=='\0'){ 
			return;
		}
		*str+=3;
		cypher(str+1);	
	}
	int main(){
		char str[256];
		readline(str,256);
		cypher(str);
		printf("%s\n",str);
	}
