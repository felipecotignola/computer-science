	import java.util.Scanner;
	public class sumOfDigits{
		public static int recursao(int n){
			if(n<10){
				return n;
			}
			int soma=n%10;
			//soma= ao ultimo digito atual
			soma+=recursao(n/10);
			//eu passo por recursao o numero original sobre 10 pra remover o caractere que eu acabei de atribuir a variavel soma
			//soma eh igual ao retorno da soma dos proximos ultimos digitos finais
			return soma;
		}
		public static void main(String[] args){
			Scanner sc=new Scanner(System.in);
			int n=sc.nextInt();
			while(sc.hasNext()){
				System.out.printf("%d\n",recursao(n));
				n=sc.nextInt();
			}
		}
	}
