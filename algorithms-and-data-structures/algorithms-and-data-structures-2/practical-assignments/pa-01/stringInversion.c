	#include<stdio.h>
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
		str[size(str)-1]='\0';
	}
	char* inversion(char* str){
		int k=(size(str))-1;	
		for(int i=0;i<size(str)/2;i++){
			char temp=str[i];
			str[i]=str[k];
			str[k]=temp;
			k--;	
		}
		return str;
	}	
	int main(){
		char string[256];
		readline(string,256);
		printf("%s\n",inversion(string));
	}
