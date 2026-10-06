#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int getSize(char* str){
	int cont=0;
	while(*str!='\0'){
		cont++;
		str++;
	}
	return cont;
}
void readline(char* str,int size){
	if(fgets(str,size,stdin)!=NULL){
		if(str[getSize(str)-1]=='\n'){
			str[getSize(str)-1]='\0';
		}
	}
}
typedef struct Erro{
	int linha;
	int coluna;
	char msg[51];
}Erro;
Erro* newErro(int l,int c,char* str){ 
	Erro* erro=malloc(sizeof(Erro));	
	erro->linha=l;
	erro->coluna=c;
	strcpy(erro->msg,str);
	return erro;
}
void printErro(Erro* e){
	printf("%d %d %s\n",e->linha,e->coluna,e->msg);

}
typedef struct Celula{
	Erro* erro;
	struct Celula* prox;
}Celula;
Celula* newCelula(Erro* e){
	Celula* c=malloc(sizeof(Celula));
	c->erro=e;
	c->prox=NULL;
	return c;
}
typedef struct Fila{
	Celula* p;
	Celula* u;
	int q;
}Fila;
Fila* newFila(){
	char c[5]="lixo";
	Erro* erro=newErro(-1,-1,c);
	Celula* cel=newCelula(erro);
	Fila* fila=malloc(sizeof(Fila));
	fila->p=cel;
	fila->u=cel;
	fila->q=0;
	return fila;
}
void enqueue(Fila* f,Erro*  e){
	Celula* c=newCelula(e);
	f->u->prox=c;
	f->u=c;
	f->q++;	
}
void sort(Fila* f){
	for(int i=0;i<(f->q)-1;i++){
			Celula* nav=f->p;
			nav=nav->prox;
			Celula* resp=nav;
			Celula* nav2=nav->prox;
			while(nav2!=NULL){
				if(nav2->erro->linha<resp->erro->linha){
					resp=nav2;
				}
				else if(nav2->erro->linha==resp->erro->linha){
					if(nav2->erro->coluna<resp->erro->coluna){
						resp=nav2;
					}
				}
				nav2=nav2->prox;
			}
			Erro* tmp=nav->erro;
			nav->erro=nav2->erro;
			nav2->erro=tmp;
	}
}
void printFila(Fila* f){
	Celula* nav=f->p->prox;
	while(nav!=NULL){
		printErro(nav->erro);
		nav=nav->prox;
	}
}
int main(){
	Fila* f=newFila(); 
	int l; 
	while(scanf("%d",&l)!=EOF){ 
		int c; 
		scanf("%d",&c); 
		getchar();
		char str[51];
		readline(str,51);
		Erro* e=newErro(l,c,str);
		enqueue(f,e);	
	}
	sort(f);
	printFila(f);
}


