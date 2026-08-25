	#include<stdio.h>
	int substring(char* str){
		int vet[256];
		//eu crio um vetor que ira armazenar o indice de quando cada caractere ocorre e inicializo cada posicao como -1 para dizer que nenhuma apareceu ainda
		for(int i=0;i<256;i++){
			vet[i]=-1;
		}
		int inicio=0,tam=0,maxTam=tam;
		for(int i=0;str[i]!='\0';i++){
			//se a ultima vez que esse caractere aparece eh dps do inicio quer dizer que ele repetiu ent atualizamos o inicio
			if(vet[str[i]]>=inicio){
				inicio=vet[str[i]]+1;
			}
			//como n passou no if quer dizer q o caractere ainda n apareceu desde o inicio da substring entao marcamos no vetor o indice de quando esse caractere apareceu e eu atualizo o tamanho da substring
			vet[str[i]]=i;
			tam=i-inicio+1;
			if(tam>maxTam){
				maxTam=tam;
			}	
		}
		return maxTam;
	}
	//tamanho da string
	int strln(char* str){
		int cont=0;
		while(*str!='\0'){
			cont++;
			str++;
		}
		return cont;
	}
	//leio a string e tiro o \n
	void readline(char* str,int tam){
		fgets(str,255,stdin);
		str[strln(str)-1]='\0';
	}
	int main(){
		char str[255];
		readline(str,255);
		printf("%d",substring(str));	
	}
