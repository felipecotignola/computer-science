#include<stdio.h>
typedef struct Participante{
	int pontuacao;
	int problemasResolvidos;	
	char nome[101];
}Participante;


int check(Participante a,Participante b){
	if(a.pontuacao>b.pontuacao){return 1;}
	else if(a.pontuacao<b.pontuacao){ return -1;}
	else {
		if(a.problemasResolvidos>b.problemasResolvidos){ return 1;}
		else if(a.problemasResolvidos<b.problemasResolvidos){return -1;}
		else { return 0;}
	}
}
void interscale(Participante* arr,int left,int middle,int right){
	int n1=middle-left+1,n2=right-middle;
	Participante* aux1=malloc(n1*sizeof(Participante));
	Participante* aux2=malloc(n2*sizeof(Participante));
	int k=left;
	for(int i=0;i<n1;i++){
		aux1[i]=arr[k];
		k++;
	}
	for(int i=0;i<n2;i++){
		aux2[i]=arr[k];
		k++;
	}
	k=left;
	int i=0,j=0;
	while(i<n1 && j<n2){
		int condition=check(aux1[i],aux2[j]);
		if(condition>=0){
			arr[k]=aux1[i];
			i++;
			k++;
		} else {
			arr[k]=aux2[j];
			j++;
			k++;
		}
	}
	while(i<n1){
		arr[k]=aux1[i];
		i++;
		k++;
	}
	while(j<n2){
		arr[k]=aux2[j];
		j++;
		k++;
	}
	free(aux1);
	free(aux2);
}
void mergesort(Participante* arr,int left,int right){
	if(left<right){
		int middle=(left+right)/2;
		mergesort(arr,left,middle);
		mergesort(arr,middle+1,right);
		interscale(arr,left,middle,right);
	}
}

int main(){
	
}
