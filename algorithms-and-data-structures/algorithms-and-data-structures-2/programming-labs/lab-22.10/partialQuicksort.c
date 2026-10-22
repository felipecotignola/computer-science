#include <stdio.h>
#include<string.h>
#include <stdlib.h>
typedef struct Aluno{
	int nota;
	int falta;
	char nome[51];	
}Aluno;

Aluno newAluno(int nota,int falta, char* str){
	Aluno* a=malloc(sizeof(Aluno));
	aluno->nota=nota;
	aluno->falta=falta;
	strcpy(&(a->nome),str);
	return a;
}

void quicksort(Aluno* arr,int left,int right,int k){
	int i=left,j=right;
	int pivoNota=arr[(left+right)/2]->nota;
	int pivoFalta=arr[(left+right)/2]->falta;
	char pivoNome[51];
	strcpy(pivoNome,arr[(left+right)/2]->nome);
	
}
void print(Aluno* arr){
	
}
int getSize(char* str){
	int cont=0;
	while(str!='\0'){
		cont++;
		str++;
	}
	return cont;
}
void readline(char* str,int size){
	fgets(str,size,stdin);
	str[getSize(str)-1]='\0';	
}
int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		Aluno* array=malloc(n*sizeof(Alun));
		int nota,falta;
		char nome[51];
		for(int i=0;i<n;i++){
			scanf("%d %d",&nota,&falta);
			getchar();
			readline(nome);
			array[i]=newAluno(nota,falta,nome);
			
		}
		quicksort(array,0,n-1,k);
		print(array);
	}
}
