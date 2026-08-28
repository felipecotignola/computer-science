	#include<stdio.h>
	int recursao(int n){
		if(n<10){
			return n;
		}
		//eu pego o ultimo digito atual e somo a soma final
		int soma=n%10;
		//
		soma+=recursao(n/10);
		//eu divido por 10 e removo o digito q ja atribui a minha soma e na proxima recursao eu mando o numero com um digito a menos e dps vai ir retornando a soma de cada digito quando chegar no caso base
		return soma;
	}
	int main(){
		int n;
		scanf("%d",&n);
		printf("%d",recursao(n));
	}
