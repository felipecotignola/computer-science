	#include<stdio.h>
	//tamanho da string
	int tam(char* str){
		int cont=0;
		while(*str!='\0'){
			cont++;
			str++;
		}
		return cont;
	}
	//le string e tira caractere
	void readline(char* str,int size){
		fgets(str,size,stdin);
		str[tam(str)-1]=='\0';
	}
	//como estou trabalhando com ponteiro eu n preciso retornar nada cada alteracao na string eh feita diretamente no endereco do caractere
	//eu vou passando a variavel str que aponta para o caractere atual somo 3 ao valor apontado por ele e passo por parametro o proximo endereco de caractere e eu faço isso ate o valor apontado pelo ponteiro ser '\0'
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
