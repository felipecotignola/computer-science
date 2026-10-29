#include <stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct Hack{
 	int data;
	int q;
	char nome[51];
}Hack;
int readline(char* str,int size){
	if(fgets(str,size,stdin)==NULL){
		return 0;	
	}
	int l=strlen(str);
	if(str[l-1]=='\n'){
		str[l-1]='\0';
	}	
	return 1;
}
Hack newHack(int data,int q,char* nome){
	Hack* h=malloc(sizeof(Hack));
	h->data=data;
	h->q=q;
	strcpy(h->nome,nome);
	return *h;	
}

int check(Hack a, Hack b){
	if(a.data>b.data){
		return 1;
	} else if(a.data<b.data){
			return -1;	
	} else {
		if(a.q>b.q){
			return 1;
		} else if(a.q<b.q){
			return -1;
		} else {
			return 0;
		}
	}
}
void interscale(Hack* arr,int left,int middle,int right){
	int n1=middle-left+1;
	int n2=right-middle;
	Hack* aux1=malloc(n1*sizeof(Hack));
	Hack* aux2=malloc(n2*sizeof(Hack));
	int k=left;
	for(int i=0;i<n1;i++){
		aux1[i]=arr[k++];
	}
	for(int i=0;i<n2;i++){
		aux2[i]=arr[k++];
	}
	k=left;
	int i=0;
	int j=0;
	while(i<n1 && j<n2){
		if(check(aux1[i],aux2[j])>=0){
			arr[k++]=aux1[i++];
		} else {
			arr[k++]=aux2[j++];
		}
	}
	while(i<n1){
		arr[k++]=aux1[i++];
	}
	while(j<n2){
		arr[k++]=aux2[j++];
	}
	free(aux1);
	free(aux2);
}

void mergesort(Hack* arr,int left,int right){
	//shouldve used if instead of while 
	while(left<right){
		int middle=(right+left)/2;
		mergesort(arr,left,middle);
		mergesort(arr,middle+1,right);
		interscale(arr,left,middle,right);
	}
}
int main(){
	int data;
	int q;	
	char nome[51];
	Hack* arr=malloc(1000*sizeof(Hack));
	int i=0;
	while(scanf("%d %d",&data,&q)==2 && readline(nome,51)==1){
		Hack h=newHack(data,q,nome);
		arr[i++]=h;		
	}
	mergesort(arr,0,i);
	for(int j=0;j<i;j++){
		printf("%d %d %s\n",arr[j].data,arr[j].q,arr[j].nome);
	}
}
