#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int size(char* str){
	int c=0;
	while(*str!='\0'){
		c++;
		str++;
	}
	return c;
}
void readline(char* str,int tam){
	fgets(str,tam,stdin);
	if(str[size(str)-1]=='\n'){
		str[size(str)-1]='\0';
	}
}
int check(char* key, char* str){
	if(strcmp(key,str)<0){
		return 1;
	}	
	else if(strcmp(key,str)==0){
		return 0;
	}
	else{
		return 0;
	}
}
void sort(char** array,int n){
	for(int i=1;i<n;i++){
		char* key=array[i];
		int j=i-1;
		while(j>=0 && check(key,array[j])){
			array[j+1]=array[j];
			j--;	
		}
		array[j+1]=key;
	}	
}
int main(){
	int n;
	scanf("%d",&n);
	char** array=malloc(n*sizeof(char*));
	int mais=0,menos=0;
	for(int i=0;i<n;i++){
		char str[23];
		readline(str,23);
		if(str[0]=='+'){
			mais++;
		}
		else if(str[0]=='-'){
			menos++;
		}
		array[i]=str;
	}
	sort(array,n);
	for(int i=0;i<n;i++){
		printf("%s\n",array[i]);
	}
}
