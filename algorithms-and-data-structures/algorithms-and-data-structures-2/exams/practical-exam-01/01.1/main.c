#include <stdio.h>
int strSize(char* str){
	int count=0;
	while(*str!=NULL){
		count++;
		str++;
	}
	return count;
}
void readline(char* str,int tam){
	fgets(str,tam,stdin);
	str[strSize(str)-1]='\0';
}
typedef struct{
	float altura;
	char nome[51];
}Participante;
Participante* newParticipante(){
	Participante* p=malloc(sizeof(Participante)); 
	scanf("%f",&(p.altura);
	getchar();
	readline(p.nome,51);	
	return p;
}
int check(Participante* key, Participante* p){
	if(key->altura<p->altura){
		return 1;
	}
	else{
		return 0;
	}
}
void sort(Participante* array,int q){
	for(int i=1;i<q;i++){
		Participante key=array[i];
		int j=i-1;
		while(j>=0 && check(key,array[j])){
			array[j+1]=array[j];
			j--;	
		}
		array[j+1]=key;
	}
}
int main(){
	int f,a;
	scanf("%d %d",&f,&a)
	Participante auditorio[f][a];
	int q=f*a;
	Participante* array=malloc(q*sizeof(Participante));
	for(int i=0;i<q;i++){
		array[i]=newParticipante;
	}	
	sort(array);
	int k=0;
	for(int i=0;i<f;i++){
		for(int j=0;j<a;j++){
			Auditorio[f][a]=array[k];
			k++;
		}	
	}
	for(int i=0;i<q;i++){
		printf("%d %.2f %s",i+1,array[i].altura,array[i].nome);
	}	
}

