	#include<stdio.h>
	int somaDigitos(int n){
		int soma=0;
		//inicializo a soma com 0
		while(n>10){
			soma+=n%10;
			//somo o ultimo digito atual ate n ser menor que 10
			n/=10;	
			//removo o digito somado dividindo por 10
		}
		//dps do while necessariamente n eh menor que 10 ent ele eh o ultimo digito entao eu somo a soma e retorno a soma
		soma+=n;
		return soma;	
	}
	int main(){
		int n;
		while(scanf("%d",&n)!=EOF){
			printf("%d\n",somaDigitos(n));
		}
	}
