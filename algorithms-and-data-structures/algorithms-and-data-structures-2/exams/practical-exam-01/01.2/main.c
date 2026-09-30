#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Predio{
	int numero;
	char nome[31];
}Predio;
Predio newPredio(int numero,char* str){
	Predio predio;
	predio.numero=numero;
	strcpy(predio.nome,str);
	return predio;
}
int condition(Predio key,Predio p){
	if(strcmp(key.nome,p.nome)<0){
		return 1;
	}
	else{
		return 0;	
	}
}
void sort(Predio* array,int n){
	for(int i=1;i<n;i++){
		Predio key=array[i];
		int j=i-1;
		while(j>=0 && condition(key,array[j])){
			array[j+1]=array[j];
			j--;	
		}
		array[j+1]=key;
	}
}
int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		int p;
		scanf("%d",&p);
		Predio array[p];
		int numero;
		char nome[31];
		for(int i=0;i<p;i++){
			scanf("%d",&numero);
			scanf("%s",nome);
			array[i]=newPredio(numero,nome);
		}
		sort(array,p);
		for(int i=0;i<p;i++){
			printf("%s %d\n",array[i].nome,array[i].numero);
		}	
	}
}
