	#include<stdio.h>
	//tamanho string
	int size(char* str){
		int cont=0;
		while(*str!='\0'){
			cont++;
			str++;
		}
		return cont;
	}
	//le a string e remove \n
	void readline(char* str,int tam){
		fgets(str,tam,stdin);
		if(str[size(str)-1]=='\n'){
			str[size(str)-1]='\0';
		}
	}
	char* inversion(char* str){
		int k=(size(str))-1;	
		int index=k;
		//eu crio um contador que marca o fim da string
		for(int i=0;i<=k/2;i++){
		//eu crio um for que roda ate a metade da string pq se rodasse ate o fim ia swappar duas vezes e ia restaurar a string
			char temp=str[i];
			str[i]=str[index];
			str[index]=temp;
			index--;	
			//eu swappo ate a length/2 pq eu tenho q trocar cada caractere inicial com  sua extremidade
		}
		return str;
	}	
	int main(){
		char string[256];
		readline(string,256);
		while(!(string[0]=='F' && string[1]=='I' && string[2]=='M' && size(string)==3)){ 
			printf("%s\n",inversion(string));
			readline(string,256);
		}
	}

