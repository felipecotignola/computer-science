#include <stdio.h>
#include<string.h>
#include <stdlib.h>
typedef struct Aluno{
	int nota;
	int falta;
	char nome[51];	
}Aluno;

Aluno newAluno(int nota,int falta, char* str){
	Aluno* aluno=malloc(sizeof(Aluno));
	aluno->nota=nota;
	aluno->falta=falta;
	strcpy((aluno->nome),str);
	return *aluno;
}
int check(Aluno a,int nota,int falta,char* nome){
	if(a.nota<nota){return 1;}
	if(a.nota>nota){return -1;}
	if(a.falta<falta){return -1;}
	if(a.falta>falta){return 1;};
	return strcmp(a.nome,nome);	
}
void quicksort(Aluno* arr,int left,int right,int k){
	int i=left,j=right;
	int pivoNota=arr[(left+right)/2].nota;
	int pivoFalta=arr[(left+right)/2].falta;
	char pivoNome[51];
	strcpy(pivoNome,arr[(left+right)/2].nome);
	while(i<=j){
		while(i<=j && check(arr[i],pivoNota,pivoFalta,pivoNome)<0){
			i++;
		}
		while(i<=j && check(arr[j],pivoNota,pivoFalta,pivoNome)>0){
			j--;
		}
		if(i<=j){
			Aluno tmp=arr[i];
			arr[i]=arr[j];
			arr[j]=tmp;
			i++;
			j--;	
		}
	}
	if(left<j){
		quicksort(arr,left,j,k);
	}
	if(i<=k && i<right){
		quicksort(arr,i,right,k);
	}	
}
void print(Aluno* arr,int k){
	for(int i=0;i<k;i++){
		printf("%d %d %s\n",arr[i].nota,arr[i].falta,arr[i].nome);
	}	
}
int getSize(char* str){
	int cont=0;
	while(*str!='\0'){
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
		int k;
		scanf("%d",&k);
		Aluno* array=malloc(n*sizeof(Aluno));
		int nota,falta;
		char nome[51];
		for(int i=0;i<n;i++){
			scanf("%d %d",&nota,&falta);
			getchar();
			readline(nome,51);
			array[i]=newAluno(nota,falta,nome);
			
		}
		quicksort(array,0,n-1,k-1);
		print(array,k);
	}
}
