	import java.util.Scanner;
	public class recursiveStringInversion{
		//metodo recursivo que recebe a string original e o indice de cada posicao dela(eu comeco passando o indice da ultima posicao e vou dando -- ate ser igual a 0 e retornar o caractere na posicao 0
		//e eu vou construindo uma nova string a partir do inverso da original
		static String recursion(String str,int index){
			if(index==0){
				return  ""+str.charAt(index);
			}
			String string="";
			string=str.charAt(index)+recursion(str,index-1);
			return string;
		}
		public static void main(String[] args){
			Scanner sc=new Scanner(System.in);
			String string=sc.nextLine();
			while(!(string.length()==3 && string.charAt(0)=='F' && string.charAt(1)=='I' && string.charAt(2)=='M')){
				System.out.printf("%s\n",recursion(string,(string.length())-1)); 	
				string=sc.nextLine();
			}
		}
	}
